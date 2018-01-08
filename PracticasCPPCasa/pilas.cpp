#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class node{
    char * data;
    node * siguiente;
    node(char * sdata, node *snode =nullptr):data{sdata}, siguiente{snode}{
    }
    public:
    ~node(){
    }
    friend class pila;
};

class pila{
    node * ultimo = nullptr;
    public:
    void push(const char * str){
        auto n = new node((char *)str,ultimo );
        ultimo = n;
    }

    const char * pop(){
        if(!ultimo)return 0;
        auto aux = ultimo;
        const char * data = (const char *)aux->data;
        ultimo = ultimo->siguiente;
        delete aux;
        return data;
    }
    void print(){
        auto aux = ultimo;
        while(aux){
            cout<<aux->data<<endl;
            aux = aux->siguiente;
        }
    }
};

int main(){

    pila p;
    p.push("uno");
    p.push("dos");
    p.push("tres");
    p.push("cuatro");
    p.push("cinco");


    p.print();
    cout<<"*****************************"<<endl;
    cout<<p.pop()<<endl;
    cout<<"*****************************"<<endl;    
    cout<<p.pop()<<endl;
    cout<<"***********2******************"<<endl;
    
    p.print();


    return 0;
}