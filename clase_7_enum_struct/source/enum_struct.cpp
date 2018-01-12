#include <iostream>
#include <string>
#include <cstring>
#include "../include/main.h"

using namespace std;

// SOLO PUEDE TENER ESOTOS VALORES
// SCOPE con class le damos ambito a sus valores y se pueden usar en otros enums
enum class Color{
    RED = 8,
    GREEN = 25,
    BLUE = 42
    };
    
    
//EN C conjunto de campos cada campo tiene un nombre y un tipo
/* EN C++ ES UN CONJUNTO DE DATOS CON NOMBRES
CONJUNTO DE ATRIBUTOS(VARIABLES MIEMBRO)
CONJUNTO DE METODOS(FUNCIONES MIEMBRO)
*/ //LA DIFRECIA CON UNA CLASE  LAS ESTRUCTURAS TIENEN TODOS SUS PROPIEDADES PUBLICAS POR DEFECTO
struct /*class*/ Person{
    //public:
 char fullname[32];
    int edad;
    int peso;
}; 

//como voya modificar loa persona sera una referencia y no una costante
void init(Person &p ,const char * nom,int edad, int peso);
    //para lectura y no sacar copia del parametro y usar en el metodo  poner & y lectura const
void show(const Person &q);




int main(){


string x = "Martes";

cout<<x[2]<<endl;

// COMPRUEBA SI ESTA FUERA DE LA CADENA
cout<<x.at(2)<<endl;

// es un char
for(auto k : x){
    cout<<k<<endl;
}

// obtenemos un iterador y nos movemos por el
// begin es una funcion q debuelve un iterador q apunta  al principio de la cadena
// funcion end apunta  amas alla de la funcion de la cadena una mas
for(string::iterator i = x.begin(); i!= x.end();i++){
    cout<<"k: "<<*i<<endl;
    
}


// rbegin al ultimo elemento de la cade
// rend apunta primero
cout<<"*************REVERSE**************"<<endl;
//todo se remplaza con el auto   en c++ se puede declarar clases dentro de clases reverse es un a
// clase dentro de la clase string 
for(string::reverse_iterator i = x.rbegin(); i!= x.rend();i++){
    cout<<"k: "<<*i<<endl;
}

cout<<"*********ENUMS******************"<<endl;

Color c = Color::RED;
// se castea a int porq cout no sabe leer esto
cout<<(int)c<<endl;
if(c == Color::BLUE){
cout<<"Blue"<<endl;

}
cout<<(int)c<<endl;
c=(Color)1460;
cout<<(int)c<<endl;


cout<<"*********STRUCTS******************"<<endl;
Person p,q;
init(p,"Lucas",38,60);
init(q,"Eva",40,70);

show(p);
show(q);





    return 0;
}

void init(Person &p ,const char * nom,int edad, int peso){
    //la flecha accede al campo del la referencia q este objeto apunta  p-> = (*p)
    strcpy(p.fullname, nom);
    p.edad = edad;
    p.peso = peso;
}
void show(const Person &p){
    cout<<"name "<<p.fullname<<endl; 
    cout<<"edad "<<p.edad<<endl; 
    cout<<"peso "<<p.peso<<endl; 
}


// PREPARA O CREA LAS DIRECTVAS PARA LA COMP[ILACION]
// cmake -G "Unix Makefiles" ..

// COMPILA
// make

// EJECUTAR EL MAIN DENTRO DEL BIN
// ./main
