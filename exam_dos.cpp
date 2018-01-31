#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <fstream> 
#include <iomanip> 
#include <sstream>//




using namespace std;

//*****************INI PILA*************************************
struct NodePila{//para guardar los numeros 
    double data;
    NodePila * siguiente;
    NodePila(double sdata, NodePila *snode =nullptr):data{sdata}, siguiente{snode}{
    }
    public:
    ~NodePila(){
    }
    friend class Pila;
};

class Pila{
    public:
    NodePila * ultimo = nullptr;
    public:
    void push(double data){
        auto n = new NodePila(data,ultimo );
        ultimo = n;
        cout<<"push"<<endl;
    }

    double pop(){
        if(!ultimo)return 0;
        auto aux = ultimo;
        double data = aux->data;
        ultimo = ultimo->siguiente;
        delete aux;
        cout<<"pop"<<endl;
        
        return data;
    }
};
//*****************FIN PILA*************************************

enum class ECalculatorType{
    RPN,
    DEFAUL,
    BLUE
};
class IOperator{
};
class IOperatorBinario : public virtual IOperator{
  public:  virtual double eval(double &a, double &b)=0;
};
class IOperatorUnario : public virtual IOperator{
  public:  virtual double eval(double &a)=0;    
};
class OperatorAdd :public virtual IOperatorBinario{
     public:
     double eval(double &a, double &b){
         return a+b;
     }    
};
class OperatorMul :public virtual IOperatorBinario{
     public:
     double eval(double &a, double &b){
         return a*b;
     }    
};
class OperatorResta :public virtual IOperatorBinario{
     public:
     double eval(double &a, double &b){
         return a-b;
     }    
};
class OperatorDiv :public virtual IOperatorBinario{
     public:
     double eval(double &a, double &b){
         return a/b;
     }    
};
class OperatorMax:public virtual IOperatorBinario{
    public:
     double eval(double &a, double &b){
         return a>b?a:b;
     }    
};
class OperatorInc :public virtual IOperatorUnario{
     public:
     double eval(double &a){
         return a++;
     }    
};
class OperatorSqrt :public virtual IOperatorUnario{
     public:
     double eval(double &a){
         return sqrt(a);
     }    
};


//*****************INI PILA*************************************
class NodeLis{
public:
    string key;
    IOperator * operatorE;
    NodeLis * anterior;
    NodeLis * siguiente;
    ~NodeLis(){
    }
};
    
struct ListaOperadoresExistentes{
    NodeLis * first= nullptr;
    NodeLis * last= nullptr;
    public:
    ListaOperadoresExistentes(){}
    ~ListaOperadoresExistentes(){
        auto aux = first;
 		while(aux){
 			auto next = aux->siguiente;
             aux->key = nullptr;
             aux = nullptr;
 			aux = next;
 		}
         
    }
     void add_front(string nkey, IOperator * operatorE){
        auto n = new NodeLis{nkey,operatorE, nullptr, nullptr};
        if(first == nullptr){
            first = last = n;
        }else{
            n->siguiente = first;
            first->anterior = n;
            first = n;
        }
    }

    bool existe(string& nkey){
        auto n = first;
        if(n==nullptr){
            return false;
        }
        while(n){
            if(n->key.compare(nkey) == 0){
                return true;
            }
            n = n->siguiente;
        }
    }
};
//

class ICalculator{
    public:
    virtual double eval(const string& exprexion)=0;
    virtual void add_operator(string & key, IOperator)=0;
};

class CalculatorRPN : public virtual ICalculator{
Pila pila ;
public:
    //double num2 = std::stod(auxChar2);
    double eval(const string& exprexion){
        string exp = (string)exprexion;
        string aux;
        stringstream input(exp);
        while(getline(input,aux,' ')){
            double d =  stod(aux);
            if(d){
                cout<<"entre"<<d<<endl;
                pila.push(d);
            }
            aux ="";
        }

    
        // if(getline(input_stringstream,parsed,' '))
        // {
        //     // do some processing.
        // }
            cout<<pila.ultimo->data<<endl;
        showp();

    }  

    void showp(){
       // while(pila.ultimo){
        //}
    }

    void add_operator(string & key, IOperator){

    }
};

class CalculatorFactory{
public:
   
    ICalculator *  create_calculator(const ECalculatorType type){
        if(type == ECalculatorType::RPN ){
            return new CalculatorRPN();
        }
        return nullptr;
    }
};

void show(double res){
    cout<<res<<endl;
}


int main()
{
        CalculatorFactory cf;
        ICalculator* calc = cf.create_calculator(ECalculatorType::RPN);
        show(calc->eval("2 3 +")); // 5
        //calc->showp();
        
/* int main()
{
        CalculatorFactory cf;
        ICalculator* calc = cf.create_calculator(CalculatorType::RPN);

        show(calc->eval("2 3 +")); // 5
        show(calc->eval("100 12.5 13.7 * -")); // 67.825
        show(calc->eval("5 6 7 8 + - * 5 +")); // 50
        show(calc->eval("6 inc")); // [Error: operator 'inc' unknown]
        show(calc->eval("7 2 max")); // [Error: operator 'max' unknown]
        show(calc->eval("7 *")); // [Error: no operand found for '*']
        show(calc->eval("+")); // [Error: no operand found for '+']
        show(calc->eval("abc")); // [Error: operator 'abc' unknown]
        show(calc->eval("12x6")); // [Error: syntax error]

        calc->add_operator("inc", new IncOperator());
        calc->add_operator("max", new MaxOperator());
        calc->add_operator("sqrt", new SqrtOperator());

        show(calc->eval("10 5 max inc")); // 11
        show(calc->eval("25.8 63 max inc sqrt")); // 8
} */
}