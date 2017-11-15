#include <iostream>
#include <sstream>
#include "Multiplicacion.h"

using namespace std;


Multiplicacion::Multiplicacion(){

}

ostringstream Multiplicacion::getHeaderPrototipe(int numOperandos){
	ostringstream res;
	res<<"float multiplicacion"<<numOperandos<<"(float arrayValores[]);";
	
	return res;
}

ostringstream  Multiplicacion::getFuncionMultiplicacion(int numOperandos){

	ostringstream res; 
	res<<"float multiplicacion"<<numOperandos<<"(float arrayValores[]){"<<"float res;"
							<<"for (int i = 0; i < "<<numOperandos<<"; ++i){"
								<<"res*=arrayValores[i];"
							<<"}"
				<<"return res;}";

		return res;
	}