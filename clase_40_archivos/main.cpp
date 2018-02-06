//archivos
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
#include <fstream> 

#include <list>  //lista doblemente enlazada
using namespace std;



struct CI{
    int n;
    string c;

};
    ostream& operator<<(ostream &os,const CI & c){
        os<<"("<<c.n<<")"<<c.c;
        return os;
    }


int main(){//CIHash provee el codigo hash , CIEq compara para el hasmap no es NECESARIO SI HAY EL OPERATOR ==
    


    ofstream f{"lista.txt"};
    if(f.fail()){//si fallo al abrir
        return -2;
    }

    vector<string> ss = {"enero", "febrero", "marzo","abril", "mayo"};
    for(auto &s : ss){
        f<<s<<"\n";
    }
    //cout es una instancia de ostream
    vector<CI> cis;

    cis.push_back(CI{1234,"cbba"});
    cis.push_back(CI{5678,"lp"});

    ofstream fc{"cis.txt"};
    for(auto & c: cis){
        fc<<c<<"\n";

    }

    return 0;
}


