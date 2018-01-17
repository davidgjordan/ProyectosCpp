#include <iostream>
#include <cstring>
#include <string>
//#include <math>

using namespace std;


/* RPN 
REVERSE POLICH NOTATION   SQRT(2)
 */
class IOperator{
};
class OperatorEspecial:public virtual IOperator{
public:
    ~OperatorEspecial(){}
    virtual double operar(double numAopertar) const =0;
};

class OperatorNormal:public virtual IOperator{
public:
    ~OperatorNormal(){} 
    virtual double operar(double numAopertar1, double numAopertar2,  char  signo) const =0;
};




class ICalculator{
public:
    ~ICalculator(){} //
    virtual void add_operator(const char * name , OperatorEspecial * newOperator)const = 0;
    virtual double eval(const char *expresion)const =0;
};


class IncOperator: public virtual OperatorEspecial{
public:
     double operar(double numAopertar) const override{
         numAopertar++; 
        return numAopertar;
     }
};

class MaxOperator: public virtual OperatorNormal{ 
public: 
     double operar(double numAopertar1, double numAopertar2,  char  signo)const override {
         
        return numAopertar1 > numAopertar2 ? numAopertar1:numAopertar2;
     }
};

class SqrtOperator: public virtual OperatorEspecial{
public:
     double operar(double numAoperar) const override{
         //este solo saca la raiz y la devuelve
        //return std::sqrt(numAoperar);
        return 4;
     }
};

class DefaultOperator: public virtual OperatorNormal{
public:
     double operar(double numAoperar1, double numAoperar2, char  signo) const override{
        //ESTA CLASE es para operar con sumas o restas o lo q sea segun el signo
        double res = 0;
        switch(signo){
            case '+':
                res =  numAoperar1 +numAoperar2;
            break;
            case '-':
                res =  numAoperar1 -numAoperar2;
                break;
            case '*':
                res = numAoperar1 *numAoperar2;
            break;
            case '/':
                res = numAoperar1 /numAoperar2;
            break;
        }
        return res;
     }
};




//*****************INI PILA*************************************
class NodePila{//para guardar los numeros 
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
    NodePila * ultimo = nullptr;
    public:
    void push(const double data){
        auto n = new NodePila(data,ultimo );
        ultimo = n;
    }

    double pop(){
        if(!ultimo)return 0;
        auto aux = ultimo;
        double data = aux->data;
        ultimo = ultimo->siguiente;
        delete aux;
        return data;
    }
};
//*****************FIN PILA*************************************



//*****************INI PILA*************************************
class NodeLis{
public:
    char * data;
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
             aux->data = nullptr;
             aux = nullptr;
 			aux = next;
 		}
         
    }

     void add_front(const char * ndata, OperatorEspecial * operatorE){
        auto n = new NodeLis{(char *)ndata,operatorE, nullptr, nullptr};
        if(first == nullptr){
            first = last = n;
        }else{
            n->siguiente = first;
            first->anterior = n;
            first = n;
        }
    }

    bool existe(const char * rdata){
        auto n = first;
        if(n==nullptr){
            return false;
        }
        while(n){
            if(strcmp(n->data, (char *)rdata) == 0){
                return true;
            }
            n = n->siguiente;
        }
    }
};
//*****************finPILA*****para guardar los operadores

class CalculatorType{
    public://CLASS FALLANDO NO SE COMO ASIGNAR UNA VARIABLE ESTATICA
    const static int RPN = 0;//calculadora RPN
    };
    

class CalculatorRPN : public virtual ICalculator{
public:
    Pila pila; //apilo los numeros
    IOperator * oper; //instancio segun me den en el add operator y anado a mi lista
    ListaOperadoresExistentes * lista;

    CalculatorRPN(){
        oper = new DefaultOperator();
    }
    
     void add_operator(const char * name , OperatorEspecial * newOperator)const override{
         //lista->add_front(name,newOperator);

    }
     double getnumber(){

    }
    double eval(const char *expresion)const override{
        auto len = strlen(expresion);
        char * aux = new char[len+1];
        strcpy(aux , expresion);

        char * c = strtok(aux," ");

        cout<<c<<" palabra "<<endl;
        if((int)(*c) >=48 && (int)(*c) <= 57){
            int num = *c - '0';
            double numd = (double)num;
            //double numd = 9.9;
            //pila.push(numd);
            //no se pudee castear char * a  double
            //y peor q el internet no da
            //cout<<numd<<endl;   
        }  
        while(c != nullptr){
            c = strtok(nullptr, " ");
            cout<<c<<endl;
            //pila.push(numd);
            
        }
        return 0.1;
    }
};

class CalculatorFactory{
public:
    ICalculator *cal;
    ICalculator *  create_calculator(const int type){
        if(type == 0 ){
            cal = new CalculatorRPN();
            return cal;
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
        ICalculator* calc2 = cf.create_calculator(CalculatorType::RPN);
        ICalculator *calc = new CalculatorRPN();//DIGAMOS Q EL  cf.create_calculator YA ME DEVOLVIO UNA ISNTANCIA DE CalculatorRPN
        
        show(calc->eval("2 3 +")); // 5
        show(calc->eval("100 12.5 13.7 * -")); // 67.825
        show(calc->eval("5 6 7 8 + - * 5 +")); // 50
        show(calc->eval("6 inc")); // [Error: operator 'inc' unknown]
        show(calc->eval("7 2 max")); // [Error: operator 'max' unknown]
        show(calc->eval("7 *")); // [Error: no operand found for '*']
        show(calc->eval("+")); // [Error: no operand found for '+']
        show(calc->eval("abc")); // [Error: operator 'abc' unknown]
        show(calc->eval("12x6")); // [Error: syntax error]

        
        //constante
        //evaluar
        /*    
        show(calc->eval("5 6 7 8 + - * 5 +")); // 50
        show(calc->eval("6 inc")); // [Error: operator 'inc' unknown]
        show(calc->eval("7 2 max")); // [Error: operator 'max' unknown]
        show(calc->eval("7 *")); // [Error: no operand found for '*']
        show(calc->eval("+")); // [Error: no operand found for '+']
        show(calc->eval("abc")); // [Error: operator 'abc' unknown]
        show(calc->eval("12x6")); // [Error: syntax error]
        
        calc->add_operator("inc", new IncOperator()); //incrementa 
        calc->add_operator("max", new MaxOperator()); //da el valor maximo
        calc->add_operator("sqrt", new SqrtOperator()); //raiz cuadrada

        show(calc->eval("10 5 max inc")); // 11  inc  
        show(calc->eval("25.8 63 max inc sqrt")); // 8 */
}