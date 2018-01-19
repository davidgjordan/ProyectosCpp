//VARIABLE TEMPLATE
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
//#include <string_view>
#include <memory> //contiene punteros inteligentes hay tres

using namespace std;
/* using namespace std::string_literals;



template<typename T, typename U >
T sum(const T & a, const U & b){
    return a+b;
}

//algo q puede recivir varios elementos
template<typename T , typename ...ARGS>//repressemtas varios tipos ARGS
T sum(const T & x, const ARGS & ... args){//args q es un conjunto de datos argsr se llama parametress pack
    return x + sum(args...);//este agrs.. parameter parck expaansion

}

template<typename T>
void show(string_view s , const T & x  ){
    std::cout << x <<endl;
}

template<typename T ,typename U , typename ...ARGS>//repressemtas varios tipos ARGS
void show(const T & separador ,const U x, const ARGS & ...args ){

   //show(separador); //    show(";", 2 , 8 , "hola", true);
     show(separador);
    show(x ,args...); 
    cout<<x<<separador;
    show(separador);
    
    
} */

struct Car{
string brand;
string role;
int year;
};
template <class T, class ...U>
T * New(const U& ...args){
    std::cout << "Hello" << '\n';
    return new T{args...};
}

int main(){
    
    
    /* auto p = sum(2,5);
    auto q = sum(12,5);
    auto r = sum(2,56,5,6,7);
    auto s = sum(24,56.23,23.1);
    
    
    auto u = sum<string>("bye"s,"is"s, "friday"s, "19"s);
    
    show(";", 2 , 8 , "hola", true);
 */


    auto x = New<Car>("Vw","peta", 1995);
    cout <<x->brand<<endl; //marca




    return 0;






}