#include <iostream>

using namespace std;

void interarChars(const char *m);

void copiar(const char *s1, char  *s2);

int main(int argc, char const *argv[])
{
	
	/*x va tener esos 6 elementos en el stack el compilador reserva espacio para estos 6 enteros
	x representa la direccion de memoria del primer elemento del array
	*/
	//si se declara asi el array vive en el stack sise acaba este metodo se muere el array
		int x[] = {12,8,5,4,7,6};
		/*ayq pasarle el tama*/
		//cout<<x<<endl;
		//cout<<&x<<endl;
		int * px = x;
		//cout<<px<<endl;

		/*  * acdede al valor del elemento  */
		//cout<<*px<<endl;
		//cout<<*x<<endl;

		//cout<<x[0]<<endl;
		//cout<<x[1]<<endl;
		//cout<<px[1]<<endl;

		/*ARITMETICA DE PUNTEROS CONSISTE EN SUMAR Y RESTAR NUMEROS A UNA DIRECCION DE MEMORIA*/
		
		//este numero se suma un entero a la direccion de memoria
		//cout<<(px+1)<<endl;
		
		//accedemos al valor con el *
		//cout<<*(px+1)<<endl;

		//es como si hicieramos *(1+px)
		cout<<1[px]<<endl;
		//operador de c++ al q le pasamos una variable y me devuelve el numero de bites q ese tipo de ddatoo usa
		//cout<<sizeof(x)<<endl;//24
		//cout<<sizeof(px)<<endl;//8 segun el sistema operativo y sus bits
		cout<<"****************"<<endl;//8 segun el sistema operativo y sus bits

		/*ITERANDO UN ARRAY*/
		/*for (int i = 0; i < 100; ++i){
			cout<<x[i]<<endl;
		}*/
		cout<<"****************"<<endl;//8 segun el sistema operativo y sus bits



		/*RRANGE BASED FOR en versoin 11*/
		//por cada entero en el vector x
		/*for (auto e: x){
			cout<<e<<endl;
		}*/

		cout<<"****************"<<endl;//8 segun el sistema operativo y sus bits
		//el tamano 10 tiene q ser numerico y conocido en tiempo de compilacion al menos
		//q le pasemos una constante con constexpri
		//int y[10];

		//cout<<"****************"<<endl;//8 segun el sistema operativo y sus bits

		//char p[] = {'h','o','l','a',0 };
		//cout<<p<<endl;


		/*con comillas aumentan un 0*/
		//const char * m = "hola mundo";
		//cout<<m<<endl;
		//estamos haciendo *(m+2)
		//cout<<m<<endl;

		//char p[] = {'h','o','l','a',0 };
		 

		//interarChars(m);


		//const char *x ;

		/*puntero constante*/
		//const char *x const p;



		/*cunado el compilador ve una cadena es const char * c*/
		//consta char * s1 es
		auto s1 = "thursday";
		char s2 [10];

		copiar(s1, s2);
		cout<<s2<<endl;






	return 0;
}


//para cadenas le paso el puntero hasta q encuentre un cero
void interarChars(const char *m){
		cout<<"****************"<<endl;//8 segun el sistema operativo y sus bits
	int i =0;
	while(m[i] != 0){
		cout<<m[i]<<endl;
		i++;
	}
}


void copiar(const char *s1, char *s2){
	int c =0;
	while(s1[c] != 0){
		s2[c] = s1[c];
		c++;
	}

}