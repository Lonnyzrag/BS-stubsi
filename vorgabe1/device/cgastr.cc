/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                         C G A _ S T R E A M                               *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "device/cgastr.h"

  /**
   * Mit dieser Methode sollen die gesammelten Zeichen verarbeitet
   * und so Platz für neue Zeichen geschaffen werden.
   * Die Implementierung der Methode soll jedoch erst in den
   * abgeleiteten Klassen erfolgen.
   */
    
void CGA_Stream::flush ()
{
	print(buffer, buffersize, 0x05);
	aktpos=0;
}
