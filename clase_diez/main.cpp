#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class persona{
private:
    char * fn;//va vivir en el heap puede ser un new si quiesieramos en la stack tendira q ser char fn[56]
    char *ln; //apellido
    int id;//carnet

public:
    persona(const char * fn,const char * ln, int id):  id{id}{
        //hacerse copias de las cadenas
        this->fn = new_string(fn);
        this->ln = new_string(ln);
    }
    ~persona(){
        cout<<"bye"<<endl;
        delete []fn;
        delete []ln;
    }

    persona(const persona & src):id(src.id){
        fn= new_string(src.fn);
        ln= new_string(src.ln);
    }

    //es una funcion
    persona & operator=(const persona& p){
        // si este puntero es igual a este otro nada
        if(&p == this ){
            return *this;
        }
        // siempre se llama al destrcutor con this
        this->~persona();
        id = p.id;
        fn= new_string(p.fn);
        ln= new_string(p.ln);
        cout<<"OP=\n";
        
        return *this;
    }
    bool  operator==(const persona& p){
        // si este puntero es igual a este otro nada
        return strcmp(fn, p.fn) == 0 && strcmp(ln, p.ln) == 0 && id == p.id ;
    }
//cuando marcas con const al final al this lo vuelves constante
void print() const{
    cout<<fn<<endl;
    cout<<ln<<endl;
    cout<<id<<endl;
}
// opeador de movida  se tiene  q mantener talbien el de =
persona & operator=( persona &&p){ //es un rvalue reference puede ser modificada en este tipo de llamadas

        if(&p == this){
            return *this;
        }
        // si quiero robarme la implementacion de la p
        id = p.id;
        fn = p.fn;
        ln = p.ln;
        p.fn = nullptr;
        p.ln = nullptr;
        cout<<"OP=move"<<endl;
}

private:
    //todos loe metodos reciben un this los estaticos no por eso no 
    //pueden acceder a los metodos de las clases    
   static char * new_string(const char * s){
        auto len = strlen(s);
        auto ns = new char[len+1];
        // strcpy(ns, s);
        // este copea de varios bloques de bits
        memcpy(ns,s, len+1);
        return ns;
    }
};


persona getPersona();
persona getPersona(){
    
    
    persona p{"carlos","canedo", 572};
    return p;
}

int main(){

    /* //variabbels estane en memoria de lectura nombre ras
    persona p1{"pedro", "ras",34};
    //p1.print();

    //declarada en el heap
    persona * p2;

    {
        string  s = "hermenegildo alfonnsencio";
        string  r = "vonifacion sansetenea";

        p2 = new persona(s.c_str(), r.c_str(), 12);
        //se llama al destructor de los strings en este contexto
    }
    //p2->print();

    delete p2;
    
    // persona p3; es una instacia del stack con costructor sin parametros
    //estarias creando una instancia aqui usas el new pero ene l stack
    persona p3{"hermenegildo alfonnsencio","vonifacion sansetenea",123};
    //coipamos una copia clonamos este objeto   es lo mismo  auto p4{p3}  llamamos al constructor copia
    // creamos un nuevo objeto apartir de uno existente
    auto p4 = p3; //aqui llama al constructor copia del char del int etc
    //va apuntar a sus refercnias 
    //si en mi clase uso new tengo q acer el constructor copia 
    //p4.print();

    // cuando uso new uso operador constructor copia destructor 


    persona p5 {"omar","ve",12};
    //p5.print();
    // esto no es copia es una asignacion  tenemos q sobrecargar el operador de asignacion
    //si no el compilador me genera un o de asignacion 
    p5 = p3;
    //p5.print();
    persona p6{"omar","ve",12};
    persona p7 = p6;

    if(p6 == p7){
        cout<<"iguales"<<endl;
    }else{
        cout<<"diferentes"<<endl;        
    } */


    persona q{"a","b",1};

    q = getPersona();
    q.print();
    // en una clase por defecto se crea constructor " copia operador =  constructor de movida 
    return 0;
}
// SEMANTICA DE MOVIDA 
//rvalue referecias
int a = 2;
int b       =  a ;
// l value  r value  a no cambia de valor es constante
