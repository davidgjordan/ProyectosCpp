#include <iostream>
#include <sstream>
#include "Suma.h"

using namespace std;


Suma::Suma(){

}

ostringstream Suma::getHeaderPrototipe(int numOperandos){
	ostringstream res;
	res<<"float sumar"<<numOperandos<<"(float arrayValores[]);";
	
	return res;
}

ostringstream  Suma::getFuncionSuma(int numOperandos){

	ostringstream res; 
	res<<"float sumar"<<numOperandos<<"(float arrayValores[]){"<<"float res;"
							<<"for (int i = 0; i < "<<numOperandos<<"; ++i){"
								<<"res+=arrayValores[i];"
							<<"}"
				<<"return res;}";

		return res;
	}