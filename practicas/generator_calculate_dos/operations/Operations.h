#ifndef _OPERATIONS_
#define _OPERATIONS_
#include <iostream>
#include <sstream>
#include "../entrada/Entrada.h"
#include "resta/Resta.h"
#include "suma/Suma.h"


//using namespace std;

class Operations{

private :

	ostringstream getHeaderInclude();
	ostringstream getMain();
	ostringstream getMenu(Entrada entrada[], int numIteraciones);

public:


	Operations();
	ostringstream getCalculator(Entrada entrada[], int numIteraciones);
	
};



#endif