//ANDA A LA LINEA 292

#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <fstream> 
#include <iomanip> 
#include <sstream>//

using namespace std;


//###########################################ARBOL##################################

template <class T>
class ArbolExpre {
    public:
    ArbolExpre();

    //crea un nuevo arbol binario a partir de un elemento y dos arboles binarios
    ArbolExpre(const T & e, const ArbolExpre<T> & ai=ArbolExpre(), const ArbolExpre<T> & ad=ArbolExpre());

    //modifica un ArbolExpre poniendo e como raiz e izqdo y dcho como hijo izquierdo
    // y derecho respectivamente
    void modificar (const T & e, const ArbolExpre<T> & izqdo, const ArbolExpre<T> & dcho);

    //modica el arbol actual hasta obtener el ArbolExpre vacio
    void vaciar();

    //Copia el arbol binario actual
    ArbolExpre<T> copiar();

    //Devuelve el subarbol izquierdo del &#65533;rbol, NULL si est&#65533; vac
    ArbolExpre<T> & izquierdo() const;

    //Devuelve el subarbol derecho del &#65533;rbol, NULL si est&#65533; vac
    ArbolExpre<T> & derecho() const;
    //Devuelve el elemento de la raiz
    const T & datoraiz() const;
    T & datoraiz() ;

    //Indica si el &#65533;rbol binario est&#65533; vacio
    bool esvacio () const;

    //recorre el arbol en preorden
    void preorden() const;

    //muestra el arbol en notacion infija
    string notacion_infija() const;

    //Comprueba que el ArbolExpre es extendido
    bool esExtendido () const;

    private:
    //nodo del arbol binario
    struct Nodo {
    T data;
    ArbolExpre<T> izq;
    ArbolExpre<T> der;

//constructor
    Nodo (T e=T(), ArbolExpre<T> iz=ArbolExpre(), ArbolExpre<T> de=ArbolExpre()) {
        data=e;
        izq=iz;
        der=de;
}
};

Nodo * raiz; //puntero a la raiz del &#65533;rbol binario
};

//IMPLEMENTACIONES
//construye un arbol binario vacio
        template<class T>
        ArbolExpre<T>::ArbolExpre() {
            raiz=NULL;
        }
        
        //crea un nuevo arbol binario a partir de un elemento y dos arboles binarios
        template <class T>
        ArbolExpre<T>::ArbolExpre(const T & e, const ArbolExpre<T> & izqdo, const ArbolExpre<T> & decho) {
            raiz= new Nodo(e, izqdo, decho);
        }
        
        
        //modifica un ArbolExpre poniendo e como raiz e izqdo y dcho como hijo izquierdo
        // y derecho respectivamente
        template <class T>
        void ArbolExpre<T>::modificar (const T & e, const ArbolExpre<T> & izqdo, const ArbolExpre<T> & dcho) {
            if (!esvacio()) {
                raiz->data=e;
                raiz->izq=izqdo;
                raiz->der=dcho;
            }
            else cout << "Error: arbol binario vacio" << endl;
             }
        //modica el arbol actual hasta obtener el ArbolExpre vacio
        template <class T>
        void ArbolExpre<T>::vaciar() {
            if (!esvacio()) {
                izquierdo().vaciar();
                derecho().vaciar();
                delete raiz;
            }
        }
        
        
        //Copia el arbol binario actual
        template <class T>
        ArbolExpre<T> ArbolExpre<T>::copiar() {
            ArbolExpre i, d ;
            if (!esvacio()) {
            if (!izquierdo().esvacio()) i=izquierdo().copiar();
            if (!derecho().esvacio()) d=derecho().copiar();
        //raiz=new Nodo(raiz->data, i, d);
        //return raiz;
                ArbolExpre x (raiz->data, i, d);
                return x;
            }
        }
        
        //Devuelve el subarbol izquierdo del &#65533;rbol, NULL si est&#65533; vac
        template <class T>
            ArbolExpre<T> & ArbolExpre<T>::izquierdo() const {
            return raiz->izq;
        }
        
        //Devuelve el subarbol derecho del &#65533;rbol, NULL si est&#65533; vac
        template <class T>
            ArbolExpre<T> & ArbolExpre<T>::derecho() const {
            return raiz->der;
        }
        //Devuelve el elemento de la raiz
        template <class T>
        const T & ArbolExpre<T>::datoraiz() const {
        
            return raiz->data;
        }
        template <class T>
            T & ArbolExpre<T>::datoraiz() {
            return raiz->data;
        }
        
        
        //Indica si el &#65533;rbol binario est&#65533; vacio
        template <class T>
        bool ArbolExpre<T>::esvacio () const {
            return (raiz==NULL);
        }
        
        template <class T>
        void ArbolExpre<T>::preorden() const {
            if (!esvacio()) {
                cout << raiz->data << " ";
                izquierdo().preorden();
                derecho().preorden();
         }
        }
        
        template <class T>
        string ArbolExpre<T>::notacion_infija()const
        {
            string st;
            if(!esvacio())
            {
                if(!izquierdo().esvacio() && !derecho().esvacio())
                    return st="("+izquierdo().notacion_infija()+raiz->data+derecho().notacion_infija()+")";
                else
                return st=raiz->data;
            }
        }
        
        ////////////// OKk
        template <class T>
        bool ArbolExpre<T>::esExtendido() const {
            bool ext=false;
            if(esvacio()) {
                ext=true;
            } else {
            if((!izquierdo().esvacio()) && (derecho().esvacio()) || ((izquierdo().esvacio())&& (!derecho().esvacio()))) {
                ext=false;
            } else {
                ext=izquierdo().esExtendido();
                ext=derecho().esExtendido();
            }
            }
            return ext;
        }

