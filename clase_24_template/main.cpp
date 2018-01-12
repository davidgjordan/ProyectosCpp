//TEMPLATES

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//la siguiente apartir de template sera una funcion solo una funcion
template <typename T>//se puede poner clase igual en ves de typename  ESTE TEMPLATE TODO EN UNA SOLA CLASE TIENE Q ESTAR
T maxx(T a,T b)
{
    return a>b ? a:b;
}

template <size_t N>
void star(){
    for (auto i = 0U; i < N; i++)
    {
        cout<<"*";
    }
    cout<<"\n";
    
}

template <int A, int B>
struct Maxxx{
    static const int value = A>B ? A:B;
};



template <class T>//SE PUDE ANADIR MAS PARAMETROS <CLASS T , CLASS S, CLASS O>
class Container{
    T x;

public:
    Container(const T& x):x(x){}
    T & get(){
        return x;
    }

};


//Para que de con un Integer se usa conceptos 

struct Integer{
    int  n; 
    bool operator>(const Integer & p) const{
        return n> p.n;
    }
};



int main(){

    auto x = maxx(10,20);
    cout<<x<<"\n";
    
    auto y = maxx(10.3,20.5);
    cout<<y<<"\n";


    auto z = maxx(Integer{4},Integer{5});
    cout<<z.n<<"\n";
    

    auto u = maxx<string>("hello", "world");//le decimos q T sea un string
    cout<<u<<"\n";

    
    constexpr int p = 7;//solo valores constantes imprime  ///consexpr es q es una expresion conocida en tiempo de compuilacion
    star<5>();


    cout<< Maxxx<9,25>::value<<endl;


    Container <int>q{89}; //SIEMPRE DECIMOS EL TIPO T 
    cout<< q.get()<<endl;
    

    //String h = "hello"; == basic.string<char> h; el string es un base..... osea es un template

    

//PREGUNTA
    return  0;
}

//INSTALAR LA VERSION 7.2 DE G++