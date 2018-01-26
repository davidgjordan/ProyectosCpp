//VECTORES Y LISTAS
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <vector> 

#include <list>  //lista doblemente enlazada
using namespace std;

template <typename T, typename P>
void iterate(const T&  x, P p  ){//itero cualquier cosa q pueda iterar   
    for(typename T::const_iterator i = x.begin() ; i!= x.end(); ++i){//i es list<int>::const_iterator//
        //cout<<*i<<endl;                            //cuando la estructura es constante recivo un cons iterator
        p(*i);
    }
}

int main(){
    list <int> x;
    x.push_back(6);
    x.push_back(8);//6 -> 8
    x.push_front(5);//5-> 6 -> 8
    cout << x.size() << '\n';
    std::cout << x.front() << '\n';    //devuelve el primero
    std::cout << x.back() << '\n';    //devuelve el ultimo
    std::cout << "**********************" << '\n';

    int sum = 0;
    iterate(x, [&sum](auto x){
        //std::cout << x << '\n';
        sum+=x;
    });

    std::cout << sum << '\n';
    std::cout << "**********************" << '\n';


    list<string> s = {"one","two","thre","for","five"};

    s.push_back("seven");
    s.push_back("eigth");

    for(auto i = s.begin() ;i != s.end(); ){
        if((*i)[0] == 't' ){
            i = s.erase(i);//devuelve un iterador
        }else{
            ++i;
        }

    }

    for(auto  & data : s){
        std::cout << data << '\n';
    }

    //podemos implemtar stacks



    return 0;

}

