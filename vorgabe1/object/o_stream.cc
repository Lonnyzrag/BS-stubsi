/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
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
/*    char* pos = text;       //kopiert zeiger auf den Text/String
    while (*pos){           // *pos laeuft solange wie nicht die 0-Terminierung gefunde wurde
        put(*pos);          // *pos gibt Inhalt an der position pos zurueck
        pos++;              //erhoeht zeiger
    }
*/
    int i = 0;
    while (text[i]){		// solange text != '\0'
        put(text[i]);		// schreibe Zeichen in Buffer
        i++;
    }
    return *this;
}

O_Stream& O_Stream::operator << (unsigned long number){
    unsigned long div;
    char  digit;

    if (base == 8 || base == 16)	//wenn oktal oder hexadezimal schreibe fuehrende Null
        put ('0');
    if (base == 16)					//wenn hexadezimal schreibe 'x'
        put('x');

	//ermittle hoechste Potenz der Basis die <= der Zahl ist
    //und verwende diese als Teiler
    for (div = 1; number/div >= (unsigned long) base; div *= base);

    //solange der Teiler groesser 0 ist
	for (; div > 0; div /= (unsigned long) base){
        digit = number/div;
        if (digit < 10)
            put('0'+digit);
        else
            put('a'+digit-10);
        number %= div;
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

O_Stream& O_Stream::operator << (void* pointer){
    int oldbase=base;
    base=16;
    *this << (unsigned long) pointer;
    base=oldbase;
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
    os.base=2;
    return os;
}

O_Stream& oct (O_Stream& os){
    os.base=8;
    return os;
}

O_Stream& dec (O_Stream& os){
    os.base=10;
    return os;
}

O_Stream& hex (O_Stream& os){
    os.base=16;
    return os;
}
