/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                             C G A _ S C R E E N                           *
 *                                                                           *
 *---------------------------------------------------------------------------*/
 
#include "machine/cgascr.h"
#include "machine/io_port.h"

const int spalte = 80;           // Spalten 0 <= x <= 79 */
const int zeile = 25;            // Zeilene 0 <= y <= 24 */
char* const grakaoffset = (char*) 0xb8000;  // Initialisieren graka Ram Startadresse
const IO_Port indexreg = 0x3d4;   /* Initialisieren des Indexregisters Port 3d4
                                 *  (nur schreiben) */
const IO_Port datareg = 0x3d5;	/* initialisieren des Datenregisters Port 3d5
                                 * lesen und schreiben */

/* ToDo: insert sourcecode */ 


void CGA_Screen::show (int x, int y, char c, unsigned char attrib){
    int verschiebung = (y * spalte + x) * 2;    // * 2 damit immer im geraden Bit geschrieben wird
    grakaoffset [verschiebung] = c;             // c in Adresse schreiben
    grakaoffset [verschiebung + 1] = attrib;    // attrib in ungerade Adresse schreiben
}


void CGA_Screen::setpos (int x, int y){

	int cursorpos = y * spalte + x;			// Berechnung des Offsets
	
    indexreg.outb(14);					// IndexRegister auf Port 14 setzen
	int puffer_1 = cursorpos >> 8;
	datareg.outb(puffer_1);				// ersten Teil schreiben

	indexreg.outb(15);					//IndexRegister auf Port 15 setzen
	int puffer_2 = (cursorpos);	//Inhalten nach rechts shiften um auf den 2. teil zuzugreifen
	datareg.outb(puffer_2);				// zweiten Teil schreiben

}



void CGA_Screen::getpos (int &x, int &y){
    int cursorpos;                      // cursorpos variable

    indexreg.outb(14);                  // IndexRegister auf Port 14 setzen
    cursorpos = datareg.inb();           // einlesen des Inhalts vom Datenregister
    cursorpos = (cursorpos << 8);       // linksshift, damit auf niederes Byte zugegriffen werden kann
    indexreg.outb(15);
    cursorpos = cursorpos | datareg.inb();  // einlesen und verknuepfen (Addition) der beiden Inhalte

    x = cursorpos % spalte;             // Berechnung des Restes um x-Pos anzugeben (Spalte)
    y = cursorpos / spalte;             // bestimmen der Zeile
} 

void CGA_Screen::print (char* text, int length, unsigned char attrib){
        // prüfen ob innerhalb der Grenzen
        // getpos
        // zeichen schreiben
        // setpos (getpos+1)
	int x, y;
	getpos(x,y);
	int maxspalte = spalte -1;
	if ( y < 0 )
		y = 0;
	if ( x < 0 )
		x = 0;
		
    for ( int i = 0; i < length; i++ ){
		if ( x >= maxspalte || text[i] == '\n' ) {   
		// wenn Zeichen rechts außerhalb d. Bildschirms liegt oder Zeilenumbruch
		// Achtung!!! lauf Marcus: \n ist als Steuerzeichen hinterlegt (char == 10 oder char =='\n')
			x=0;  			// Zeilenanfang
			y++;			// Zeilenumbruch
		} 
		if ( x >= 0 && x < spalte && y >= 0 && y < zeile ){
					show (x, y, text[i], attrib);	// Zeichen an Pos schreiben
					x++;			// ein zeichen weiter rücken
					setpos(x,y);	// neue Position setzen
			}else {						// falls y > Zeilen Sonderzeichen ausgeben
				show(79, 0, '$', 15);		
			}
		 
	}
}

/* Idee zum Scrollup:  	scrollup() verschiebt das ganze standardmäßig eine Zeile nach oben;
 * 						die überlagerte Fkt. scrollup(anzahl) führ das ganze 
 * 						durch eine Schleife für 'anzahl' Zeilen aus;
void CGA_Screen::scrollup(){
}
void CGA_Screen::scrollup(int anzahl){	
	for (int i = 0; i <= anzahl; i++){
	scrollup();
	}	
}
*/
