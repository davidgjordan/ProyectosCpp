#include <iostream>
#include <string> 
class Suma{
public:
	
	Suma();

	static string getFuntionSumar(){
		string res = "float suma(float numA, float numB){return numA + numB;}";
		return res;
	}	
};