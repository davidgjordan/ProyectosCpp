#include <iostream>


using namespace std;

/* MEJOR USAR REFERENCIAS A PUNTEROS
REFERECNIAS DEBEN REFERIRSE A ALGUIEN AL INICIALIZARSE
LA RELACION ENTRE VARIABLES Y SU REFERENCIA ES INMUTABLE
*/

void intercambiar(int &a, int &b);
int& hello();

int main(){
		
	/*int a = 8;
	int b = 5;
	intercambiar(a, b);*/

	/*int z = 125; 
	int &rz = z;
	int q = 140;
	rz = q;
	q++;

	//cout << a << "\n";
	cout << rz << "\n";*/





	int &r = hello();
	cout << r << "\n";*/
	
	return 0;


}

void intercambiar(int &x , int &y){
	int aux = x;
	x = y;
	y= aux;
}


int& hello(){
	int x = 8;
	return x;
}

/*


por cada funcion hay una entrada en el callstack
*/