#include <iostream>
#include <sstream>
#include "Resta.h"


using namespace std;


Resta::Resta(){
}
ostringstream Resta::getHeaderPrototipe(int numOperandos){
	ostringstream res;
	res<<"float restar"<<numOperandos<<"(float arrayValores[]);";
		return res;
}

ostringstream  Resta::getFuncionResta(int numOperandos){

	ostringstream res; 
	res<<"float resta"<<numOperandos<<"(float arrayValores[]){"<<"float res;"
							<<"for (int i = 0; i < "<<numOperandos<<"; ++i){"
								<<"res-=arrayValores[i];"
							<<"}"
				<<"return res;}";

		return res;
	}