#include <iostream>
#include <sstream>
#include <string>

#include "operations/Operations.h"
#include "entrada/Entrada.h"



using namespace std;



int main(int argc, char const *argv[]){
	

	/*  LLENAMOS EL ARRAY DE ENTRADA*/
	
	int tamArrayParametros;
	cout << "Cuantas Opeaciones Desea Implementrar"<<endl;
	cin>>tamArrayParametros;
	cin.ignore();

	Entrada arrayEntrada[tamArrayParametros];
	Entrada entrada;
	entrada.llenarEntrada(arrayEntrada, tamArrayParametros);

	

	// GENERAMOS LA CALCULADORA SEGUN EL ARRAY DE PARAMETROS
	Operations operations;
	ostringstream os; 
	os = operations.getCalculator(arrayEntrada, tamArrayParametros);
	cout<<os.str();



	


	return 0;
}