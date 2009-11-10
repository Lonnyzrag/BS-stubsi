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
char* const grakaspeicher = (char*) 0xb8000;  // Initialisieren graka Ram Startadresse
const IO_Port indexreg = 0x3d4;   /* Initialisieren des Indexregisters Port 3d4
                                 *  (nur schreiben) */
const IO_Port datareg = 0x3d5;	/* initialisieren des Datenregisters Port 3d5
                                 * lesen und schreiben */

/* ToDo: insert sourcecode */ 


void CGA_Screen::show (int x, int y, char c, unsigned char attrib){
    int verschiebung = (y * spalte + x) * 2;    // * 2 damit immer im geraden Bit geschrieben wird
    grakaspeicher [verschiebung] = c;             // c in Adresse schreiben
    grakaspeicher [verschiebung + 1] = attrib;    // attrib in ungerade Adresse schreiben
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

void CGA_Screen::print (char* text, int length, unsigned char attrib) 
{
    int x, y;

    for (int i=0; i<length; i++)	// fuer jedes Zeichen
	{
        getpos(x,y);				// Cursor-Position holen
		
        if (text[i]!='\n') {		// wenn kein Zeilenumbruch zeige Zeichen
            show(x, y, text[i], attrib); x++;
		}
        else {						// bei Zeilenumbruch Zeile+1
            x=0;
			y++;
        }

        if (x>79) {					// am Zeilenende Zeilenumbruch einfuegen
            x = 0;
			y++;
        }
        if (y>24) {					// schreiben ueber letzte Zeile hinaus
            x=0;
			y=24;
            scrollup();
        }
		
        setpos(x,y);				// Position setzen
    }

}

/* Idee zum Scrollup:  	scrollup() verschiebt das ganze standardmäßig eine Zeile nach oben;
 */

void CGA_Screen::scrollup()
{
    for(int y=0;y<25;y++)        // fuer Zeile 1-24 ersetze durch Zeichen 
                                 // in naechster Zeile
        for(int x=0;x<80;x++) {  // fuer Spalte 1-160 ersetze durch Zeichen 
                                 // in Spalte drunter
            
			grakaspeicher[(2*(y*80+x))] = grakaspeicher[(2*((y+1)*80+x))];	// verschieben des inhalts
			grakaspeicher[(2*(y*80+x))+1] = 0x0f;							// attribute leeren
		}
        
    for(int x=0;x<80;x++)        // Zeile 25 mit Leerzeichen fuellen
        show(x,24,' ',15);
		//setpos(0,24);
}

