/*  MEMORIA HEAP  varia segun el sistema operativo

para trabajar con el heap tenemos q usar dos operadores  el  new pide memoria al sistema operativo
 */


#include <iostream>

#include <string>

 using namespace std;


 int main(){
    // EL NEW CONSTRUYE EL OBJETO EN EL HEAP

    /* SI NO AY MEMORIA EN EL HEAP VOTA UNA EXEPCION BAD->ALLOC
    TAMBIEN BOTA EXEPCION SI NO HAY  MEMORIA SEGUIDA


    NEW PIDE MEMORIA Y SI HAY MEMORIA LLAMA AL CONSTRUCTOR 
    Y DEVULVE UN PUNTERO AL OBJETO
    */
    int * p = new int{8};

    cout<<p<<endl;
    cout<<*p<<endl;
    
/* EL PROGRAMA ASIGNA A UNA MEMORIA LIBRE Y DEVULVE SU DATO POR ESO IMPRIME CUALQUIER COSA */
auto q = new int;
cout<<"****q*****"<<endl;
cout<<q<<endl;
cout<<*q<<endl;
cout<<"****q*****"<<endl;

/* CUANDO EL PROGRAMA TERMINA DE CORRER EL PROGRAMA DEVUELVE LA MEMORIA PERO SI SIGUE SIGEUE OCUPANDO ESOS ESPACIOS DE MEMORIA
POR ESO HAY Q DEVOLVERLOS ASI */
delete p;
delete q;

cout<<"****delete p*****"<<endl;
cout<<p<<endl;
cout<<*p<<endl;
cout<<"****delete p*****"<<endl;

int * r = nullptr;

delete r;

// EL OTRO OPERADOR ES DELETE

/* DELETE   
VERIFICCA SI EL PUNTERO ES NULL 
        SI ES NULL NO ACE NADA  
        SI NO ES NULL LLAMA A LOS DESTRUCTORES DEL OBJETO
        Y UNA VES DESTRUIDO EL OBJETO DEVUELVE LA MEMORIA AL SISTEMA OPERATIVO
        */




    /*  EN EL STACT TIENE Q SER UNA COSTANTE EN EL HEAP NO */
    /* asi creadmos este objeto en la memoria  heap
    
    */
    int n =3;
    
    // SS ES UN STRING *
        // ESTE NEW ES OTRO SIRVE PARA CREAR UN ARRAY DE OBJETOS Y PARA BORRAR UN NEW [](NEW DE ARRAYS) se usa el delete []ss
        auto ss = new string[n];

        ss[0] = "hola";
        ss[1] = "jueves ";        
        ss[2] = "viernes";
/* COMO EL ARREGLO ES DE ESTRIGN * SE USA ESTE FOR PORQ EL DEL AUTO TIENE Q SER UN ARRAY 
    NO CON NEW SI NO UN PUNTERO   PORQ CON EL FOR DEL AUTO EL FOR TIENE Q SABER CUANTO MIDE*/
        for(int i = 0; i<3;i++){
            cout<<ss[i]<<endl;
        }
// CUANDO HAY ASTERISCO AYQ IMPLEMETAR CONSTRUCTOR COPIA PARA Q CREEN OTRAS COPIAS Y PODERASIGNAR ESAS COPIAS A LOS OBJETOS
        delete [] ss;

    return 0;
 }
