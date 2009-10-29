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
const IO_Port indexreg = 3d4;   /* Initialisieren des Indexregisters Port 3d4
                                 *  (nur schreiben) */
const IO_Port datareg = 3d5;	/* initialisieren des Datenregisters Port 3d5
                                 * lesen und schreiben */

/* ToDo: insert sourcecode */ 


void CGA_Screen::show (int x, int y, char c, unsigned char attrib){
    int verschiebung = (y * spalte + x) * 2;    // * 2 damit immer im geraden Bit geschrieben wird
    grakaoffset [verschiebung] = c;             // c in Adresse schreiben
    grakaoffset [verschiebung + 1] = attrib;    // attrib in ungerade Adresse schreiben
}
/*
void CGA_Screen::setpos (int x, int y){   
} */
/*
void CGA_Screen::getpos (int &x, int &y){
} */
/*
void CGA_Screen::print (char* text, int length, unsigned char attrib){
} */