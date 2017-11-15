
#include <iostream>
#include <sstream>
#include "Operations.h"
#include "../entrada/Entrada.h"
#include "resta/Resta.h"
#include "suma/Suma.h"
#include "multiplicacion/Multiplicacion.h"
#include "division/Division.h"
#include <string>



using namespace std;




Operations::Operations(){}

ostringstream Operations::getHeaderInclude(){
	ostringstream res;
	res << 	"#include <iostream>#include <sstring> using namespace std;";

	return res;
}


ostringstream Operations::getMain(){

	ostringstream res;
	res << 	"int main(int argc, char const *argv[]){ /*Menu de opciones*/";

	return res;

}

ostringstream Operations::getMenu(Entrada entrada[], int numIteraciones){
	ostringstream res;
	res<< "cout<< \"Bienvenido a la calculadora!\"<<endl;";
	res<<"do{";
res<<      "cout<<\"Elija una opcion: \"<<endl;";
			char c[numIteraciones];
			for (int i = 0; i < numIteraciones; ++i){
res<<			"count<<"<<i+1<<"<<entrada[i].getOperation()<<entrada[i].getNumOperandos()<<";";
//					1 sumar2
//  				2 restar3
				c[i] = entrada[i].getCharOperation();
			}
res<< 			"string opcion;";
res<<			"cin.getline(opcion);";			
res<< 			"opcion();";
					
			

res<<	"}while(opcion!="<<numIteraciones<<");";
return res;
}


ostringstream Operations::getCalculator(Entrada entrada[], int numIteraciones){
	cout<<"********************************** Calculator"<<endl;
	ostringstream res;
	Operations op;
	//anadimos lo includes
	res << op.getHeaderInclude().str();

			Suma suma;
			Resta resta;
			Multiplicacion multi;
			Division divi;
	for (int i = 0; i < numIteraciones; ++i){
		switch(entrada[i].getCharOperation()){
			case 's':
			res<< suma.getHeaderPrototipe(entrada[i].getNumOperandos()).str();
			break;
			case 'r':
			res<< resta.getHeaderPrototipe(entrada[i].getNumOperandos()).str();
			break;
			case 'm':
			res<< multi.getHeaderPrototipe(entrada[i].getNumOperandos()).str();
			break;
			case 'd':
			res<< divi.getHeaderPrototipe(entrada[i].getNumOperandos()).str();
			break;
			default:
			res<<"Default";
			break;
		}
	}

	res<< op.getMain().str();

	res<< op.getMenu( entrada, numIteraciones).str();
	res<<"}";



	//Cargamos los metodos
	for(int i = 0; i<numIteraciones ; i++){

		switch(entrada[i].getCharOperation()){
			case 's':
				res<< suma.getFuncionSuma(entrada[i].getNumOperandos()).str();
				break;
			case 'r':
				res<< resta.getFuncionResta(entrada[i].getNumOperandos()).str();
				break;
			case 'm':
				res<< multi.getFuncionMultiplicacion(entrada[i].getNumOperandos()).str();
				break;
			case 'd':
				res<< divi.getFuncionDivision(entrada[i].getNumOperandos()).str();
				break;
			default:
				res<<"Default";
				break;
		}


	}


	
	return  res;
}







