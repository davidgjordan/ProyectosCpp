//EJERCICIOS
#include <unordered_map>//esta es la libreria

//el unorder set es una tabla hash// el set es un arbol binario de busqueda
#include <iostream>
#include <string>
#include <cstring>
#include <vector> 
#include <algorithm> 
#include <fstream> 
#include <set> 
#include <map> 
#include <list>

#include <iostream>
#include <string>
#include <cstring>
#include <vector> 
#include <fstream> 
#include <iomanip> 


#include <sstream>// 
using namespace std;

struct operator_info{
    double ( * unary)(double) = nullptr;//recive un double y devuelve un double
    double ( * binary)(double, double) = nullptr;//recive un double y devuelve dos  doubles
};



class rpn_calculator{
    map<string, operator_info> ops;

    public:
        rpn_calculator(){
            add_binary("+", [](auto a,auto b ){return a+b;});
            add_binary("-", [](auto a,auto b ){return a-b;});
            add_binary("*", [](auto a,auto b ){return a*b;});
            add_binary("/", [](auto a,auto b ){
                if(b==0)
                throw "division a cero";
                return a/b;
                });
        }
    void add_binary(string opn, double(*p)(double, double)){
        ops[opn].binary = p;//todo esto me devuelve una referencia a un campo 
    }
    void add_unary(string opn, double(*p)(double)){
        ops[opn].unary = p;//todo esto me devuelve una referencia a un campo 
    }
    double eval(string exp)const{

        list<double> stack;
        istringstream iss{exp};//por defecto separa po un espacio las palabras
        string token;
        while(iss>>token){//cuando ya no haydatos deveulve false
            double num;
            bool valid_num = is_valid(token, num);//2
            if(valid_num){
                stack.push_back(num);
                continue;
            }
            auto it = ops.find(token);//1
            if(it == ops.end()){
                throw "unknow operator";
            }

            process(stack, it->second);
        }

        if(stack.empty()){
            throw "syntax error";
        }if(stack.size() != 1){
            throw "sintax error";
        }

        return stack.front();
    }

    bool is_valid(const string & token, double & num )const{
        try{
            num = stod(token);
            return num;
        }catch(...){
            return false;
        }

    }

    void process(list<double>& stack, const operator_info & op)const{
        if(op.unary != nullptr){
            if(stack.size() < 1 ) throw "syntax error";
            auto val = stack.back();
            stack.pop_back();
            auto nval = op.unary(val);
            stack.push_back(nval);
            return;
        }
        if(stack.size() < 2 ) throw "syntax error";
        auto a = stack.back(); stack.pop_back();
        auto b = stack.back(); stack.pop_back();

        auto nval = op.binary(a,b);
        stack.push_back(nval);
    }
};



void eval(const rpn_calculator calc, string exp){
    try{
        cout<<calc.eval(exp)<<endl;
    }catch(const char * m){
        cerr<<"error "<<m<<endl;
    }
}

int main(){


rpn_calculator calc;
calc.add_unary("inc", [](auto  x){
    return x+1;
});

calc.add_binary("max", [](auto  a, auto  b){
    return a>b?a:b;
});


eval(calc, "5 6 +");
eval(calc, "6 8 5 + *");
eval(calc, "12.5 inc");
eval(calc, "5 8 max inc 2 +");
eval(calc, "hola");
eval(calc, "");
eval(calc, "+"); 






    return 0;
}
