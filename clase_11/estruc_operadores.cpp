#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct S{

        char * p;
        S():p{new char[123465]}{

        }
        ~S(){
            // cout<<"DELETE"<<endl;
            
            delete []p;
        }

        // consttuctor copia
        S(const S& x):p{new char[123465]}{
            // cout<<"copy"<<endl;
        }


        S & operator=(const S& x){
            //destructorc
            this->~S();
            p = new char[123465];
            // cout<<"OP"<<endl;            
            return *this;
        }

    };
    
    void myswap(S &a, S &b){
        // operador copia 
        S aux = a;

        // opeador igual 
        a=b;
        b = aux;   
    }



int main(){

S a , b;
    for(int i=0; i<10000000;i++){

        myswap(a,b);
    }

return 0;
}
