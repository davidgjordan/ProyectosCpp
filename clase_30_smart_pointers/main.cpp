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
#include <memory> //contiene punteros inteligentes hay tres

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

struct X{
    int  n;
    void print(){
        std::cout << n << '\n';
    }
    X(int n):n{n}{}

    ~X(){
        std::cout << "bye X" << '\n';
        
    }
};

struct Point{
    int x,y;
    Point(int x, int y):x{x},y{y}{
        std::cout << "pointer" << '\n';
        //throw 1;
    }
    ~Point(){
        std::cout << "bye pointer" << '\n';
    }
};

struct Line{
    unique_ptr<Point>p1;//con esto nos olvidamos acer deletes de los punteros
    unique_ptr<Point>p2;//con esto nos olvidamos acer deletes de los punteros
    Line(Point *p1, Point *p2):p1{p1},p2{p2}{
        throw 8;
    }
    ~Line(){
        //delete p1;
        //delete p2;
    }
};

int main(){


        //A a{new int{1}}; //se llamara a sus destructores pero si hiciera esto
        //A * pa = new A{new int{8}};//yo tengo q destruir a mano mi objeto
        //mejor smart points

    /* Ptr<A> p{new A{new int{10}}};//prt es uhn puntero a A declarado en el heap 
                                //el PTR se encarga de acer delete

    p->show();
    (*p).show();//accedo a su valor y se vuelve un objeto

 */
    //TTRES PUTNEROS INTELIGENTE //SU POLITICA ES PARECIDA A LA Q IMPLEMENTAMOS
    unique_ptr<X> p{new X{6}};//abia antes auto_ptr esta deprecado
    p->print();
    //es lo mismo q el de arrva solo cambia la sintaxis
    auto q = make_unique<X>(20);
    q->print();

    //esta borrado q le tenemos q mover la implementacion
    {
        //le estoy robando la implementacion q
        auto r = move(q);
    }
    std::cout << "mort" << '\n';

    std::cout << "****************" << '\n';
    try{

        Line line{new Point(2,4), new Point(5, 8)};
    
    }
        catch(...){
            std::cout << "error" << '\n';
        }
    

    return 0;
}