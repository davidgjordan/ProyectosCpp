#include <iostream>
#include <cstring>
#include <string>

 using namespace std;



class binary{
    char num;

    // char getNum(const string &s);
private:
    // constructor privado
    binary( char n):num{n}{

    }

    public :
    binary(const string &s) :num{getNum(s)}{
        // cuando me pase una cadena transformarlo a binario

    }
    char getNum(const string &s){
        char n = 0;
    
        for(auto k : s){
            n*=2;
            n+= k=='1' ? 1:0;
        }
        return n;
    }

    char get_decimal()const{
        return num;
    }


    // sobrecargamos el operador mas es constante
    /* void operator+( const binary &p) const {
        binary b{(char)(num+p.num )};
        return b;
    } */

    binary & operator+=( const binary &b){
        num += b.num;
        return *this;
    }
    string get_binary(){
        string r;
        int x= num;
        while(x){
            auto mod = x%2;
            char k = mod ? '1':'0';
            r.insert(r.begin(), k);
            x/=2;
        }

        return r;
    }
};







 int main(){
 

binary b3 {"0000"};
b3 += binary{"0001"};

cout<<b3.get_binary()<<endl;



return 0;

}


