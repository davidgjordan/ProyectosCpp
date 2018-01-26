//VECTORES ARRAY EN EL HEAP
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <vector> 
#include <algorithm> 
#include <array> 

#include <list>  //lista doblemente enlazada
using namespace std;



template <typename T, typename P>
void iterate(const T&  x, P p  ){//itero cualquier cosa q pueda iterar   
    for(typename T::const_iterator i = x.begin() ; i!= x.end(); ++i){//i es list<int>::const_iterator//
        //cout<<*i<<endl;                            //cuando la estructura es constante recivo un cons iterator
        p(*i);
    }
}


//lunes sets mapas 

template <typename T>
bool compareDefault(T & a, T & b){

}


//dos
//T es la vector o array , Comp sera una funcion comparador por defecto  
template <typename T, typename Comp = compareDefault>   ///lista , funcion comparadora con y el objeto q no tenga q implemente el ==
bool is_palindrome(const  T & x, Comp c){//podria recivire una funcion q sepa comparar carros
    c(x);
}

//uno
template<typename T>
bool is_palindrome(const T & x){
    return is_palindrome(x, [](auto  & a , auto & b ){
        return a==b;
    })); 
}


//tarea implementar esto q soporte cualquier tipo y de manera eficiente
// template <typename T >
// bool is_palindrome(const  T & x){//podria recivire una funcion q sepa comparar carros

//     //con strings array y vectores
//     if( *(word.begin()) =! *(word.end())  ){
//         return false;
//     }
//     string copy = word; //se crea dos copias q es pecismo no se deveria acer 

//     reverse(word.begin(), word.end());

//     return copy == world;
    
// }

int main(){


    array<int , 4> d;//este array siempre esta en el stact no como el vector q esta en el heap
    d[0] = 1;
    d[1] = 2;
    d[2] = 4;
    d[3] = 5;

    sort(d.begin(), d.end());
    iterate(d, [](auto n){
        cout<<n<<endl;
    });


    string  x = "amiguitos";
    string  y = "oruro";

    cout<<is_palindrome(x)<<endl;
    cout<<is_palindrome(y)<<endl;


    //reverse(x.beguin, x.end())
    return 0;

}

