//ES UNAVARIABLE DE STACK
//UTILIZA LAII SE DESTRUYE CUANDO SALE DE CONTEXTO Y DEMAS
//ES UNA VARIABLE DE STACT PERO SE VE Y SE USA COMO PUNTERO
//SMART POINTERS
//IMPLEMENTA ALGUN MECANISMO DE MANEJO DE MEMORIA DEPENDIENDO 
//DEL SMART POINTER ELEGIMOS Q MECANISMO UTILIZAR


//evitar  lo mas posible new o usar smart pointer
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;


struct A{
    int * a;
    ~A(){
        delete a;
        std::cout << "bye" << '\n';
    }
    void show(){
        std::cout << *a << '\n';
    }
};

template <typename T>
struct Ptr{
    T * p;
    ~Ptr(){
        delete p;
    }
    T* operator->(){
        return p;
    }

    T&  operator*(){
        return *p;
    }
};

int main(){


        //A a{new int{1}}; //se llamara a sus destructores pero si hiciera esto
        //A * pa = new A{new int{8}};//yo tengo q destruir a mano mi objeto
        //mejor smart points

    Ptr<A> p{new A{new int{10}}};//prt es uhn puntero a A declarado en el heap 
                                //el PTR se encarga de acer delete

    p->show();
    (*p).show();//accedo a su valor y se vuelve un objeto
    
    return 0;
}