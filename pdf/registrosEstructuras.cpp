#include <iostream>
using namespace std;
/*struct <nombre de la estructura>
	{
	<tipo de dato miembro1> <nombre miembro1>
	<tipo de dato miembro2> <nombre miembro2>
	...
	<tipo de dato miembron> <nombre miembron>
};*/


struct libro // nombre de la estructura
{
	int anyo;
	char titulo[30];
	char autor[25];
	

	int getAnyo(){
		return this->anyo;
	}
}LIBDOS; //l4,l4,l6 son variables de tipo libro


int main(int argc, char *argv[])
{ 
 // asignación de estructuras
	LIBDOS.anyo = 14 ;
	libro lib = {12, "fs", "g23"};
	cout << lib.getAnyo()<< endl;
	cout << LIBDOS.getAnyo();

	return 0;


}


//****UNION****************************
/*union nombre
{
tipo1 miembro1;
tipo2 miembro2;
...
};*/