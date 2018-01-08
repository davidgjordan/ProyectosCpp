#include <iostream>
#include <string>
#include <cstring>


using namespace std;

class node{
    public:
    char * data;
    node * anterior;
    node * siguiente;
    ~node(){
        // delete data;
        // delete anterior;
        // delete siguiente;
    }
};
struct ll{
    node * first= nullptr;
    node * last= nullptr;
    public:
    ll(){}
    ~ll(){
        cout<<"destructor"<<endl;
        auto aux = first;
 		while(aux){
 			auto next = aux->siguiente;
             aux->data = nullptr;
             aux = nullptr;
 			//delete aux->data;
 			//delete aux;
 			aux = next;
 		}
         print();
    }
    void add_front(const char * ndata){
        auto n = new node{(char *)ndata, nullptr, nullptr};
        if(first == nullptr){
            first = last = n;
        }else{
            n->siguiente = first;
            first->anterior = n;
            first = n;
        }
    }
    void add_back(const char * ndata){
        auto n = new node{(char *)ndata, nullptr, nullptr};
        if(first == nullptr){
            first = last = n;
        }else{
            last->siguiente = n;
            n->anterior = last;
            last = n;
        }
    }
    void add_after_of(const char * data, const char * ndata){
        auto n = new node{(char *)ndata, nullptr, nullptr};
        if(first == nullptr){
            first = last = n;
        }else{
            auto aux = first;
            while(aux){
                auto next = aux->siguiente;
                if(strcmp(aux->data, (char *)data)==0){
                    if(aux->anterior == nullptr && aux->siguiente ==nullptr){
                        aux->siguiente = n;
                        n->anterior = aux;
                        last = n;
                    }else if (aux->anterior == nullptr && aux->siguiente != nullptr){//soy el primero
                        n->siguiente = aux->siguiente;
                        n->anterior = aux;
                        aux->siguiente->anterior = n;
                        aux->siguiente = n;
                    }else if(aux->anterior != nullptr && aux->siguiente == nullptr){//soy el ultimo
                        n->anterior = aux;
                        aux->siguiente = n;
                        last = n;
                    }else{
                        n->siguiente = aux->siguiente;
                        n->anterior = aux;
                        aux->siguiente->anterior = n;
                        aux->siguiente = n;
                    }
                }
                aux = next;
            }
        }
    }
    void print(){
        auto n = first;
        while(n){
            cout<<"data: "<<n->data<<endl;
            n = n->siguiente;
        }
    }
    void print_reverse(){
        auto n = last;
        while(n){
            cout<<"data: "<<n->data<<endl;
            n = n->anterior;
        }
    }
    void remove(const char * rdata){
        auto n = first;
        while(n){
            auto aux = n->siguiente;
            if(strcmp(n->data , rdata) == 0){
                if(n->anterior == nullptr && n->siguiente == nullptr){
                    n->data = nullptr;                    
                    n =nullptr;
                }else if(n->anterior == nullptr&& n->siguiente != nullptr){//eres el primero
                     n->siguiente->anterior = nullptr;
                     first = n->siguiente;
                    n->data = nullptr;                                         
                     n = nullptr;
                }else if(n->siguiente == nullptr){
                    n->anterior->siguiente = nullptr;
                    last = n->anterior;
                    n->data = nullptr;                                        
                    n = nullptr;
                }else{
                    n->anterior->siguiente = n->siguiente;
                    n->siguiente->anterior = n->anterior;
                    n->data = nullptr;                    
                    n =nullptr;
                }
            }
            n = aux;
        }
    }
    bool existe(const char * rdata){
        auto n = first;
        if(n==nullptr){
            return false;
        }
        while(n){
            if(strcmp(n->data, (char *)rdata) == 0){
                return true;
            }
            n = n->siguiente;
        }
    }
};

int main(){

    cout <<"Hello world"<<endl;
    ll l;
    l.add_back("uno");
    l.add_back("dos");
    l.add_back("tres");
    l.add_back("cuatro");
    l.add_back("cinco");
    l.add_back("cinco");
    l.print();
    cout<<"***********************"<<endl;
    l.remove("cinco");
    l.print();
    cout<<"***********************"<<endl;
    //l.print_reverse();

    cout<<l.existe("cinco")<<endl;
    l.add_after_of("cuatro","add");
    l.print();
    
    node n;
    return 0;
}






















