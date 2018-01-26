//PERFECT FORWARDING
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



struct M{

    M(){
        std::cout << "M constrcutor" << '\n';
    }

    M(const M&){
        std::cout << "M constrcutor copia" << '\n';
    }
    ~M(){
        std::cout << "M destructor" << '\n';
    }

    void say()const{
        std::cout << "say" << '\n';
    }
    //constrcutor movida para el caso de la M() de abajo
    M(M&& s){
        std::cout << "M Move " << '\n';
    }
};

class Q {
    public:
    M a,b;
    //no se llama al movida porq aqui es una referencia normal
    /* Q(const M&a, const M&b):a(a),b(b){

    }

    //para el caso de arriba se ace esto
    Q(const M&a, M&& b):a(a),b(move(b)){ // para este caso es  Q q (x, M());  para este ya no da Q q (M(), M())
        std::cout << "Q Move " << '\n';
        
    } */

    //perfect forwarnig
    template <typename T , class U>
    Q( T&&a, U&& b):a(std::forward<T>(a)),b(std::forward<U>(b)){ 
    
            std::cout << "Q Move perfect forwarnig " << '\n';
        
    }



};

void sum(int a , int b){
    std::cout << (a+b) << '\n';
}

template<class FUNC , typename ...X>
void f(FUNC p ,   X &&...args){ //perferforwar  funciona con && RValue
    std::cout << "invocando" << '\n';
    p(forward<X>(args)...);//forward decide si acer copias movidas o constructor copia o movida
    //llama a la funcion p con cada uno de los elementos de args
}

void inc(const string x ,int & y){
    std::cout << x << '\n';
    y++;
}

struct Person{

    string name;
    int age;
    public:
    //el string view tiene un constructor q realiza el perferforwar
    /* Person(string_view name, int age):name(name),age(age){//solo es paraacceder a una cadena 
    } */
};

int main(){


    {
    M x;
    M y;
    
    Q q(x,y);
    x.say();
    }
    {
        std::cout << "*****************" << '\n';
        M x;
        Q q (x, M());//M() es copia es una referencia constante o (rvalue) y x un (lvalue)   revisar lo de rvalue y l value para estar seguro

        x.say();//M() se destruye en aqui osea q see acer una movida
    }
    
    std::cout << "*****************" << '\n';
    
    f(sum , 8,5);
    f([] (auto & s){//expresion lamda q recive un string
        std::cout << s << '\n';
    }, " hello world");
    
int n = 8;
f(inc, "hello ", n);
std::cout << n << '\n';
    std::cout << "*****************" << '\n';


    tuple <string, int> p {"juan perez"s, 32};
    //desde el standar 17 c++ 7.2  actuliza 
    //Person pp = make_from_tuple<Person> (p);//trasforma d ela tuple p a la clase person

}

