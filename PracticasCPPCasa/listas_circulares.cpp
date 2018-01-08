#include <iostream>
#include <string>
#include <cstring>


using namespace std;

class node{
    char * data;
    node * siguiente;
    node(const char * ndata, node * nsiguiente = nullptr ):data{(char *)ndata},siguiente{nsiguiente}{
    }
    ~node(){}
    friend class lista_c;
};

class lista_c{
    node * actual = nullptr;
    public:
    void add(const char * ndata){
        auto n = new node(ndata);
        if(!actual) actual = n;
        else n->siguiente = actual->siguiente;
        actual->siguiente = n;
    }
    void mostrar(){
        auto n = actual;
        do{
            cout<<"data: "<<n->data<<endl;
            n = n->siguiente;
        }while(n != actual);
    }
    void remove(const char * rdata){
        auto n = actual;
        do {
            if(strcmp(actual->siguiente->data , rdata)!= 0) actual = actual->siguiente;

        }while(actual != n && strcmp(actual->siguiente->data , rdata) != 0 );//mientras no lleguemos al principio y no encontremos el data
            if(strcmp(actual->siguiente->data , rdata) == 0){//si encontramos el dao en actual
                if(actual == actual->siguiente){//si solo tiene un elemento
                    delete actual;
                    actual = nullptr;
                }else{
                    n = actual->siguiente;
                    actual->siguiente = n->siguiente;
                    delete n;
                }

            }
    }
    ~lista_c(){
        node * n;
        while(actual->siguiente != actual){
            n = actual->siguiente;
            actual->siguiente = n->siguiente;
            delete n;
        }
        delete actual;
        actual = nullptr;
        
    }

};


int main(){
    lista_c l;
    l.add("uno");
    l.add("dos");
    l.add("tres");
    l.add("cuatro");
    l.add("cinco");
    l.mostrar();
    cout<<"***********************"<<endl;
    l.remove("uno");
    l.mostrar();
    
    return 0;
}