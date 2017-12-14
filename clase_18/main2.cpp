#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
//herenecia multiple

using namespace std;


struct A{
    int x;
    A(int x):x(x){}
    //aumentar constructor sin parametros y probar si da 
    virtual ~A(){}
    virtual void p()const = 0;
};

struct B:virtual A{
    B():A(6){

    }
};
struct C:virtual A{//cuando uso herencia virtual tengo q llmar explisitamente a los constructores de cada clase
    C():A(10){      
    }
};

struct D : virtual B,  virtual C{
    D():A(7){//como a no tiene constructor sin parametros tengo q llamarlo B y C tiene
    }//la solucion es tener constructores sin parametros
    void p() const override{
        cout<<"hi"<<endl;
    }
};

int main(){


    A * d = new D();
    d->p();
    cout<<d->x<<endl;

    delete d;

    return 0;
}