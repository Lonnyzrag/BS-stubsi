#include "machine/cgascr.h"
#include "machine/io_port.h"

 CGA_Screen keyoutput;
 
int main() {
	int a,b = 13;
	int scrollcounter=2;
	
    keyoutput.show(5,0, (char)65, (unsigned char) 15);
	
	//for (int i; i <= 25; i++){
		keyoutput.setpos(a,b);
		keyoutput.print ("Eike, eIke, eiKe, eikE", 22,  15);
		//a++;
		//b=b+3;
	//}
	//keyoutput.print (char* 'Dies ist ein Text!',(int) 18, (unsigned char) 15){
   
   //Scrolltest:
   //keyoutput.scrollup(scrollcounter);
   
  return 0;
}
