#include <iostream>


using namespace std;

/* MEJOR USAR REFERENCIAS A PUNTEROS
REFERECNIAS DEBEN REFERIRSE A ALGUIEN AL INICIALIZARSE
LA RELACION ENTRE VARIABLES Y SU REFERENCIA ES INMUTABLE
*/

void intercambiar(int &a, int &b);
int& hello();
int* hello2();

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





	int *r = hello2();
	cout << *r << "\n";
	
	return 0;


}

void intercambiar(int &x , int &y){
	int aux = x;
	x = y;
	y= aux;
}


int& hello(){
	int x = 8;
	int &y = x;
	
	return y;
}
int* hello2(){
	int x = 9;
	int *y = &x;
	
	return y;

}
/*


por cada funcion hay una entrada en el callstack
*/