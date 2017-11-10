#include <iostream>
#include <string>


using namespace std;
void divisible();
void mayorDeTres();
void imprimeCalficacion();
void ordenarDosNumeros();
void sinArgumentos(void);
void referencia(int& x){ //Parámetro por referencia{
	x += 2;
}

class Prueba{
	string name;
	int x;
public:
	Prueba(string s, int x){
		this->name = s;
	}
	void getName(){
		cout << name << endl;
	}

};

int main(){
	 //(S, A, B, N, E) 
	
	//divisible();
	//mayorDeTres();
	//imprimeCalficacion();
	//ordenarDosNumeros();
	/*int x = 1;
	cout << x << endl;
	{
		cout << x << endl;
		int x = 2;
		cout << x << endl;
		{
			cout << x << endl;
			int x = 3;
			cout << x << endl;
		}

		cout << x << endl;
	}*/
	/*int  n = 5, m = 3 ;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			cout << " *";
		cout << endl;
	}*/

	/*int x = 8;
	int *puntero = &x;

	int valor = *puntero;

	*puntero = 9;

	cout<< "*puntero "<<*puntero<<endl;
	cout<< "puntero "<<puntero<<endl;
	cout<< "x "<<x<<endl;
*/

	/*int x = 20;
	cout << " antes de la llamada " << " x= " << x << endl;
	referencia (x);
	cout << " despues de la llamada " <<" x= " << x << endl;

*/

	//Prueba p [12];

	/*Prueba *ff = new Prueba("name",16);
	ff->getName();


	Prueba fff{
		"name2",16
	};
	fff.getName();*/

	/*int num[4] ;

	cout << sizeof(num)/ sizeof(int)<<endl;*/


	//char Cadena[6] = "abcde";

	//Cadena = "abcde"; 
	//cout << Cadena << endl;

	int n [3];
	int *puntero = &n[2];
	cout <<"Valor antes "<< *puntero<<endl;

	cout <<"direccion de memoria "<< &n[2]<<endl;
	for (int i = 0; i < 3; ++i){
		n[i] = i*2;
		//cout << i <<" "<< n[i]<<endl;
	}

	for (int i = 0; i < 3; ++i){
		//n[i] = i;
		cout << i <<" "<< n[i]<<endl;
	}


	cout <<"Valor despues "<< *puntero <<endl;


	return 0;
}


void divisible(){
	int a, b;
	cout << "Ingrese los numeros seguidos de espacio"<<endl;
	cin>>a>>b;

	if(a%b == 0 || b%a == 0){
		cout << "Son Divisibles"<< endl;
	}else{
		cout << "No Son Divisibles"<< endl;
	}
}

void mayorDeTres(){
	int a[3];
	int mayor;
	cout << "Ingrese los numeros seguidos de espacio"<<endl;
	cin>>a[0]>>a[1]>>a[2];

	mayor = a[0];
	for(int i =1 ;i < 3 ; i++){

		if(a[i-1]<a[i]<9){
			mayor =a[i];
		}

	}

	cout << "El mayor es: "<<mayor<< endl;

}


void imprimeCalficacion(){
	char character;
	cout << "Ingrese el caracter (S, A, B, N, T)"<<endl;
	cin>>character;
	//(S, A, B, N, T) 
	switch(character){
		case 'S':
		cout << "Nota SobreSaliente"<<endl;
		break;
		case 'A':
		cout << "Nota Aceptable"<<endl;
		break;
		case 'B':
		cout << "Nota Buena"<<endl;
		break;
		case 'N':
		cout << "Nota Notable"<<endl;
		break;
		case 'T':
		cout << "Nota Terrorifica"<<endl;
		break;
		default:
		cout << "Error de entrada"<<endl;
		break;
	}

}

void ordenarDosNumeros(){
	int a,b;
	cout << "Ingrese los dos numeros seuidos de espacios"<<endl;
	cin>>a>>b;

	a<b ? cout<< a << " " << b : cout<< b << " " << a;
	

}



void sinArgumentos(void){

}
















