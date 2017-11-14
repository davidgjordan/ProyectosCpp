#include <string> 
#include <iostream>
#include "Suma.cpp"
#include "Restar.cpp"


using namespace std;

class Operations{

private:
	char operations[4] = {'0','0','0','0'};
public:

	Operations(char operations){
		this->operations = operations;
	}

	string getFuntionsCalculator(){
		string res="";
		for (int i = 0; i < sizeof(operations)/sizeof(char); ++i){
			switch(operations[i])
			case 'S': 
				res += Suma::getFuntionSumar(); 
				break;
			case 'R':
				res+= Resta::getFuntionRestar();
				break;
			default :
				break;	
			}
		}
		return res;
	}





};