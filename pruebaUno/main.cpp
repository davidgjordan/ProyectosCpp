#include <iostream>

using namespace std;



int main(){
	
	/* int x = 4;
	int *px = &x;

	cout << "Valor de x: " << x << endl;
	cout << "Valor de x: " <<*px << endl;




	int x = 4;
	int *px = &x;
	int **ppx = &px // es un puntero de puntero por lo que solo puede guardar direcciones de punteros de tipo int
//  */
// 	int x = 4;
// 	int *px = &x;
// 	cout << "Valor de x: " << x << endl;
// 	cout << "Valor de x: " <<*px << endl;
// 	 Esto mostrará el siguiente resultado:
	
	// Valor de x: 4
	// Valor de x: 4
	// Como vemos anteponer * a una variable puntero nos devuelve el contenido de la dirección que contiene. Lo mismo sucede con los punteros de punteros:
	
	int x = 4;
	int *px = &x;
	int **ppx = &px;
	cout << "Valor de x: " << x << endl;
	cout << "Valor de x: " << *px << endl;
	cout << "Valor de x: " << **ppx << endl;
 


	
	return 0;


}