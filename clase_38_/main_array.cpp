//VECTORES MAPS  son clave valor estructura de datos
//UNORDERED_MAP  MAPAS NO OREDENADOS SON TABLAS HASH LO VEREMOS MANANA

#include <unordered_map>
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




struct CarID{
    string placa;
    int anio;
};

struct CarComp{//son funtors porlo general
    bool operator()(const CarID & a,const CarID & b )const{
        //return a.anio < b.anio;
        //tie devuelve una tupla y las tuplas tienen una caracteristica de comparacacio
        return tie(a.anio , a.placa)< tie(b.anio, b.placa);
    }
};


bool strcomp(const string &a,const string &b ){
    return b<a;
}

int main(){



    //es un arbol binario de busqueda    * o(lon N)  en un millon de elementos maximo 20 ciclos para insert para delete para buscar tambien y l



    map<int , string>  m;

    m.insert(pair<int, string>{1234567, "juan salinas"});
    m.insert(make_pair(1234, "juan salinas2"));//intuye los tipos

    m[4567] = "miguel inojosa";//el operador corchetes utilizar par ainsertar o obtener elementos q estoy seguro q estan eln el mapa
    //devuelve una tupla

    std::cout << m[12345888] << '\n';//me devuelve un string & y como no hay ese key crea un objeto en el mapa
    std::cout << m.size() << '\n';

    //forma para buscar es   rd un iterador map<int , string >::iterator
    auto it = m.find(1234567);//devuelve un iterador apuntando 
    
    if(it == m.end()){
        std::cout << "no encontrado" << '\n';

    }else{
        std::cout << it->second << '\n';
    }
    std::cout << "*********************" << '\n';


    for (auto & p: m){//recupero una refecrencia a un pair
        cout <<p.first<<endl;//key
        cout <<p.second<<endl;//value
    }

    //LOS ELEMNENTOS SIEMPRE ESTAN ORDENANDO POR CLAVE

    //LA CLAVE TIENE Q TENER INPLEMNETADO EL OPERADOR MENOR


  //m.erase(clave)

  //UTILIZAR ESTOS MAPAS PARA GUARDAR VALORES POR CLAVE Y NO POR POCCIOCION
    std::cout << "*********************" << '\n';


    //por defecto recive tres cosas typemane key , typemane value  , typemane Comp = less<t>  compraa por el menor
    map<CarID, string, CarComp> m2;  

    m2.insert(make_pair(CarID{"123A",19980}, "modelo 1"));

    m2[CarID{"123b", 2018}] = "tesla A5";

    m2[CarID{"123c", 2019}] = "tesla A67";

    
    for(auto & c : m2){
        std::cout << c.second << '\n';
    }


    std::cout << "*********************" << '\n';//decltype detecta el tipo de la funcion
    map<string , int ,/*bool(*)(const string &,const string &) */ decltype(&strcomp)>  m3{strcomp};//le damos el tipo de la funcion con la q realizara la ccomparaccion
    m3["uno"] = 1;
    m3["dos"] = 2;
    m3["tres"] = 3;
    m3["cuatro"] = 4;
    m3["cinco"] = 5;

    for(auto d : m3){

        std::cout << d.first << '\n';
    }

    //otra clase como los mapas son los mapas no oredenados 
    //

    unordered_map<int , string> x;
    x[1] = "one";
    x[2] = "two";
    x[3] = "three";
    x[4] = "four";
    x[5] = "five";


    for(auto a: x){
        std::cout << a.first << '\n';
        std::cout << a.second << '\n';
    }
    return 0;

    //otras estructuras q podemos ver son 
    //set  arbol BB

    //mordered_set utiliza 

}


