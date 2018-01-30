//LECTURA DE DATOS
#include <iostream>
#include <string>
#include <cstring>
#include <vector> 
#include <fstream> 
#include <iomanip> 


#include <sstream>//

using namespace std;



struct CI{
    int n;
    string c;

};
    ostream& operator<<(ostream & os,const CI & c){
        os<<"("<<c.n<<")"<<c.c;
        return os;
    }

istream& operator>>(istream & is, CI & ci){
    string line;
    getline(is,line);
    if(!is)return is;
    
    auto index = line.find(")");
    auto numstr = line.substr(1, index-1);

    cout<<"*****"<<numstr;
    auto c = line.substr(index+1);
    ci.n = stoi(numstr);//stoi transforma un string a entero
    ci.c = c;
    return is;


}


int main(){//CIHash provee el codigo hash , CIEq compara para el hasmap no es NECESARIO SI HAY EL OPERATOR ==
    
    ifstream g{"lista.txt"};
    if(g.fail()){
        return -8;
    }


    string line;
    while(getline(g,line)){
        std::cout << line << '\n';
    }
    std::cout<<"  asdas" << line << '\n';


    ifstream h{"cis.txt"};
    vector <CI>cis2;
    CI aux;
    while(h>>aux){
        cis2.push_back(aux);
    }
    for(auto & ci:cis2){
        std::cout<<ci<<"\n";
    } 
    //lectuea y estructura binaria

    cout<<"*********************************"<<endl;
    //en ves de botar un archivo bota en memoria
    stringstream ss;
    ss<<1<<"\n";
    ss<<"hola"<<"\n";
    ss<<3.14<<"\n";
    //soporta cualquier tipo q tenga sobrea cargado est operador

    cout<<ss.str()<<endl;


    //y el inputs es para parcear cadenas
    istringstream iss{"hello world"};
    while(iss){

        string aux;
        iss>>aux;
        cout<<aux<<endl;
    }


    double pi = 3.1345678;
    cout <<setprecision(4)<<pi<<endl;

    double x = 3'000'000;

    cout <<scientific<<x<<endl;
    

    //ARCHIVOS BINARIOS

    return 0;
}