//#################METODOS DE INFORMACION CREO#####################

bool es_entero (char a) {
    if (a=='*' || a=='/' || a=='-' || a=='+')
    return false;
    return true;
}

double evaluar (const ArbolExpre<char> &a) {
    if (a.izquierdo().esvacio() && a.derecho().esvacio()) {
        return a.datoraiz() - '0';
    } else {
            switch (a.datoraiz()) {
            case '+':
                return (evaluar(a.izquierdo()) + evaluar(a.derecho()));
            break;
            case '-':
                return (evaluar(a.izquierdo()) - evaluar(a.derecho()));
            break;
            case '*':
                return (evaluar(a.izquierdo()) * evaluar(a.derecho()));
            break;
            case '/':
                return (evaluar(a.izquierdo()) / evaluar(a.derecho()));
            break;
        }
    }
}

ArbolExpre <char> crear_arbol2 (string cadena,int tam, int &pos){
    ArbolExpre<char> izq,der;
    if (pos<tam) {
        if (!es_entero(cadena[pos])) {
        ArbolExpre<char> arb(cadena[pos]);
        pos++;
        izq = crear_arbol2 (cadena,tam,pos);
        pos++;
        der = crear_arbol2 (cadena,tam,pos);
        arb.modificar(arb.datoraiz(),izq,der);
        return arb;
    } else {
        return ArbolExpre<char> (cadena[pos],izq,der);
    }
    }
}

void notacion_funcional(const ArbolExpre<char> & a){
char raiz;
    if (!a.esvacio()) {
        raiz=a.datoraiz();
        switch (raiz) {
        case '+':
        cout << "suma(";
        break;
        case '-':
        cout << "resta(";
        break;
        case '*':
        cout << "producto(";
        break;
        case '/':
        cout << "division(";
        break;
        default:
        cout << raiz;
        break;
}
notacion_funcional(a.izquierdo());
    if(raiz=='+' || raiz=='*'|| raiz=='/'||raiz=='-' )
    cout << ",";

notacion_funcional(a.derecho());
}
    if(raiz=='+' || raiz=='*'|| raiz=='/'||raiz=='-' )
        cout<<")";
}
//#################FIN METODOS DE INFORMACION CREO

//##########################################FIN ARBOL###########################33


//##########################################INI MI LOGICA ###########################33
struct ICalculator{

};

struct calculator: public virtual ICalculator{
    //TENER UN OBJETO DE TIPO ARBOL
    //PARA IR PUSHEANDO LO PARCEADO
    int conN = 0;
    int conO = 0;
    int posi = 0;
    ArbolExpre <char> arb;
    void calculate(string expresion){
        //cout<<"entre"<<endl;
        string exp = (string)expresion;
        string aux;
        double numeros;
        string signos;
        stringstream input(exp);
        double res=-1;
        //CREO Q ASI SE CREA UN ARBOL DE EXPRESION Y TENDRIAS Q IR CREANDO UN ARBOL POR CADA EXPRESION Q TE DEN SUPONGO
        //1 PARAMETRO EXPRESION , TAMANO , POSI NO SE PARA Q SEA SOLO HIZE UN CONTADOR
        int len = expresion.length();
        arb = crear_arbol2 (expresion,len,posi);
        posi++;
        //#################  Y ESTO DE ABAJO ESTARIA POR DEMAS O NO SE INTENTA VER EN LOS COUTS 
        //COMO TE DEVUELVE CUANDO LE DAS 4 + 5 UNO DE LOS METODOS DE ABAJO TE DEVUELVE EL CUATRO Y EL OTRO EL 5 MIRA ESO Y LOS SUMAS
        //DE ESTA FORMA PARCESO CADA NUMERO Y SIGNO DEPENDIENDO
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
                //colaoperator.push(aux);  pusheo al arbol pero como SIGNO
                conO++;              
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
//##########################################FIN MI LOGICA ###########################33


int main(){


    calculator c;
    eval(c, "2 + 5");//7
    cout<<"******************************"<<endl;

    string s;
    ArbolExpre <char> a;//EJEMPLO DE COMO PUSHEAR CREO
    char sig = 's';
    int tam;

    while (sig!='n') {
        cout << "Nueva cadena: ";
        cin >> s;
        tam= s.length();
        cout << endl;
        cout << "Longitud: " << tam ;

        // PREGUNTA 1
        //cout << "****************************************" << endl;
        //cout << "Crear arbol: " << endl;
        int pos =0;
        a = crear_arbol2 (s,tam,pos);
        cout << endl;
        // PREGUNTA 2
        cout << "****************************************" << endl;
        cout << "Mostrar arbol: " << endl;
        a.preorden();
        cout << endl;

        // PREGUNTA 3
        cout << "****************************************" << endl;
        if (a.esExtendido())
        cout << "Es Extendido.";
        else
        cout << "No es Extendido.";
        cout << endl;

        // PREGUNTA 4 Notacion Infija
        cout << "****************************************" << endl;
        cout << "Notacion Infija : " << endl;
        cout << a.notacion_infija();
        cout << endl;

        // PREGUNTA 5
        cout << "****************************************" << endl;
        cout << "Notacion funcional: " << endl;
        notacion_funcional (a);
        cout << endl;

        // PREGUNTA 6
        cout << "****************************************" << endl;
        cout << "Evaluar arbol: " << evaluar(a);
        cout << endl;

        ////////////////////////////////////////////////////
        cout << "Introducir otra cadena? (s/n)? ";
        cin >> sig;
        cout << endl;
    }

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