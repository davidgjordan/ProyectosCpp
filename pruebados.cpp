#include <iostream>
#include "arbin.h"
using namespace std;

//IMPLEMENTACIONES
//construye un arbol binario vacio
template <class T>
arbin<T>::arbin() {
raiz=NULL;
}

//crea un nuevo arbol binario a partir de un elemento y dos arboles binarios
template <class T>
arbin<T>::arbin(const T & e, const arbin<T> & izqdo, const arbin<T> & decho) {
raiz= new Nodo(e, izqdo, decho);
}


//modifica un arbin poniendo e como raiz e izqdo y dcho como hijo izquierdo
// y derecho respectivamente
template <class T>
void arbin<T>::modificar (const T & e, const arbin<T> & izqdo, const arbin<T> & dcho) {
if (!esvacio()) {
raiz->info=e;
raiz->izq=izqdo;
raiz->der=dcho;
}
else cout << "Error: arbol binario vacio" << endl;
}
//modica el arbol actual hasta obtener el arbin vacio
template <class T>
void arbin<T>::vaciar() {
if (!esvacio()) {
izquierdo().vaciar();
derecho().vaciar();
delete raiz;
}
}


//Copia el arbol binario actual
template <class T>
arbin<T> arbin<T>::copiar() {
arbin i, d ;
if (!esvacio()) {
if (!izquierdo().esvacio()) i=izquierdo().copiar();
if (!derecho().esvacio()) d=derecho().copiar();
//raiz=new Nodo(raiz->info, i, d);
//return raiz;
arbin x (raiz->info, i, d);
return x;
}
}

//Devuelve el subarbol izquierdo del &#65533;rbol, NULL si est&#65533; vac
template <class T>
arbin<T> & arbin<T>::izquierdo() const {
return raiz->izq;
}

//Devuelve el subarbol derecho del &#65533;rbol, NULL si est&#65533; vac
template <class T>
arbin<T> & arbin<T>::derecho() const {
return raiz->der;
}
//Devuelve el elemento de la raiz
template <class T>
const T & arbin<T>::datoraiz() const {

return raiz->info;
}
template <class T>
T & arbin<T>::datoraiz() {
return raiz->info;
}


//Indica si el &#65533;rbol binario est&#65533; vacio
template <class T>
bool arbin<T>::esvacio () const {
return (raiz==NULL);
}

template <class T>
void arbin<T>::preorden() const {
if (!esvacio()) {
cout << raiz->info << " ";
izquierdo().preorden();
derecho().preorden();
}
}

template <class T>
string arbin<T>::notacion_infija()const
{
string st;
if(!esvacio())
{
if(!izquierdo().esvacio() && !derecho().esvacio())
return st="("+izquierdo().notacion_infija()+raiz->info+derecho().notacion_infija()+")";
else
return st=raiz->info;
}
}

////////////// OKk
template <class T>
bool arbin<T>::esExtendido() const {
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

/********************************************/
/* main.cpp
/********************************************/


bool es_entero (char a) {
if (a=='*' || a=='/' || a=='-' || a=='+')
return false;
return true;
}

float evaluar (const arbin<char> &a) {
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

arbin <char> crear_arbol2 (string cadena,int tam, int &pos){
arbin<char> izq,der;
if (pos<tam) {
if (!es_entero(cadena[pos])) {
arbin<char> arb(cadena[pos]);
pos++;
izq = crear_arbol2 (cadena,tam,pos);
pos++;
der = crear_arbol2 (cadena,tam,pos);
arb.modificar(arb.datoraiz(),izq,der);
return arb;
} else {
return arbin<char> (cadena[pos],izq,der);
}
}
}

void notacion_funcional(const arbin<char> & a){
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

int main () {

string s;
arbin <char> a;
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

} // Final del while

return 1;
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