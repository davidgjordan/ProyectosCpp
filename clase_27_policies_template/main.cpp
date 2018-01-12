//POLICIES

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template <class T>
struct DefaultCreaterThan{
    bool is_greater_than(const T & a, const T & b)const{
    return a>b;

    } 
};

struct Car{
    int id;
    string model;
    string brand;
    int year;
    
};

struct CarC{
    bool is_greater_than(const Car & a, const Car & b)const{
        return a.id>b.id;
    
        }
    
};

template<class T, class GretterThan = DefaultCreaterThan<T>>//clase mayor q(gt) //se conectan a las templates y proveen comportamiento esas son las politicas
T mmax(const  T&a, const T&b){
    
    GretterThan c;
    return c.is_greater_than(a,b)?a:b;
    //return a>b? a:b;
}




 int main(){
   
    auto y = mmax(10,6);
    auto z = mmax<string>("hello", "hola");


    auto ca = mmax<Car, CarC>(Car{1,"peta","nn",1234},Car{1,"peta1","nn",1234});


    cout<<ca.model<<endl;
    
    
    cout<<y<<endl;
    cout<<z<<endl;
    return 0;

 }