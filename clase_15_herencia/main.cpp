#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

// class person{

// public:
//     string name;
//     int id;
// };

//     //todo lo public de esta clase sera de esta publico para las hijas q hereden de student
// class student: private person{//si seria privado las propiedades de person solo se podrian usar en studen no en las q ereden destuden

// public:
//     string curso;
// }

using namespace std;

class person{//privados por defecto
        string name;
        int id;
public: //virtual da polimorfismo
        virtual void print() const{//basta con un virtual para q se mapee en la memorita tabla vtable
            cout<<id<<" "<<name<<endl;//y ahi guarda llave valor llave el objeto y key el metodo
        }
public:
    person(const string & n , int i):name(n), id(i){

    }
    virtual ~person(){//cuando hay un polimorfismo tengo q poner un destructor virtual
    }
    // person(){
        
    //         }
    };
    
        //todo lo public de esta clase sera de esta publico para las hijas q hereden de student
    class student: public person{//si seria privado las propiedades de person solo se podrian usar en studen no en las q ereden destuden  
        string curso;
    public:
        student():person("",0){
        }
        ~student(){
            cout<<"bye"<<endl;//se llama a los destructores encascada
        }
        student(const string & n, int i, const string & c):person(n,i),curso{c}{
        }
        //por nomenclatura para facilitar errores se pone override
        void print() const override{
            person::print();
            cout<<" "<<curso<<endl;
        }
    };

int main()
{
/* 
    person q{"juan perez", 123};

    student s{"maria", 687, "devint24"};

    q.print();
    s.print();
    */
    person * p = new person("romulo", 123);
    student * q = new student("carlos", 63,"devin24");
     p->print();
     q->print();


     person * s = new student("pepe",45, "devint24");

     s->print();

     delete s;

     delete p;
     delete q;
return 0;
}
