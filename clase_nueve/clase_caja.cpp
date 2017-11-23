#include <iostream>
#include <cstring>
#include <string>

 using namespace std;

struct caja{

    int x;

public:

    ~caja(){
        
                cout<<"bye caja"<<endl;
            }
};

class cajon{
    caja *c1;
    caja *c2;
    string *s;


public:
    cajon(){

        // ubuira sido mejor acer caja c{20}; para q se guarde en el stack
        // porq asi guardamos en el heap 
        c1 = new caja{10};
        c2 = new caja{20};
        s = new string{"hello0 world"};
        cout<<"hi cajon"<<endl;
        
    }
    ~cajon(){

        delete c1; delete c2;delete s;
        cout<<"bye cajon"<<endl;
    }

    // constructor copy
    cajon( const cajon & p){
        // cosntruimos un nuevo string porq era el q daba problemas
        s = new string{*(p.s)};
        c1 = new caja{*(p.c1)};

        
        c2 = new caja{*(p.c2)};

        cout<<"copia"<<endl;
        
    }

};

 int main(){
    //  podria crear sin new

cajon *c =  new cajon();



// cajor d es una copia de c  el cosntructor busca un costructor copia como no hay copia los bites del objeto
cajon d = *c;




// asi borramos el cajon pero no las cajitas del constructor

delete c;

    return 0;
 }