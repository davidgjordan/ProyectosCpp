//o tambien si no reutiliza el arbol q hicimos y su data del nodo seria tipo
//t algo asi mas o menos ya q puedes pushear al arbol numeros o signos
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
struct ICalculator{

};
struct calculator: public virtual ICalculator{
    void calculate(string expresion){

    }
};

template<class T>
class Node
{
  public:
    T *data;
    Node *izq;
    Node *der;
  public:
    Node(T *data, Node *izq = nullptr, Node *der = nullptr) : data{data}, izq{izq}, der{der} {}
};

template<class T>
struct Arbol{
    Node<T> *root;
    Node<T> *actual;


};

void eval(calculator c, string &  expre){
    c.calculate(expre);
}

int main(){


    calculator c;
    eval(c, "2 + 5");


    return 0;
}

 int main()
{
    calculator c;
    eval(c, "2 + 5"); //7
    eval(c, "5 / 0"); //[Error: divide by zero]
    eval(c, "a = 4"); //4
    eval(c, "6 - a"); //2
    eval(c, "b = 5 + a"); //9
    eval(c, "(3 + b) / a"); //3
    eval(c, "6 *"); //syntax error
    eval(c, "1 + 2 * 3"); //7
    eval(c, "(++a) + 5"); //9
    eval(c, "a + b"); //14
    eval(c, "b++"); //9
    eval(c, "((1 + 5 + b) * (6 + a)) / 2"); // 88
    eval(c, "d"); //'d' undefined
    eval(c, "lastresult"); // 88
    return 0;
}
 