#include "machine/cgascr.h"
#include "machine/io_port.h"

 CGA_Screen keyoutput;
 
int main() {
	int a,b = 13;
	int scrollcounter=2;
	
    keyoutput.show(5,0, (char)65, (unsigned char) 15);
	
	//keyoutput.print ("1234567890qwertz1234567890qwertz1234567890qwertz1234567890qwertz1234567890qwertz1234567890qwertz1234567890qwertz1234567890qwertz", 200,  15);
	keyoutput.print 
	("Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minimi 1234567890qwertzu", 2010 ,  15); //1977 grenze
	//for (int i; i <= 25; i++){
		//keyoutput.setpos(a,b);
		//keyoutput.print ("Eike, eIke, eiKe, eikE", 22,  15);
		//a++;
		//b=b+3;
	//}
	//keyoutput.print (char* 'Dies ist ein Text!',(int) 18, (unsigned char) 15){
   
   //Scrolltest:
  // keyoutput.scrollup();
  
  //keyoutput.setpos(79,24);
   
  return 0;
}
