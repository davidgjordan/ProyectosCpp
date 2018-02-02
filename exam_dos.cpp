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
    friend class LL;\
};\
class LL{\
    public:\
    LL(){}\
     LL##NodePila * ultimo = nullptr;\
    public:\
    void push(T data){\
        auto n = new LL##NodePila(data,ultimo);\
        ultimo = n;\
    }\
    T pop(){\
        if(!ultimo)return 0;\
        auto aux = ultimo;\
        T data = aux->data;\
        ultimo = ultimo->siguiente;\
        delete aux;\
        return data;\
    }\
};
//*****************FIN COLA*************************************
# define  COLA(T, LL)\
class LL##node{\
    public:\
     T data;\
     LL##node * siguiente;\
    public:\
     LL##node(T sdata, LL##node * ssig = nullptr):data{sdata},siguiente{ssig}{\
     }\
     ~LL##node(){}\
     friend class LL;\
};\
class LL{\
public:\
    LL##node * primero;\
    LL##node * ultimo;\
    public:\
    LL():primero{nullptr}, ultimo{nullptr}{\
    }\
    ~LL(){\
    }\
    void push(T sdata){\
        auto n = new LL##node(sdata);\
        if(ultimo){\
            ultimo->siguiente = n;\
        }\
        ultimo = n;\
        if(!primero){\
            primero = n;\
        }\
    }\
    T pop(){\
        auto n = primero;\
        if(!n)return 0;\
        primero = primero->siguiente;\
        auto data = n->data;\
        delete n;\
        if(!primero) ultimo = nullptr;\
        return data;\
    }\
};



enum class CalculatorType{
    RPN,
    DEFAUL,
    CIENTIFIC
};
enum class OperatorType{
    BINARY,
    UNARI
};
class IOperator{
    public:
    virtual OperatorType getTipo()=0;
};
class OperatorBinario : public virtual IOperator{
  public: virtual double eval(double &a, double &b){
      return a+b;
  }
  OperatorType getTipo(){
      return OperatorType::BINARY;
  }
  ~OperatorBinario(){}
};
class OperatorUnario : public virtual IOperator{
  public:  
    virtual double eval(double &a){
      return a++;
  }
   OperatorType getTipo(){
      return OperatorType::UNARI;
  }
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
class MaxOperator:public virtual OperatorBinario{
    public:
     double eval(double &a, double &b){
         return a>b?a:b;  

     }    
};
class IncOperator :public virtual OperatorUnario{
     public:
     double eval(double &a){
         return ++a;
     }    
};
class SqrtOperator :public virtual OperatorUnario{
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
    virtual void add_operator(const string & key, IOperator* oper)=0;
};

PILA(double, PilaNumbers)
COLA(string, ColaOperator)
class CalculatorRPN : public virtual ICalculator{
    PilaNumbers  pilanumbers;
    ColaOperator colaoperator;
    ListaOperadoresExistentes listaOper;
    int conN= 0;
    int conO= 0;
    public:
        CalculatorRPN(){
            listaOper.push("+", new OperatorAdd());
            listaOper.push("-", new OperatorResta());
            listaOper.push("*", new OperatorMul());
            listaOper.push("/", new OperatorDiv());
        }
        //double num2 = std::stod(auxChar2);
     double eval(const string& exprexion){
         
         while(pilanumbers.ultimo != nullptr){
            pilanumbers.pop();
        }
        while(colaoperator.primero != nullptr){
            colaoperator.pop();
        }
        //cout<<"entre"<<endl;
        string exp = (string)exprexion;
        string aux;
        stringstream input(exp);
        double res=-1;
        
        while(getline(input,aux,' ')){
            try{
                if(stod(aux.c_str())){
                    double d =  stod(aux.c_str());
                    //cout<<"pilanumbers: "<<d<<endl;
                    pilanumbers.push(d);
                    conN++;
                }
            }catch(...){
                colaoperator.push(aux);  
                conO++;              
                //std::cout << "colaoperator"<<aux<< '\n'; 
                res = calculate();            
            }
          
        }          
        //cout<<"sali"<<endl;        
        //print();
        return res;
       
    } 

    void print(){
        while(pilanumbers.ultimo != nullptr){
            double d = pilanumbers.pop();
            cout<<"n: "<<d<<" - " ;
        }
        cout<<endl;
        while(colaoperator.primero != nullptr){
            string d = colaoperator.pop();
            cout<<"o: "<<d<<" - " ;
        }
    } 
    double calculate(){
            
        double res=-1;        
        //std::cout << "calculate 1: "<</* pilanumbers.pop()<< */ '\n'; 
        while(colaoperator.primero && pilanumbers.ultimo){
            //std::cout << "calculate 2: "<</* pilanumbers.pop()<< */ '\n';             
            string key = colaoperator.pop();
            //std::cout << "calculate 3: "<</* pilanumbers.pop()<< */ '\n';                             
            //cout<<key<<endl;
            if(listaOper.existe(key)){
                IOperator * oper = listaOper.getOp(key);
                //std::cout << "calculate 4: "<</* pilanumbers.pop()<< */ '\n';                             
                if(oper->getTipo() == OperatorType::UNARI){
                    OperatorUnario * operUna = dynamic_cast<OperatorUnario *>(oper);
                    double data = pilanumbers.pop();
                    res = operUna->eval(data);
                    pilanumbers.push(res);
                    //cout<<"unari: "<<res<<endl;
                }else if(pilanumbers.ultimo->siguiente ){
                    //validar en caso de que no haya dos pop
                    double a = pilanumbers.pop();
                    double b = pilanumbers.pop();
                    OperatorBinario * operBinar = dynamic_cast<OperatorBinario *>(oper);
                    res = operBinar->eval(a, b);
                    pilanumbers.push(res);                        
                    //cout<<"binary: "<<res<<endl;                        
                }

            }else{

                cout<< "[Error: operator "<<"\'"<<key<<"\'"<<" unknown]"<<endl;
                res = -1;    
                break;
            }
        }
        return res;
    }
    void add_operator(const string & key, IOperator *oper){
        //cout<<oper->getTipo()<<endl;
        listaOper.push(key, oper);
    }
};

class CalculatorFactory{
public:

    ICalculator *  create_calculator(const CalculatorType type){
        if(type == CalculatorType::RPN ){
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