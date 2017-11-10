#include <iostream>


using namespace std;


/*void p(){
bool x = 45 ;
	cout << x <<"\n" ;
}

void q(){
int x ;
	cout << x <<"\n" ;
}*/

int main(){

		//cout << "Hello world\n" ;
		//p();
		//q();
		//bool p = 'A';
		//cout << p ;

		/*int s = 45
		int m = !!s;
		cout << m <<"\n";
*/


		//char // es entereo de un byte

	//signed es un entero con signo desde [-128 ; 128[  ocupa 8 bytes
	//unsigned es un entero con signo desde [0 ; 256[  ocupa 8 bytes

	/*signed	char s = 12;
		char b = s + 37;
		char p =1 -42;
		cout << b <<endl;; //imprime codigo aski
		cout << (int)p ; //imprime codigo aski
*/
	/*char s1 = -1;
	unsigned char s2= s1;
	cout<< ( int)s1;*/

	/*char s = 'H';
	cout << s <<"\n";*/



//ocupa 4 bytes   L es un caracter largo
/*	wchar_t t = L't';
	wcout << t << L"\n";  */



	//short mide medio int  en windpws el short mide  16 bits o 2 bytes

	//lo q estoy escribiendo es signed short int s = 1234;
	 //short s = 1234;
	 //cout << s << "\n";

	//----------------------------------------------------
	 //INVESTIGAR SOBRE EL SIGNED O UNSIGNED


	//TIPO BASICO INT REPRESENTA UN ENTERO Q MEDIA EL NUMERO DE BITS USADOS POR EL PROICESADOR
	//SI LA PC ERA DE32 BITS EL INT MEDIA 32 BITS  
	//PERO EN EL SALTO DE 32 BITS A 64 BITS EL INT SE QUEDO EN 32 BITS


	//--LOGN ERA ELL DOBLE DEL INT 
	//EL LONG EN WINDOWS EL LOGN MIDE 32 BITS
	//EN UNIX ES DE 64 BITS

	//EN WINDOWS INVENTARON EL LOGN LONG  PRA REPRESENTAR 64 BITS
	//EN UNIX SIGUE 64 BITS


	//APODOS A NUESTROS TIPOS DE DATOS
	//USING _US_ = USIGNED SHOR;

		using _us_ = unsigned short;
		_us_  y = 64 ;
		cout << y ;

		//define short long
		//typedef usigned shor _use_;  // mejor usar using




	//ya hay uno explicito q se llama size_t = usuigned long
	//devuelde el tamaño positivo de una lista  o de lo q queramos



	///FLOAT O DOUBLE 
	//FLOAT MIDE 32 BITS    7 DIGITOS SIGNIFICATIVOS 3.1234567
	//DOUBLE 64 BITS        13 DIGITOS SIGNIFIVATIBOS 3.12345678910
	//LONG DOUBLE 80 BITS   




	return 0;
}