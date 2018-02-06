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


std::map<string, T>::iterator
template <typename T, typename P>
void iterate(const T&  x, P p  ){//itero cualquier cosa q pueda iterar   
    for(typename T::const_iterator i = x.begin() ; i!= x.end(); ++i){//i es list<int>::const_iterator//
        //cout<<*i<<endl;                            //cuando la estructura es constante recivo un cons iterator
        p(*i);
    }
}

struct X{
    int n;
     X (int n): n(n){
        std::cout << "hello X" << '\n';
    }

    ~X(){
        std::cout << "bye X " << '\n';
    }
    X(const X & x):n(x.n){
        std::cout << "Copy X" << '\n';
    }

    X(const X && x):n(x.n){ //con esto el operador igual desaparece
        std::cout << "Move X" << '\n';
    }

    X & operator=(const X & x){
        n = x.n;
        return *this;
    }
};
struct Animal{

    virtual  ~Animal(){
        std::cout << "Animal chau" << '\n';
    }

    virtual void say()const{
        std::cout << "*****" << '\n';
    }
};
struct Dog : Animal{
    void say()  const override{
        std::cout << "gua gua" << '\n';
    }
};

struct Cat : Animal{
    void say()  const override{
        std::cout << "miau miau" << '\n';
    }
};
int main(){


    
    // vector<int> q {1,2,5,78,8};

    // q.push_back(1);
    // //q.pus_front(100);//no existe por su ineficiencia
    // //iterar
    // iterate(q , [](auto i){
    //     std::cout << i << '\n';
    // });
    // std::cout << "*************************" << '\n';
    // cout<<q[4]<<endl;
    // //std::cout << q.at(10) << '\n';//verifica q 10 este dentro de el array si no devuelve una exepcion auto_range
    // std::cout << "*************************" << '\n';
    // sort(q.begin(), q.end());

    // auto z = q.begin()+2;
    // std::cout << *z << '\n';
    // for(auto i : q){
    //     std::cout << i << '\n';
    // }

    // std::cout << "*************************" << '\n';
    // vector<string> r(3);//array de tamano 3
    // r.push_back("hello");

    // std::cout << "/* ******************** */" << '\n';


    // vector<X> x = {3,4,7,6,7,4, 4};//llama al constructor de X
    // std::cout << "/* ******************** */" << '\n';
    // x.push_back(18); //costructor de movida
    // std::cout << "/* ******************** */" << '\n';

    // x.emplace_back(15); //crea el objeto en este stack le paso lo q recive el constructor d emi clase x
    //                 //nos permite evitar una copia y una movida
    // std::cout << "/* ******************** */" << '\n';

    // sort(x.begin(), x.end(), [](X & a, X & b ){
    //     return a.n <b.n;
    // });


    //for(auto & i:x){
     //   std::cout << i.n << '\n';
    //}

    // std::cout << "/* ******************** */" << '\n';
    // vector<Animal  *> ss; //* para el polimorfismo
    // vector<unique_ptr<Animal>> ss; //* para el polimorfismo  
    //                             // si quisieramos compartir los elementos seria shared_ptr pero es 
    //                             //mucho mas pesado q el unique_ptr
    // ss.push_back(make_unique<Dog>());    
    // ss.push_back(make_unique<Cat>());    

    // for(auto &i :ss){
    //     i->say();
    // }


    // for (auto i : ss){
    //     delete i ;
    // }


    // //tipo unique_ptr<Animal>
    // auto & ps = ss[1];//no puedo hacer
    // //el operador igual en este caso hace una copia
    // ps->say();

    // //casteo 
    // Cat * c = dynamic_cast<Cat *>( ps.get());//devuievle el puntero Animal *
    // c->say();


    // std::cout << "*****************" << '\n';


    return 0;

}

