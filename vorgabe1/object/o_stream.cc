/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            O _ S T R E A M                                *
 *                            O _ S T R E A M                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "object/o_stream.h"

/* ToDo: insert sourcecode */ 



O_Stream& O_Stream::operator << (char c){
    put(c);			//schreibe Zeichen in Puffer
    return *this;	//Referenz auf sich selber
}

O_Stream& O_Stream::operator << (unsigned char c){
    return *this << (char) c;	// Rueckfuehrung auf char
}

O_Stream& O_Stream::operator << (char* text){

    int i = 0;
    while (text[i]){		// solange true, false wenn kein zeichen, also text = '\0'
        put(text[i]);		// schreibe Zeichen in Buffer
        i++;
    }
    return *this;
}

O_Stream& O_Stream::operator << (unsigned long number){
    unsigned long div;
    char  digit;

    if (basis == 8 || basis == 16)	//wenn oktal oder hexadezimal schreibe fuehrende Null, hex: 0x....., okt 0.... laut wikipedia
        put ('0');
    if (basis == 16)					//wenn hexadezimal schreibe 'x' wegen 0x bei hex
        put('x');

	//ermittle hoechste Potenz der Basis die <= der Zahl ist
    //und verwende diese als Teiler
    for (div = 1; number/div >= (unsigned long) basis; div *= basis);

    //solange der Teiler groesser 0 ist
	for (; div > 0; div /= (unsigned long) basis){
        digit = number/div;
		
		//für HEX, denn OCT kommt da nicht rein, da zwischen 0 und 7
		//für A=10, B=11, ....
				
        if (digit < 10)
            put('0'+digit);
        else
            put('a'+digit-10);
        number = number % div;		//number %= div
    }
    return *this;
}

O_Stream& O_Stream::operator << (long number){
    if (number<0){
        put('-');
        number = -number;
    }
    return *this << (unsigned long) number;
}

O_Stream& O_Stream::operator << (unsigned int number){
    return *this << (unsigned long) number;
}

O_Stream& O_Stream::operator << (int number){
    return *this << (long) number;
}

O_Stream& O_Stream::operator << (unsigned short number){
    return *this << (unsigned long) number;
}

O_Stream& O_Stream::operator << (short number){
    return *this << (long) number;
}
												  
												 //abfangen wenn pointer
												 //0xPOINTERADRESSE weil pointeradresse in hex ausgegeben wird
O_Stream& O_Stream::operator << (void* pointer){ //gibt 0x... aus, denn long wird mit der basis 16 ausgerufen, dessen teiler kleiner als 10, damit 0x0
    int oldbasis=basis;
    basis=16;
    *this << (unsigned long) pointer;
    basis=oldbasis;
    return *this;
}

O_Stream& O_Stream::operator << (O_Stream&(*f)(O_Stream&)){
    return f(*this);
}

O_Stream& endl (O_Stream& os){
    os << '\n';
    os.flush();
    return os;
}

O_Stream& bin (O_Stream& os){
    os.basis=2;
    return os;
}

O_Stream& oct (O_Stream& os){
    os.basis=8;
    return os;
}

O_Stream& dec (O_Stream& os){
    os.basis=10;
    return os;
}

O_Stream& hex (O_Stream& os){
    os.basis=16;
    return os;
}
