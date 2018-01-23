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



/* template<typename ...T>
auto sum2(const T& ...args){
    return (0 +...+args); //parametrer pack folding  los mismos operadores tienen q ser + +
        //(args+...+0)//  o al reves tambien suma al valor inicial todos los demas parametros
} */
template <typename T>
void  show2(const T& x){
    cout<<x<<endl;
}

template <typename ... T>
void  show2(const T& ...args){
    (show2(args),...);//llamamos a la version dons con cada uno de los argumentos 
}


int main(){
    
    
 
    cout<<"*******************"<<endl;



    //cout<<sum2(6,2,3,5,67,7)<<endl;

    show2(8,5,"hola",4);

    return 0;






}