#include <iostream>

using namespace std;
class node{
    private:
     char * data;
     node * siguiente;
    public:
     node(const char * sdata, node * ssig = nullptr):data{(char *)sdata},siguiente{ssig}{
     }
     ~node(){}
     friend class cola;
};

class cola{
    private:
    node * primero;
    node * ultimo;
    public:
    cola():primero{nullptr}, ultimo{nullptr}{
    }
    ~cola(){
    }
    void push(const char  * sdata){
        auto n = new node(sdata);
        if(ultimo){
            ultimo->siguiente = n;
        }
        ultimo = n;
        if(!primero){
            primero = n;
        }
    }

    char * pop(){
        auto n = primero;
        if(!n)return 0;
        primero = primero->siguiente;
        auto data = n->data;
        delete n;
        if(!primero) ultimo = nullptr;

        return data;
    }

    void print(){
        auto n = primero;
        while(n){
            cout<<"data: "<<n->data<<endl;
            n = n->siguiente;
        }
    }
};
 int main(){
     cola c;

     c.push("uno");
     c.push("dos");
     c.push("tres");
     c.push("cuatro");
     c.push("cinco");
    c.print();
    cout<<"***********************"<<endl;    
    cout<<c.pop()<<endl;
    cout<<c.pop()<<endl;
    cout<<"***********************"<<endl;    
    c.print();    
     return 0;
 }
