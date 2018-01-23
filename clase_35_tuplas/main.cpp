//TUPLAS   object<int , string>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <tuple>
//#include <string_view>
#include <memory> //contiene punteros inteligentes hay tres
using namespace std;
using namespace std::string_literals;



/* template<typename T>
void show_tuple(const T & data){     
        cout<<data<<endl;
}
 */


template<typename T, size_t s>
void show_tuple(const T & x){

    constexpr auto sz =tuple_size<T>::value;
    cout<<get<sz-s>(x)<<endl;
}

template<typename T>
void show_tuple(const T & data){
    constexpr auto s =tuple_size<T>::value;
        show_tuple<T, s - cont>( data );
}
//IMPELEMTAR EN UNA CLASE Y ACER FUNCIONAR CON ESPECIALIZACION PARCIAL

/* template<typename ...T>
void show_tuple(const T & ...data){
    show_tuple()
}
 */


int main(){

    tuple <int ,int, string> p {6,8, "hello"};//hay dos tipos esta y la de abajo
    auto  q = make_tuple(6, true,"h");//tupla entero boll y const char *
    //su tamano esta agregado en tiempo de compilacion no se puede agregar mas parametros luego
    //tuple r {6, 8,"hello agains"s}; //actualizar c++ para q de   7.2

    //el dos y 1 tienen q ser constantes  const int 
    cout<<get<2>(p)<<endl;//de la tupla p saca el elemento en la pocicion 2
    cout<<get<1>(q)<<endl;//de la tupla p saca el elemento en la pocicion 2
    cout<<tuple_size<decltype(p)>::value<<endl;//devuelve el tamano de la tupla

    int a  = 2;

    decltype (a) b = 8;
    //data una variable detecta el tipo de dato y devuelve su tamano    
    cout<<"*************"<<endl;
    show_tuple(p);
    return 0;
}


template <typename T , size t >

class Iter{

    Iter(T ){

    }

    
    Iter<T,  N -1>;
}