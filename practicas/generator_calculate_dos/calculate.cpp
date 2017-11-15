
#include <iostream>
#include <sstream> 
using namespace std;


float sumar2(float arrayValores[]);
float restar3(float arrayValores[]);


int main(int argc, char const *argv[]){ 
/*Menu de opciones*/
	cout<< "Bienvenido a la calculadora!"<<endl;
	do{
		cout<<"Elija una opcion: "<<endl;
		count<<1<<suma2;
		count<<2<<resta3;
		string opcion;
		cin.getline(opcion);
		opcion();
	}while(opcion!=2);
}





float sumar2(float arrayValores[]){
	float res;
	for (int i = 0; i < 2; ++i){
		res+=arrayValores[i];
	}
	return res;
}
float resta3(float arrayValores[]){
	float res;
	for (int i = 0; i < 3; ++i){
		res-=arrayValores[i];
	}
	return res;
}