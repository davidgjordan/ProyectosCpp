#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <stdexcept>
//LISTAS GENERICAS CON MACROS
using namespace std;
# define  DEF_LL(T,LL)\
struct LL##Node{\
    T elem;\
    LL##Node * next;\
};\
struct LL{\
    LL##Node * first = nullptr;\
    LL##Node * last = nullptr;\
};\
void add(LL & x, const T & y){\
    auto nn = new LL##Node{y, nullptr};\
    if(x.first==nullptr){\
        x.first = x.last=nn;\
        return;\
    }\
    x.last->next = nn;\
    x.last = nn;\
}

DEF_LL(int , IntelicenceList)
DEF_LL(string , StringLinkedList)

//__file__  devuelve el numero
//__line__  devuelve el numero de linea 
int main(){
    IntelicenceList a;
    add(a,15);
    add(a,15);
    add(a,15);
    add(a,15);
    auto aux =a.first;
    while(aux){
        cout<<aux->elem<<endl;
        aux =aux->next;
    }

    StringLinkedList b;
        add(b,"15gfj");
        add(b,"15gfj");
        add(b,"15gfj");
        add(b,"15gfj");
        auto auxs =b.first;
        while(auxs){
            cout<<auxs->elem<<endl;
            auxs =auxs->next;
        }

    return 0;
}