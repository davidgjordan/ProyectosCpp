#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
//herenecia multiple

using namespace std;


struct Base{//se les llama abc abstract base class
    virtual ~Base(){};//con esto digo q la jerarquia es polimorfica
    virtual bool equals(const Base&) const =0;
    virtual string toString() const =0;
};

struct  IInterface: virtual Base{
};

struct IComparable: virtual IInterface{
    virtual int compareTo(const IComparable&) const =0;    
};
struct Object : Base{
    
    bool equals(const Base& s) const override {
        return  this==&s;//comparamos los punteros
    }
    
    string toString() const override{
        char aux[32];
        sprintf(aux, "Object@%p",this);
        return aux;
    }
};


struct Integer: virtual Object,virtual IComparable{
    int n;
public:
    Integer(int n):n(n){
    }

    bool equals(const Base& s) const override {
        //auto es const Integer                 //cuando se usa virtaul en las clases no se usadynamicc cast
        auto & i = dynamic_cast<const Integer&>(s);//trasforma de s a const integer
        return n==i.n;
    }
    string toString() const override{
        return to_string(n);
    }
 int compareTo(const IComparable& s) const {
    auto & i =  dynamic_cast<const Integer&>(s);//dynamic cas si no puede castear debuelve una exepcion
        //no convierte en null como el static cast porq no es un puntero
    return n-i.n;
 }
    
    
};

int main(){


    IComparable *a = new Integer(8);
    IComparable *b = new Integer(10);//asi no ndecesito liberar memoria Integer x{10};

    cout<<a->toString()<<endl;//es uin metodo eeredado en
                            //la clase basic y tyambien esta implementado en tla otra rama y funciona por el virtual 
                                //todo en java es virtual
    cout<<a->compareTo(*b)<<endl;
    delete a;    
    delete b;    




    return 0;
}