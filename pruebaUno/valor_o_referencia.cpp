#include <iostream>
using namespace std;



// PASO POR VALOR copia el valor de la variable original
/* void sumar(int);
int main(){
    int n = 4;
    sumar(n);
    cout << n << endl; //salida 4
    return 0;
}
void sumar(int x)
{
    x++;
    cout << x << endl; //salida 5
}
 */


// PASO POR REFERENCIA  el metodo pide un objeto del tipo referencia de memoria &



/* PASO POR REFERENCIA

    Hay veces que nos interesa que una función modifique una variable que no pertenece a 
    ella, es decir, fuera de su ámbito. En C/C++ es imposible pasar una variable por 
    referencia como en otros lenguajes y hay que hacerlo a través de punteros 
    (o referencias como veremos más adelantes). La idea es que como solo se puede pasar 
    el valor de una variable a una función lo que hacemos es pasar la dirección de una 
    variable a través de un parámetro de puntero y luego con el operador de indirección 
    podemos acceder al contenido de la variable original.
 */
// void sumar(int*);
// int main()
// {
//     int n = 4;
//     // entonces ayq mandarle una referencia de memoria de algun objeto
//     sumar(&n);
//     cout << n << endl;//salida 5
//     return 0;
// }
// void sumar(int *x)
// {
//     // se accede al valor del objeto con el asterisco
//     *x = *x + 1;

//     /* Como vemos el parámetro de sumar ahora es un puntero que recibe una dirección 
//     de memoria en este caso le pasamos la dirección de la variable x y dentro de la 
//     función con operador de indirección podemos acceder al contenido de la variable n. */
//     cout << *x << endl; // salida 5
// }



/* REFERENCIAS

    Además de los punteros heredados de C el lenguaje C++ añadió una nueva característica 
    que son las referencias, una referencia es por así decirlo un alias o etiqueta de una variable.
    Las referencias se deben inicializar al declararse ya que no son en sí una variable sino una 
    etiqueta de otra y se declaran poniendo el operador & después del tipo de dato.
 */

 /* int main(){

     int n = 4;
     int &ref_n = n;
     cout << ref_n <<endl;//salida 4
    
     return 0;
 } */


 /* PASO POR REFERENCIA... CON REFERENCIAS
 
 Las referencias son una buena forma de pasar un valor a otra función sin ser por valor, 
 veamos el ejemplo anterior de paso por punteros, pero está vez usando referencias.
  */
 void sumar(int &);
 int main()
 {
     int n = 4;
     sumar(n);
     cout << n << endl; //salida 5
     return 0;
 }
 void sumar(int &x)
 {  //cuando el parametro tiene & trabajas directamente sobre el valor
     x = x + 1;
     cout << x << endl; //salida 5
 }