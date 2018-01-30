//MAPAS NO ORDENADOS
#include <unordered_map>//esta es la libreria
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
#include <map> 

#include <list>  //lista doblemente enlazada
using namespace std;


struct CI{
    int n;
    string c;
};
struct CIHash{//esta eleggion es importande para obrencion de datos
    size_t operator()(const CI & c)const{
        return c.n;
    }
};

//ahora otro funtor q calcule si todos los CI son iguales
struct CIEq{
    bool operator()(const CI & a, const CI &b )const{
        return a.n == b.n  && a.c == b.c;//si no comparamos todo esto 
    }
};

///EL RENDIMIENTO DE ESTE ES O(1)
int main(){//CIHash provee el codigo hash , CIEq compara para el hasmap no es NECESARIO SI HAY EL OPERATOR ==
    unordered_map<CI, string , CIHash, CIEq> s;//para nuestro tipos tenemos q sobrecarggar el operador ==
    s.insert(make_pair(CI{123,"cbba"}, "juan lopez"));

    s[CI{456, "lp"}] = "romina perez";
    s[CI{789, "lp"}] = "ariana grande";
    s[CI{123, "pt"}] = "ariana juanbura";


    for(auto & i:s){//faltra u operador igual o un funtor  y una funcion q calcule el codigo hash de esta estructura hay una clase hash<T> pero para nuestras clases tenemos q proveer esta implementacion aqui
        std::cout << i.first.n <<" "<<i.first.c<<" - "<<i.second<< '\n';
    }


    return 0;
}


