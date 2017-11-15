#include <iostream>
#include <string>
#include "Entrada.h"
using namespace std;



Entrada::Entrada(){
}

string Entrada::getOperation(){
	return operation;
}
int Entrada::getNumOperandos(){
	return numOperandos;
}
void Entrada::setOperation(string operation){
this->operation = operation;
}
void Entrada::setNumOperandos(int numOperandos){
	this->numOperandos = numOperandos;
}

 void Entrada::llenarEntrada(Entrada entrada[], int numIteraciones){
	string operation;
	int numOperandos;
	cout << "Ingrese los parametros con el siguiente formato(despues presione entre)"<<endl;
	cout << "Nombre Operacion    Numero de Operandos"<<endl;
	
	for(int i = 0; i<numIteraciones ; i++){
		cin>>operation>>numOperandos;
		entrada[i].setOperation(operation);
		entrada[i].setNumOperandos(numOperandos);
		cin.ignore();
		cout << endl;
	}
	
	cout<<"**********************************"<<endl;
	for(int i = 0; i<numIteraciones ; i++){
		cout <<"Operacion: "<<entrada[i].getOperation()<<"---"<< "Num operandos  "<< entrada[i].getNumOperandos()<<endl;
	}
}



char Entrada::getCharOperation(){
	char res = this->operation[0];
	return res;
}