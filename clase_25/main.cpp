//Array list

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//la siguiente apartir de template sera una funcion solo una funcion
template <typename T>//se puede poner clase igual en ves de typename  ESTE TEMPLATE TODO EN UNA SOLA CLASE TIENE Q ESTAR
class ArrayList{

    T * data;
    size_t n;
    size_t c;


public:
    ArrayList():data{new T[4]}, n{0},c{4}{

    }

    ~ArrayList(){
        delete []data;
    }

    ArrayList & add(const T & x){
        if(n==c) resize();

        data [n++] = x;//se llama a su operador igual del tipo T   pero si no tendriamos 
        return *this;
    } 

    size_t size() const noexcept{
        return n;
    }

    T& operator [](size_t i) const noexcept{
        return data[i];
    }

    ArrayList & add(T && x){ //para el caso del 50 donde el objeto se destruyeese rato
    
        if(n==c)resize();
        data[n++] = std::move(x);
        return * this;
    
    }

private:
    void resize(){
        auto nc = c*2;
        auto nd = new T[nc];

        for (size_t i = 0U; i < n; i++)
        {
//            nd[i] = data[i];//aqui podriamos mover enves de copiar 
            nd[i] = std::move(data[i]);//aqui podriamos mover enves de copiar 
        }

        delete [] data;
        data = nd;
        c= nc;
    }

};


class P {
    int n;

public:
    P(int n=0):n(n){
        cout<<"constructor: "<<n<<endl;
    }

    P(const P& p):n(p.n){
        cout<<"copy constructor: "<<n<<endl;
    }
    P& operator=(const P& p){
        cout<<"opeator =: "<<n<<endl;
        
        n = p.n;
        return *this;
    }

    P(P && p):n(p.n){
        cout<<"Move constructor: "<<n<<endl;
    }

    P& operator=(P&& p){//el && te pide un r-value y este si puede cambiar el valor
        n = p.n;
        cout<<"Move ="<<n<<endl;  
        return *this;
    }
};

int main(){
    ArrayList <int> x;//en este punto se crea esta clase y todos los metodos q se estan utilizando
    x.add(5).add(10).add(11).add(12).add(13).add(15).add(16);
/* 
    for (size_t i = 0; i < x.size(); i++)
    {
        cout<<x[i]<<endl;
    }

 */


    ArrayList <string> y;//en este punto se crea esta clase y todos los metodos q se estan utilizando
    y.add("dsfsad5").add("10dsfsad").add("11dsfsad").add("12dsfsad").add("13dsfsad").add("15dsfsad").add("16dsfsad");

    /* for (size_t i = 0; i < y.size(); i++)
    {
        cout<<y[i]<<endl;
    } */

    cout<<"*********************************************"<<endl;
    ArrayList<P> ps;
    P p1{10};
    P p2{11};
    P p3{13};
    P p4{14};
    P p5{15};
    ps.add(p1).add(p2).add(p3).add(40).add(50).add(P{50});


    return 0;



 }