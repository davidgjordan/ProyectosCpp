//VECTORES ARRAY EN EL HEAP
#include <iostream>
#include <string>
#include <cstring>
#include <vector> 
#include <algorithm> 
#include <array> 
#include <list>  //lista doblemente enlazada
using namespace std;



template <typename T, typename P>
void iterate(const T&  x, P p  ){
    for(typename T::const_iterator i = x.begin() ; i!= x.end(); ++i){
        p(*i);
    }
}

template <typename T, typename Comp>   
bool is_palindrome(const  T & x, Comp c ){
    int j = x.size()-1;
    for(int i =0 ; i<(x.size() /2)+1; i++){
        if(!c( x[i] , x[j] ) ){
            return false;
        }
        j--;
    }

    return true;
}


template<typename T>
bool is_palindrome(const T & x){
    return is_palindrome(x, [](auto  & a , auto & b ){  
        return a==b;
    }); 
}

struct Car{
    int serie;
    string model;
     bool operator==(const Car& p){
        return  serie == p.serie;
    }
};


 bool equalsCar( Car a, Car b ){
    return a == b;
} 

int main(){


    array<int , 4> d;
    d[0] = 1;
    d[1] = 2;
    d[2] = 2;
    d[3] = 1;

    string  x = "amiguitos";
    string  y = "oruro";
    cout<<"****************************************"<<endl;
    cout<<is_palindrome(x)<<endl;
    cout<<is_palindrome(y)<<endl;
    cout<<is_palindrome(d)<<endl;
    cout<<is_palindrome(x)<<endl;

    cout<<"*******************CARDS*********************"<<endl;
    vector<Car> soyPalindromo;
    soyPalindromo.push_back(Car{111});
    soyPalindromo.push_back(Car{222});
    soyPalindromo.push_back(Car{222});
    soyPalindromo.push_back(Car{111});


    vector<Car> noSoyPalindromo;
    noSoyPalindromo.push_back(Car{111});
    noSoyPalindromo.push_back(Car{222});
    noSoyPalindromo.push_back(Car{222});
    noSoyPalindromo.push_back(Car{113});
    
    cout<<"******************Car 1 soyPalindromo**********************"<<endl;
    cout<<is_palindrome(soyPalindromo,[]( Car  a,  Car  b)->bool{
        return a == b;
    })<<endl;
    
    cout<<"******************Car 1 soyPalindromo**********************"<<endl;

    cout<<is_palindrome(soyPalindromo,equalsCar)<<endl;
    


    cout<<"******************Car 2 noSoyPalindromo**********************"<<endl;
    cout<<is_palindrome(noSoyPalindromo,[]( Car  a,  Car  b)->bool{
        return a == b;
    })<<endl;
    
    cout<<"******************Car 2 noSoyPalindromo**********************"<<endl;

    cout<<is_palindrome(noSoyPalindromo,equalsCar)<<endl;


    return 0;

}

