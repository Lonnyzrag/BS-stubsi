#include "machine/cgascr.h"
#include "machine/io_port.h"

 CGA_Screen keyoutput;
 
int main() {
    keyoutput.show(5,0, (char)65, (unsigned char) 15);
	keyoutput.setpos(10,12);
	print ('T', 1,  15);
	//print (char* 'Dies ist ein Text!',(int) 18, (unsigned char) 15){
   
  return 0;
}
