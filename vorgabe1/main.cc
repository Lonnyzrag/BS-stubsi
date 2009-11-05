#include "machine/cgascr.h"
#include "machine/io_port.h"

 CGA_Screen keyoutput;
 
int main() {
   keyoutput.show(5,0, (char)65, (unsigned char) 15);
  
   
  return 0;
}
