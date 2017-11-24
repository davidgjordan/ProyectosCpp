#include <iostream>
#include <cstring>
#include <string>

 using namespace std;

struct caja{

    
public:
    int x;

    ~caja(){
        cout<<"bye caja"<<endl;
    }
};

class cajon{
    
    
public:
    caja *c1;
    caja *c2;
    string *s;
    cajon(){

        // ubuira sido mejor acer caja c{20}; para q se guarde en el stack
        // porq asi guardamos en el heap 
        //CUANDO ISNTANCIAS CON NEW DEVUELVE UNA REFERENCIA DE MEMORIA A ESE OBJETO
        c1 = new caja{10};
        c2 = new caja{20};
        s = new string{"hello world"};
        // cout<<"cajoooondelete p"<<endl;
        // cout<<c1<<endl;
        
        // cout<<"cajoooondelete p"<<endl;
        
        cout<<"hi cajon"<<endl;
        
    }
    ~cajon(){

        delete c1; 
        delete c2;
        delete s;
        cout<<"bye cajon"<<endl;
    }

    // constructor copy  PARA COPIAR UN OBJETO EN OTRO  **\\**
    cajon( const cajon & p){
        // cosntruimos un nuevo string porq era el q daba problemas

        // EL THIS ES DE LA D DE ABAJO EN EL MAIN OSE ES ASI THIS.S THIS.C1
        s = new string{*(p.s)};
        c1 = new caja{*(p.c1)};
        // HACER PRUEBAS DE UN ARRAY& EN PARAMETRO 
        
        c2 = new caja{*(p.c2)};
        cout<<"ssssss"<<endl;
        
        cout<<*(p.s)<<endl;
        cout<<"ssssss"<<endl;
        

        cout<<"copia"<<endl;
        
    }

};

 int main(){
    //  podria crear sin new

cajon *c =  new cajon();



// cajor d es una copia de c  el cosntructor busca un costructor copia como no hay copia los bites del objeto
// D LLEGA A SER EL THIS DEL CONSTRUCTOR COPY Y COMO EL COSTRUCTOR COPY NOS PIDE
// UN VALOR POR EL & LE MANDAMOS EL VALOR DEL OBJETO C
cajon d = *c;//     **\\**




// asi borramos el cajon pero no las cajitas del constructor

delete c;

    return 0;
 }

//HABLAS DE TODO ESTO:

/* RECIBIRA UN OBSERVATION DE OPENAI PARA ENTRENAR EL AGENTE

    
    UNO Q PERMITA JUGAR Y SE GUARDE LO Q A ECHO
    EL MISMO PROGRAMA V A ENSENARSE A SI MISMO */

// ESCALABILIDAD  MENOS ADAPTABLE

// QUE SE MANEJA  SESIONES LAS OPERACIONES 
// QUE SEGUN LA INFORMACION Q LE DEMOS NOS CREA UN TENSORBOARD DE DATOS
    // ESTADISTICOS
//PUEDE ACER TODO TIPO DE OPERACIONES ARITMETICAS SUMAS MULTIPLICACIONES
//YA EMOS ECHO PEQUENOS EJEMPLOS LE DIRE SI NO


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


recibe dos textos el texto y el patron(ejemplo"*a*a") si acepater matcher o no  
    significa q en el final del texto tiene q aver una a
no puede tener dos * seguidos
 sin usar string principalmente */

 
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









