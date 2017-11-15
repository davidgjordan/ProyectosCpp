#ifndef _ENTRADA_
#define _ENTRADA_

#include <iostream>
#include <sstream>

#include <string>
using namespace std;



class Entrada{
private:
	string operation;
	int numOperandos;
public:
	Entrada();
	string getOperation();
	int getNumOperandos();
	void setOperation(string operation);
	void setNumOperandos(int numOperandos);
	void llenarEntrada(Entrada entrada[], int numIteraciones);
	char getCharOperation();
};


#endif