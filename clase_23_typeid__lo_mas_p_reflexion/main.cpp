#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <stdexcept>
#include <typeinfo>

//RTTI  RUN TYPE INFORMATION-> LO MAS PARECIDO A REFLEXION //CONSTISTE EN SABER EN TIEMPO
//DE EJECUCION DE Q TIPO ES CIERTO OBJETO  PERO OCUPA MUCHA MEMORIA
using namespace std;

struct Animal{
    virtual ~Animal(){}
};
struct Gato :public Animal{
    
};

int main(){

    // int a = 2;
    // int * b =&a;

    // auto & ta = typeid(a); //es const type_info &
    // auto & tb = typeid(b); //std::type_info &  devuelve me devuelve una iunstancia singleton 
    // cout <<ta.name()<<endl;//aqui se esta tratando de acer un acopba
    // cout <<tb.name()<<endl;//devuelve el name de la clase   
    // //PI DEVUELVE EL COMPILADOR LE DA ESTE TIPO DE DATO

    // if(ta == typeid(int))
    //     cout<<"int"<<endl;
    // else
    // cout<<"diferent"<<endl;
    
  
//TAREA
    Animal * a = new Animal();
    Gato * g = new Gato();
    Animal * b = new Gato();

 cout<<typeid(a).name()<<endl;
 cout<<typeid(g).name()<<endl;//devulvel por delante e
 cout<<typeid(b).name()<<endl;
 cout<<typeid(*b).name()<<endl;
    

 
    TreeMap M;//TODO ORIENTADO A OBJETOS

    m.add(new Integer(2), new String("dos"));
    m.add(new Integer(4), new String("cuatro"));
    m.add(new Integer(0), new String("cero"));
    

    cout<<m.toString()<<endl;

    m.remove(Integer {0});

    for(auto & p: m){ //TENEMOS Q ACER ITERADOR EN EL TreeMap  //llamar al destructor borrar nodos los objetos de ;los nodeos y el comparador

        cout<<p.key->toString()<<endl;
        cout<<p.value->toString()<<endl;
    }
    

    cout<<m[Integer{4}]->toString()<<endl;//implementar operatror []  //accedo a la valor con la llave 4
    //es como un m.get

    //tendremos una propiedad de clase de tipo CIComparetor para segun a eso comparar el CI
    TreeMap pm{new CIComparator()};//nos serviria  

    m.add(new CI(4928514,"Cbba"), new String("pedro lopez"));//el default comparater compara 

    cout<<pm.toString()<<endl;
    
    return 0;
}