//TEMPLATE ESPECIALIZACION

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template <typename T >
void p(const T &x){
    std::cout << x << '\n';
}
template <>//aqui encaja con el string   simpre las espezialisaciones depues de la implementacion orignal osea la de arriba
void p<string>(const string &x){
    std::cout<<"****string**** " << x << '\n';
}
template <>//aqui encaja con el string   simpre las espezialisaciones depues de la implementacion orignal osea la de arriba
void p<double>(const double &x){
    std::cout<<"****double**** " << x << '\n';
}
template <int N>//aqui encaja con el string   simpre las espezialisaciones depues de la implementacion orignal osea la de arriba
void print(char x){
    std::cout<<"*"<< '\n';
    print<N-1>(x);
}
template <>
void print<0>(char x){
    std::cout<< '\n';
}

//TOTAL TODOS LOS PARAMETROS ESPECIALIZADOS LO PARAMETRIZAMOS COMO EL STRING Y EL DOUBLE(EN LAS FUNCIONES SOLO ESPECIALI TOTAL(OSEA ESPECIALIZAR TODOS))

//EL OTRO ES ESPECIALIZACOIN PARCIAL con las clases si se puede hacer el parcial
template <typename T>
struct CP{
    T a,b;
    void  show(){
        std::cout << a<<"--"<<b << '\n';
    }
};

struct Q{
    int q;
};
template <>
struct CP<Q>{
    Q x,y;
    void  print()const{
        std::cout << x.q<<"-desde el Q-"<<y.q << '\n';
    }
};



//ESPECIALIDAD PARA PUNTEROS
template <typename T>
struct CP<T*>{  //t sera int * en el caso de abajo
    T *a,*b;
    void  show(){
        std::cout << *a<<"--"<<*b << '\n';
    }
    ~CP(){
        delete a;
        delete b;
    }
};



//PARCIAL

template <typename A,typename B>
struct X{
    A a;B b;
    void  p()const{
        std::cout << a<<"--"<<b << '\n';
    }
};

template <typename Q>//especializazion parcial solo uno
struct X<int, Q>{
    int a;Q b;
    void  s()const{
        for (size_t i = 0; i < a; i++)
        {
            
            std::cout <<b<< '\n';
        }
    }
};

//TOTAL
template <>//
struct X<int, int>{
    int a;int b;
    void  s()const{          
            std::cout <<a+b<< '\n';
    }
};

/* template <typename T> //PUEDE CONTENER OTROS TEMPLATES
struct Pepito<int, int>{
    int a;int b;
    void  s()const{          
            std::cout <<a+b<< '\n';
    }
}; */

template<typename T>
struct A{
    T a;
    void print() const{
        std::cout<<a << "copy" << '\n';
    }
};
template<typename T, class U>
struct B: A<T>{
    U b;
    B(const T & a, const U & b):A<T>{a}, b{b}{

    }
    void show() const{//como ya hererda tengo q poner constructor
        A<T>::print();
        std::cout << b << '\n';
    }
};



 int main(){
    p<int>(10);//10 tiene q ser constante
    p<double>(10.5);
    p<string>("hello");

    print<5>('x');


    CP<int>cp{2,5};
    CP<string>s{"hello", "worl"};
    cp.show();
    s.show();



    CP<Q> q{12,18};
    q.print();

    CP<int *> r{new int{10}, new int{20}};
    r.show();


    X<string, string> x {"hola","mundo2"};
    x.p();

    X<int, string> y {13,"mundo2"};
    y.s();


    X<int, int> g{13,17};
    g.s();



    B<int, string>xb{10, "hello"};
    xb.show();


    return 0;

 }