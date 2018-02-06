//es lo maximo q pude hacer  si quieres ve no da crhasea al llamar a la funcion para calcular
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <fstream> 
#include <iomanip> 
#include <sstream>

using namespace std;


//###########################################ARBOL##################################


template <class T>
class ArbolExpre {
    struct Nodo {
    T data;
    ArbolExpre<T> izq;
    ArbolExpre<T> der;
    Nodo (T elem=T(), ArbolExpre<T> izq=ArbolExpre(), ArbolExpre<T> der=ArbolExpre()) {
        data=elem;
        izq=izq;
        der=der;
    }
    };
    Nodo * raiz; 
    public:
    ArbolExpre();
    ArbolExpre(const T &, const ArbolExpre<T> & arb=ArbolExpre(), const ArbolExpre<T> & ade=ArbolExpre());
    void update (const T & elem, const ArbolExpre<T> & izquierdo, const ArbolExpre<T> & derecho);
    void podar();
    ArbolExpre<T> copiarT();
    ArbolExpre<T> & izquierdo() const;
    ArbolExpre<T> & derecho() const;
    const T & datoRoot() const;
    T & datoRoot() ;
    bool isEmpty () const;
    void preorden() const;
};

        //impl
        template<class T>
        ArbolExpre<T>::ArbolExpre() {
            raiz=NULL;
        }

        template <class T>
        ArbolExpre<T>::ArbolExpre(const T & elem, const ArbolExpre<T> & izquierdo, const ArbolExpre<T> & derecho) {
            raiz= new Nodo(elem, izquierdo, derecho);
        }
        template <class T>
        void ArbolExpre<T>::update (const T & el, const ArbolExpre<T> & izquierdo, const ArbolExpre<T> & derecho) {
            if (!isEmpty()) {
                raiz->data=el;
                raiz->izq=izquierdo;
                raiz->der=derecho;
            }
                else cout << "El arbol esta vacio" << endl;
             }
        template <class T>
        void ArbolExpre<T>::podar() {
            if (!isEmpty()) {
                izquierdo().podar();
                derecho().podar();
                delete raiz;
            }
        }
        template <class T>
        ArbolExpre<T> ArbolExpre<T>::copiarT() {
            ArbolExpre i, d ;
            if (!isEmpty()) {
            if (!izquierdo().isEmpty()) i=izquierdo().copiarT();
            if (!derecho().isEmpty()) d=derecho().copiarT();
                ArbolExpre x (raiz->data, i, d);
                return x;
            }
        }
        template <class T>
            ArbolExpre<T> & ArbolExpre<T>::izquierdo() const {
            return raiz->izq;
        }
        template <class T>
            ArbolExpre<T> & ArbolExpre<T>::derecho() const {
            return raiz->der;
        }
        template <class T>
        const T & ArbolExpre<T>::datoRoot() const {
        
            return raiz->data;
        }
        template <class T>
            T & ArbolExpre<T>::datoRoot() {
            return raiz->data;
        }
        template <class T>
        bool ArbolExpre<T>::isEmpty () const {
            return (raiz==NULL);
        }
        template <class T>
        void ArbolExpre<T>::preorden() const {
            if (!isEmpty()) {
                cout << raiz->data << " ";
                izquierdo().preorden();
                derecho().preorden();
         }
        }
        bool isNumero (char a) {
        if (a=='*' || a=='/' || a=='-' || a=='+'){
            return false;
        }
        return true;
    }

//##########################################FIN ARBOL###########################33
    

//#################METODOS ###################################################3



ArbolExpre <char> addTreeChildExpre (string expresion,int len, int &pos){
    ArbolExpre<char> izq,der;
    if (pos<len) {
        if (!isNumero(expresion[pos])) {
        ArbolExpre<char> arb(expresion[pos]);
        pos++;
        izq = addTreeChildExpre (expresion,len,pos);
        pos++;
        der = addTreeChildExpre (expresion,len,pos);
        arb.update(arb.datoRoot(),izq,der);
        return arb;
    } else {
        return ArbolExpre<char> (expresion[pos],izq,der);
    }
    }
}


//#################FIN METODOS DE AYUDA##############################################################


    double calculateExpr (const ArbolExpre<char> &arbol) {
    if (arbol.izquierdo().isEmpty() && arbol.derecho().isEmpty()) {
        return arbol.datoRoot() - '0';
    } else {
            switch (arbol.datoRoot()) {
            case '=':
            return (calculateExpr(arbol.derecho()));
            break;
            case '+':
                return (calculateExpr(arbol.izquierdo()) + calculateExpr(arbol.derecho()));
            break;
            case '-':
                return (calculateExpr(arbol.izquierdo()) - calculateExpr(arbol.derecho()));
            break;
            case '/':
                return (calculateExpr(arbol.izquierdo()) / calculateExpr(arbol.derecho()));
            break;
            case '*':
                return (calculateExpr(arbol.izquierdo()) * calculateExpr(arbol.derecho()));
            break;
            
        }
    }
}



//##########################################INI###########################33
struct ICalculator{
    virtual double calculate(string expresion)=0;
};

struct calculator: public virtual ICalculator{
    int conNumbers = 0;
    int conSing = 0;
    int posi = 0;
    ArbolExpre <char> arb;

    double calculate(string expresion){
        string exp = (string)expresion;
        string aux;
        double numeros;
        string signos;
        
        stringstream input(exp);
        double res=-1;
        int len = expresion.length();
        arb = addTreeChildExpre(expresion,len,posi);
        posi++;
        //otra forma de parceo
         while(getline(input,aux,' ') || getline(input,aux,'(') || getline(input,aux,')') ){
            try{
                if(stod(aux.c_str())){
                    double d =  stod(aux.c_str());
                    numeros+=d;
                    conNumbers++;
                    cout<<" num: "<<numeros<<endl;
                    
                }
            }catch(...){
                signos+=aux+" ";
                conSing++;
                cout<<"sig: "<<signos<<endl;
                              
            }
        } 
        //de esta forma parceso cada numero y signo dependiendo
        cout<<"sig: "<<signos<<" num: "<<numeros<<endl; 
        res = calculateExpr(arb);
        return res > 0 ? res : 0;
    }

};

void eval(calculator &c, const string &  expre){

    c.calculate(expre);
}
//##########################################FIN###########################33


int main(){


    calculator c;
    eval(c, "2 + 5");//7
    cout<<"******************************"<<endl;
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
    cout<<"******************************"<<endl;
    
   

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