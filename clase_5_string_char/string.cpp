#include <iostream>
//#include <cstring>
#include <string>


using namespace std;

int main(int argc, char const *argv[])
{
	/* code */



	/*const char * s1 = "hello";
	const char * s2 = "wordl";

	char s3[15];


	strcpy(s3, s1); //o(m)
	strcat(s3, s2);//o(n+m)


	cout<<s3<<endl;


	//es srt-t
	auto len = strlen("friday");
	cout<<len<<endl;

	//strcat concatena dos cadenas


		//strstr devuelve un pountero a una cadena q 
	//se encuentra a un elemento q se encuentra en esta cadena
*/


	/*const char *p = "hoy es 17 de diciembre de 2017";
	const  char * c = strstr(p,"noviembre");

	//cuando un punter esta apuntando a 0 signiffica q no devuleve nada
	//ahhora el cero es NULL ES LOMISMO  O nullptr 




	if(c == nullptr){



		cerr<<"not found"<<endl;
	}else{
		cout<< c<<endl;

	}*/


	//strtok 
	//cosnt char *

	//se puede modificar porq esta en el stack
	//char p[] = "hoy es viernes 17";

	//se puede modificar porq esta en el stack
	/*auto s = "hoy es viernes 17";

	char p [100];
	strcpy(p,s);


	//siempre q encuentre un espacio me devuelve esa palabra
	char * c = strtok(p, " ");
	while(c != nullptr){
		cout<<c<<endl;
		//con nullptr le decimos q siga trabajando con esa cade
		c = strtok(nullptr, " ");
	}


*/


	//strcmp comparar cadenas
	/*auto s = "bolivia";
	auto a = "argentina";
	auto c = "brasil";
	cout<<strcmp(s,a)<<endl;
	cout<<strcmp(s,c)<<endl;
	cout<<strcmp(s,a)<<endl;*/
	//CERO SI SON IUGIALES
	//MAYOR A CERO SI LA PRIMERA ES MAYOR A LA SEGUNDA
	//MENOR A CERO SI LA PRIMERA ES MENOR A segunda

	/*strncmp  solo compara asta los 6 primeros caracteres*/
	//todas son de la libreria de c
	/*auto b1 = "boliviano";
	auto b2 = "boliviana";
	cout<<strncmp(b1,b2,7)<<endl;*/

	/*es una alias a un aclase de basec string  otra es wstring otra wstring*/
	//cuando se ace asi ya estamos declarando un objeto y esta guardada en el stack
	//y se destruye cuando se termina el metodo
	string s;//esto ya es una cadena vacia  INTERNAMENTE SON CONST CHAR *
	string s2 = "hello world";
	//asi estamos accediendo a su constructor de la clase
	//esta es la sugerida para usarse
	string s3 = {"Hello world 3"}; 
	string s4("hello world 4");


cout<<s<<endl;
cout<<s4<<endl;


	/* IMPLEMENTACION SSO STRING STAIN OPTIMIZATION*/
	
		/*java*/


	/**LOS SSTRING SE ALMACENAN/

	

*/








	return 0;
}