/* EN ESTA PRIMERA ITERACION 
 QUE COSAS NECESITAMOS PARA UTILIZAR ESTE ASUNTO
 1 ENTENDER QUE ES LO QUE QUIERO OPTENER LOGRAR EN LA PRIMERA ITERACION
    ATACAR LO MAS BASICO 
 2 COMO LOGRAMOS MODELAR EL ASPECTO MAS SUPEFICIAL DE NUESTRO TEMA
 3 ESCRIBIR HISTORIAS LO MAS GRANULAR POSIBLE
 4 TENER CLARO Q HAY Q ACER DIVIDIRLO EN VARIAS HISTORIAS
*/

/* 



// EJERCICIO
"TENGO UN TEXTO CAULQUIERA."

LO QUE QUIERO ES TRABAJAR CON COMIDINES WILDCARDS

DARE OTRO TEXTO ASI 
"???g*"

en este solo hay o ? o *

estas dos cadenas emparejan o no

la reglas es q  ? representa cualquier caracter  solo uno 
y  * representa cualquier cantidad de caracteres  y esto cauqlueir caracter de lo q sea de 1 a n caracteres


recibe dos entradas el texto y el patron(ejemplo"*a*a") si acepater matcher o no  
    significa q en el final del texto tiene q aver una a
no puede tener dos * seguidos
 sin usar string principalmente */

#include <iostream>

using namespace std;

bool isValid(const char *texto, const char *patron);
class obj
{
  public:
    int x;
    obj() {}
    obj(int x) : x{x} {}
};
void show(const obj *o);
void show(obj *o);

int main()
{

    const char *texto = "Primer Texto";
    const char *patron = "*?i*";

    const obj *t1 = new obj(10);
    show(t1);

    const *obj t2(5);
    show(&t2);

    obj *t3;
    t3->x = 15;
    show(t3);

    // bool is_valid = isValid(texto, patron);
    return 0;
}
bool isValid(const char *texto, const char *patron)
{
    cout << texto << endl;
    cout << patron << endl;

    return true;
}

void show(const obj *o)
{
    cout << o->x << endl;
}

void show(obj *o)
{
    cout << o->x << endl;
}
//  ************************COMPETENCIAS*******************************
// DISENO
//  diseno  desarrollar un modelo-arquitectura apartir de un problema(modelar)
// aplicar estructuras de solucion conocidas y probadas dentro de diseno (pratrones de diseno)
// entender la aquitectura de una solucion(entender funcion de cada elemento en un diseno)

// ADMINISTRACION
// identificacion de riesgos ( identificar disco duro lleno, validaciones faltantes, nivel del equipo un companero no cumple con sus tareas)
// manejo de riesgos( adeamas de la capacidad de intedntificar el problema adelanterse con un plan de contingencia, solicitar el disco nuevo)
// realiazr estimaciones( cada ves mejorar nuestra abilidad de decir cuantos pountos de esfuerzo requiere una tarea completa)
// decowriten coding standar escritura de codigo estandares( ver reglas como equipo de trabajo )
// identificar la causa de bug de codigo(como soluciona el bug o como determias porq pas ael problema aislar el bug)
// codereview revisar la calidad del codigo (cogigo cruzado , o mandar nuestro codigo
// regla 1 codign standar, regla 2 diseno arquitectura como quedamos esqcribir el codigo)
