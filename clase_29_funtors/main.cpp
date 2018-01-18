//son objetos q se comportan como funcion sirven como funciones
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;


struct S{

    template<typename T>
    T operator()(T a , T b){
        return a+b;
    }

/* double operator()(double a , double b){
    return a+b;
}
 */

};

int main(){
    S s ;
    cout<<s(2,3)<<endl;
    cout<<s(6.25,3.2)<<endl;
    //cout<<s("hola", " mundo")<<endl;
                //desde el estandar 14 se pude mandar auto
    int p[] = {2,3,4,5,1,2,0};//donde deveria ir un puntero a una funcion o un funtor
    qsort(p, 7, sizeof(int), [](const void * a, const void *b) -> int{
        int * pa = (int*)a;
        int * pb = (int*)b;//lamda expresion  
        return *pa - *pb;
    });

    for(auto i: p){
        cout<<i<<endl;
    }


    cout<<"*******************Libreria  ALgorithm************************"<<endl;
    int q[] = {2,3,4,5,1,2,0};//donde deveria ir un puntero a una funcion o un funtor    std::sort(q,q+7);//resive un iterador de t el begin y el end
    std::sort(q,q+7);
    for(auto i: q){
        cout<<i<<endl;
    }
    cout<<"*******************Libreria  ALgorithm************************"<<endl;
    bool asceding = false;    //capturamos variables exrternas entre los corchetes en caso de necesitarlos 
    std::sort(q,q+7,[&asceding](int a ,int b){//por q no esta  //para modifcar el cvalor 
        asceding = !asceding;  //de las vaiables lo pasamos por referencia
        if(asceding){      //si quiseramos todas las variables ponemos [=]  [&] todas para modificar
            return a<b;
        }
        return a>b;
    });

    for(auto i: q){
        cout<<i<<endl;
    }
    cout<<"*******************Libreria  ALgorithm************************"<<endl;
    
    
    //es como una funcion lambda template
    auto f = [](auto a){//
        cout<<a<<endl;
    };


    f(2);
    f(3);
    f(7);
    f("hola");
    
    



    return 0;
}