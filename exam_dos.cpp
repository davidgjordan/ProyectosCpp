#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <fstream> 
#include <iomanip> 
#include <sstream>//




using namespace std;

//*****************INI PILA*************************************
# define  PILA(T, LL)\
struct LL##NodePila{\
    T data;\
    LL##NodePila * siguiente;\
    LL##NodePila(T sdata, LL##NodePila *snode =nullptr):data{sdata}, siguiente{snode}{\
    }\
    public:\
    ~LL##NodePila(){\
    }\
    friend class Pila;\
};\
class LL{\
    public:\
    LL(){}\
     LL##NodePila * ultimo = nullptr;\
    public:\
    void push(T data){\
        auto n = new LL##NodePila(data,ultimo );\
        ultimo = n;\
        cout<<"push"<<endl;\
    }\
    T pop(){\
        if(!ultimo)return 0;\
        auto aux = ultimo;\
        T data = aux->data;\
        ultimo = ultimo->siguiente;\
        delete aux;\
        cout<<"pop"<<endl;\
        return data;\
    }\
};
//*****************FIN PILA*************************************

enum class ECalculatorType{
    RPN,
    DEFAUL,
    BLUE
};
class IOperator{
};
class OperatorBinario : public virtual IOperator{
  public:  virtual double eval(double &a, double &b)=0;
  ~OperatorBinario(){}
};
class OperatorUnario : public virtual IOperator{
  public:  virtual double eval(double &a)=0;
  ~OperatorUnario(){} 
};
class OperatorAdd :public virtual OperatorBinario{
     public:
     double eval(double &a, double &b){
         return a+b;
     }    
};
class OperatorMul :public virtual OperatorBinario{
     public:
     double eval(double &a, double &b){
         return a*b;
     }    
};
class OperatorResta :public virtual OperatorBinario{
     public:
     double eval(double &a, double &b){
         return a-b;
     }    
};
class OperatorDiv :public virtual OperatorBinario{
     public:
     double eval(double &a, double &b){
         return a/b;
     }    
};
class OperatorMax:public virtual OperatorBinario{
    public:
     double eval(double &a, double &b){
         return a>b?a:b;
     }    
};
class OperatorInc :public virtual OperatorUnario{
     public:
     double eval(double &a){
         return a++;
     }    
};
class OperatorSqrt :public virtual OperatorUnario{
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
     void push(string nkey, IOperator * operatorE){
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
        return false;
    }

    IOperator * getOp(string& nkey ){
        auto n = first;
        if(n==nullptr){
            return nullptr;
        }
        while(n){
            if(n->key.compare(nkey) == 0){
                return n->operatorE;
            }
            n = n->siguiente;
        }
        return nullptr;
    }
};
//

class ICalculator{
    public:
    virtual double eval(const string& exprexion)=0;
    virtual void add_operator(string & key, IOperator*)=0;
};

PILA(double, PilaNumbers)
PILA(string, PilaOperator)
class CalculatorRPN : public virtual ICalculator{
    PilaNumbers  pilanumbers;
    PilaOperator pilaoperator;
    ListaOperadoresExistentes lsoper;
    public:
        CalculatorRPN(){
            lsoper.push("+", new OperatorAdd());
            lsoper.push("-", new OperatorResta());
            lsoper.push("*", new OperatorMul());
            lsoper.push("/", new OperatorDiv());
        }
        //double num2 = std::stod(auxChar2);
        double eval(const string& exprexion){
             string exp = (string)exprexion;
         string aux;
         stringstream input(exp);
         while(getline(input,aux,' ')){
             try{
                 if(stod(aux)){
                     double d =  stod(aux);
                     cout<<"pilanumbers: "<<d<<endl;
                     //double d = stod(aux);
                     pilanumbers.push(d);
                }
             }catch(...){
                 pilaoperator.push(aux);                
                 std::cout << "pilaoperator "<<aux << '\n'; 
             }
             //aux ="";
         }
        double res;
        while(pilaoperator.ultimo){
            string key = pilaoperator.pop();
            if(lsoper.existe(key)){
                IOperator * oper = lsoper.getOp(key);
                OperatorBinario * operBinary = dynamic_cast<OperatorBinario *>(*(&oper));

            }else{
                cout<< "[Error: operator "<<"\'"<<key<<"\'"<<" unknown]"<<endl;
                res = -1;    
            }
        }
        return res;
    }  

    void add_operator(string & key, IOperator *oper){
        lsoper.push(key, oper);
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

        /* Pila p;
        p.push(5);
        p.push(53);
        p.push(51);
        p.push(4);


        while(p.ultimo){
            cout<<p.pop()<<endl;
       } */

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