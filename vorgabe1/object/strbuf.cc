/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                       S T R I N G B U F F E R                             *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "object/strbuf.h"

void Stringbuffer :: put (char c){
    /* Diese Methode fügt das Zeichen c an das Ende der bereits gesammelten Zeichen an. 
	 * ist die Pufferkapazität des Stringbuffer Objektes erschöpft, müssen die 
	 * gesammelten Zeichen durch Aufruf der Methode flush () verarbeitet werden. */
	
    if (aktpos >= buffersize){	// Überprüfung ob Puffergröße überschritten
        this -> flush();		// mittels flush die Zeichen verarbeiten
        aktpos = 0;				// nach Verarbeitung wird der Index zurückgesetzt
    }
    buffer[aktpos] = c;			// c an den Puffer anhängen
    aktpos++;					// index für das nächste Zeichen erhöhen
}


    /* Verarbeitet die gesammelten Zeichen und schafft so Platz für neue Zeichen.
	 * Die Implementierung der Methode soll jedoch erst in den abgeleiteten Klassen erfolgen. */
