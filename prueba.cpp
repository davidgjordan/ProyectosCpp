//ay creo ya implementaciones de arboles de expresiones en internet trata de copiarte
//alguna y compila o trata de arreglar sobre eso
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <fstream> 
#include <iomanip> 
#include <sstream>//

using namespace std;


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

/* template<class T>
struct Arbol{
    Node<T> *root;
    Node<T> *actual;
    
    void podar(Node<T> *& nodo){
        if(nodo){
            podar(nodo->izq);
            podar(nodo->izq);
            delete nodo;
            nodo=nullptr;
        }
    }

    void add(T data){

        Node<T> *nn;
        Node<T> *padre = nullptr;
        actual = root;

        nn = new Node<T>(data);
//        while(!vacio(actual) && )

    }

    bool vacio(Node<T> * root){
        return root ==nullptr;
    }

}; */

struct ICalculator{

};

struct calculator: public virtual ICalculator{

    int conN = 0;
    int conO = 0;
    void calculate(string expresion){
        //cout<<"entre"<<endl;
        string exp = (string)expresion;
        string aux;
        double numeros;
        string signos;
        stringstream input(exp);
        double res=-1;
        //de esta forma parceso cada numero y signo dependiendo
        while(getline(input,aux,' ')){
            try{
                if(stod(aux.c_str())){
                    double d =  stod(aux.c_str());
                    //pilanumbers.push(d); pusheo al arbol
                    numeros+=d;
                    conN++;
                }
            }catch(...){
                signos+=aux+" ";
                //colaoperator.push(aux);  pusheo al arbol pero como expresion
                conO++;              
                //std::cout << "colaoperator"<<aux<< '\n'; 
                //res = calculate();            
            }
          
        } 
        //de esta forma parceso cada numero y signo dependiendo
        cout<<"sig: "<<signos<<" num: "<<numeros<<endl;
    }
};

void eval(calculator &c, const string &  expre){

    c.calculate(expre);
}

int main(){


    calculator c;
    eval(c, "2 + 5");//7


    return 0;
}
/* 
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
  */