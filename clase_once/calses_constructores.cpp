#include <iostream>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;
//CON CONSTEXPR EL COPILADOR REMPLAZA N EN TODOS LAS N POR UN MILLON
//TODAVIA NO LE ASIGNA UN MILOLON A N PARA MEJORAR LA MEMORIA
constexpr auto N = 10000000U;

class X{
    char * p;
public:
    X(char m ): p(new char[N]){
        for(auto i=0U; i<N;i++){
            p[i] = m;
        }
    }
    ~X(){
        delete [] p;
    }

    X(const X & src): p (new char [N]){
        for(auto i=0U; i<N;i++){
            p[i] = src.p[i];
      
        }  
    }


    X& operator=(const  X & src){
        if(&src== this){
            return *this;
        }//es ley

        this->~X();
        p = new char[N];
        for(auto i=0U; i<N;i++){
            p[i] = src.p[i];
      
        } 
        return *this;
    }

    // cONSTRUCTOR COPIA DE MOVIDA 
    //dicen q es un rvalue reference significa q src al 
    //salir sera modificada
    X(X&& src) :p (src.p){ //this y src apuntan al mismo hasta q 
                            //hagamos esto
        src.p = nullptr;
    }

    //OPERADOR = DE MOVIDA


    X & operator=(X&& src){
        if(&src == this){
            return *this;
        }
        this->~X();
        p = src.p;
        src.p = nullptr;
        return *this;

    }
};

int main(){




    X a{'a'};
    X b{'b'};


clock_t z0 = clock();
for(auto i=0U; i<100;i++){
    //necesitamos implementar el co nstructor copia de movida 
//CON LA SEMANTICA DE MOVIDA SOLO CAMBIAMOS LOS PUNTEROS
    // para aplicar dsemantica de movida le decimos usa semantica de movida con move
    //constructor copia
    X aux = move(a);

    //move es una funciod 
    a = std::move(b) ;
    b =move(aux);
} 

clock_t z1 = clock();
    cout<<(z1 - z0)/1000<<endl;

    return 0;

}

// EL COMPILADOR DECIDE ACER MOVIDAS EN LOS SIGUIENTES CASOS
/* 
    STRUC P {
        STRING NAME;

        P get(){
            P   p {"hola"};
            return p;
        }
    }

    INT MIAN{\

        aqui ace semantica de movida
        la cadena sss vive solo entre las llaves   y name tine una copia de ssss 
        P x {"ASDAS"s}; //el puntero sasas le asignamos a x


        aqui no porq s no esta dentro de un ambito de {} destruccio al menos q agamos
        //P y {move(s)}; 
        string s = "hola"
        P y {s};
        cout<<s<<endl;



        aqui si gett retorna una variable q se destruy4e en ese metodo
        P x = get();
    }



*/