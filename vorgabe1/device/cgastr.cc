/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                         C G A _ S T R E A M                               *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "device/cgastr.h"

/* ToDo: insert sourcecode */ 
class CGA_Stream : virtual O_Stream, virtual CGA_Screen {
	void CGA_Stream::flush (){
		O_Stream.flush();
	}
}
