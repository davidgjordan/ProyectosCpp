#include <iostream>


using namespace std;

/* PUNTEROS SIN INICIALIZAR O APUNTANDO A MEMORIA SOLICITADA O A MEMORIA ACUMULADO O YA LIBERADA
ENTONCES ESTE PUNTERO SE LLAMA DANGKING POINTER SON PELIGROSOS
*/


void f(const char*p, char *q);


void h(int num);

int factorial(int num);



int main(){
		

	/*const char* s = "Hello world";
		//*s = 'j';
	cout<<s<<"\n";

*/


	/*cout << "hello" << "\n";
	f();*/


	auto fac = factorial(3);
	cout << fac << "\n";


	h(100000);

	return 0;


}

void f(){
	int *p = (int*) 0xCAFE;
	//cout << p << "\n";//DIRECCION DE MEMORIA
	//cout << *p << "\n";//VALOR DE LA DIRECCION DE MEMORIA  SE CUELGAPORQ ES MEMORIA INVALIDA


	int r = 2598;
	int *rl = &r;
	cout << rl << "\n";
	cout << *rl << "\n";

	*rl++;
	cout << r << "\n";
	h(1000);

}


int factorial(int num){

	if(num == 1){
		return 1;
	}else {
		return num*factorial(num-1);
	}
}


void h(int num){

	if(num==0){
		return;

	}else{
		cout<<"Hola"<<num<<endl;
		h(num-1);
	}
}