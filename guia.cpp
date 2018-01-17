#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdio>

using namespace std;


class X{

	char *p;
	public:
		//constructor
		X(char m ): p(new char[100]){
	        for(auto i=0U; i<100;i++){
	            p[i] = m;
	        }

	    }
	    //destructor
	    ~X(){
	        delete [] p;
	    }

	 //constructor copy  X aux = a;    a es una referencia  
    X(const X & src): p (new char [100]){
        for(auto i=0U; i<100;i++){
            p[i] = src.p[i];
      
        }  
    }

    //operador igual    a = b;  ambos son objetos declarados
    X& operator=(const  X & src){
        if(&src== this){
            return *this;
        }
        this->~X();
        p = new char[100];
        for(auto i=0U; i<100;i++){
            p[i] = src.p[i];
        } 
        return *this;
    }

    //CONSTRUCTOR COPIA DE MOVIDA 
    //dicen q es un rvalue reference significa q src al 
    //salir sera modificada
    X(X&& src) :p (src.p){ //this y src apuntan al mismo hasta q 
                            //hagamos esto
        src.p = nullptr;  //LLAMAMOS A ESTE METODO ASE X aux = move(a); a ya esta decladara
    }


    //OPERADOR = DE MOVIDA
    X & operator=(X&& src){
        if(&src == this){
            return *this;
        }
        this->~X();
        p = src.p;
        src.p = nullptr;
        return *this;

    }

    //OPERADOR == 
    bool  operator==(const X& src){
        // si este puntero es igual a este otro nada
        return strcmp(p, src.p) == 0 ;/*&& strcmp(ln, src.ln) == 0 && id == p.id */
    }

};

int main(){

	const char * s1 = "hello";
	const char * s2 = "wordl";
	char s3[15];

	strcpy(s3, s1); //o(m)//Copia la cadena apuntada por s2 (incluyendo el carácter nulo) a la cadena apuntada por s1.
	strcat(s3, s2);//char *strcat(char*s1, const char *s2);//Añade una copia de la cadena apuntada por s2 (incluyendo el carácter nulo) al final de la cadena apuntada por s1. El carácter inicial de s2 sobrescribe el carácter nulo al final de s1.
					//char *strncat(char*s1, const char *s2, size_t n);
	auto len = strlen("friday");//devuelve el numero de caracteres sin contar el 0
								//para crear otra cadena con este len es len + 1
	const char *p = "hoy es 17 de diciembre de 2017";
	const  char * c = strstr(p,"noviembre");//Localiza la primera aparición en la cadena apuntada por s1 de la secuencia de caracteres (excluyendo el carácter nulo) en la cadena apuntada por s2.


//*************************************
	//siempre q encuentre un espacio me devuelve esa palabra
	char s1[52] = "Esto es un ejemplo para\n usar la funcion+ strtok()";
	 	char * c = strtok(s1, " ");
		while(c != nullptr){
			cout<<c<<endl;
			//con nullptr le decimos q siga trabajando con esa cadena
			c = strtok(nullptr, " ");
	}
//***************************************
	//strcmp comparar cadenas
	auto s = "bolivia";
	auto a = "argentina";
	auto c = "brasil";
	cout<<strcmp(s,a)<<endl;
	cout<<strcmp(s,c)<<endl;
	cout<<strcmp(s,a)<<endl;
	//CERO SI SON IUGIALES
	//MAYOR A CERO SI LA PRIMERA ES MAYOR A LA SEGUNDA
	//MENOR A CERO SI LA PRIMERA ES MENOR A segunda

	/*strncmp  solo compara asta los 6 primeros caracteres*/
	//todas son de la libreria de c
	auto b1 = "boliviano";
	auto b2 = "boliviana";
	cout<<strncmp(b1,b2,7)<<endl;
//************************************

	/*es una alias a un aclase de basec string  otra es wstring otra wstring*/
	//cuando se ace asi ya estamos declarando un objeto y esta guardada en el stack
	//y se destruye cuando se termina el metodo
	string s;//esto ya es una cadena vacia  INTERNAMENTE SON CONST CHAR *
	string s2 = "hello world";
	//asi estamos accediendo a su constructor de la clase
	//esta es la sugerida para usarse
	string s3 = {"Hello world 3"}; 
	string s4("hello world 4");
//*****************************





	return 0;
}

//*****REVERSE CADENA PRINT*****************  iterar con un for normal
char* strrev( char* s ){
  char  c;
  char* s0 = s - 1;
  char* s1 = s;
  while (*s1) ++s1;
  while (s1-- > ++s0){
    c   = *s0;
    *s0 = *s1;
    *s1 =  c;
    }
  return s;
  }
int main(){
  char message[] = "Hello world!";

  cout << "message = " << message << endl;
  cout << "egassem = " << strrev( message ) << endl;

  const char * str ;
  str = new char(50);
  str = message;
  return 0;
}






//**********************************************************************
// EL COMPILADOR DECIDE ACER MOVIDAS EN LOS SIGUIENTES CASOS
/* 
    STRUC P {
        STRING NAME;

        P get(){
            P   p {"hola"};
            return p;
        }
    }
    INT MAIN{\
        aqui ace semantica de movida
        la cadena sss vive solo entre las llaves   y name tine una copia de ssss 
        P x {"ASDAS"s}; //el puntero sasas le asignamos a x
        ********************
        aqui no porq s no esta dentro de un ambito de {} destruccio al menos q agamos
        string s = "hola"
        //P y {move(s)}; 
        P y {s};
        cout<<s<<endl;
        **********************
        aqui si gett retorna una variable q se destruy4e en ese metodo
        P x = get();
    }
*/
//*************************************************************
/* {  // cout<<"hola"<<endl;
    person p1 {"pepe", "lopez", 12};
    p1.print();

    // declaramos a p2 en el heap
    person *p2;

    {
        string s = "hermenelguildo";
        string r = "parangaricutirimicuaro";
        p2 = new person(s.c_str(), r.c_str(), 152);
        //despues de este ambito las cadenas string se destruye
    }
    p2->print();

    delete p2;
    // p2->print();

    // esto es el stack
    person p3 {"Hermenelguildo p3", "Parangaricutiri", 321};

    //copiamos es decir clonamos 
   // auto p4{p3}; es igual al siguiente
   //creamos un nuevo objeto a partir de uno existente == constructor copia
    auto p4=p3;

    person p5{"omar p5", "verde", 15};
    p5.print();

    //solo asignamos , debemos sobrecargar el operador de asignacion (operador =)
    //un objeto ya creado lo queremos copiar
    p5 = p3;
    p5.print();

    person p6 {"juab", "perez", 789};
    person p7 = p6;

    if(p6 ==p7){
        cout<<"es igual"<<endl;
    }else{
        cout<<"no es igual"<<endl;
        
    }

} */


 
