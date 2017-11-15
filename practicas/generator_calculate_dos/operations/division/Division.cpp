#include <iostream>
#include <sstream>
#include "Division.h"

using namespace std;


Division::Division(){

}

ostringstream Division::getHeaderPrototipe(int numOperandos){
	ostringstream res;
	res<<"float division"<<numOperandos<<"(float arrayValores[]);";
	
	return res;
}

ostringstream  Division::getFuncionDivision(int numOperandos){

	ostringstream res; 
	res<<"float division"<<numOperandos<<"(float arrayValores[]){"<<"float res;"
							<<"for (int i = 0; i < "<<numOperandos<<"; ++i){"
								<<"res/=arrayValores[i];"
							<<"}"
				<<"return res;}";

		return res;
	}