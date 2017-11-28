
#include <iostream>

using namespace std;

bool isValid(const char *texto, const char *patron);
bool isPatronValid(const char *patron);
bool hayAsterisco(const char* patron, const char * texto, int countPatron , int countTexto );
bool segmentValid(const char * patron, const char * texto, int countPatron , int countTexto );

int main()
{

    
    const char *texto = "primer texto hola como estas";
    auto *patron = "*?x?*";

    if(isValid(&texto[0],patron)){
         cout<<"El patron es valido"<<endl;
    }else{
         cout<<"El patron no es valido"<<endl;
    }

    // cout<<patron<<"aasd"<<endl;

    return 0;
}
bool isValid(const char *texto, const char *patron){
    /* 
     cout << texto << endl;         //primer texto hola como estas
    cout << *texto << endl;         //p
    cout << &texto << endl;         //0x7ffe9cb74dc8
    cout << *(&texto+1) << endl;    //@
    cout <<"************" << endl;              
    cout << patron << endl;         //*?x?*
    cout << &patron << endl;        //0x7ffe9cb74dc0
    cout << &patron[0] << endl;    //*?x?*
    cout << *patron << endl;        //*
    cout << *(&patron) << endl;    //*?x?*
    cout << *(&patron+1) <<endl;   //primer texto hola como estas  
    cout << (&patron+1) <<endl;    //0x7ffe9cb74dc8
    cout << (patron+1) << endl;     //?x?* 
    cout << *(patron+1)<< endl;     //? 
    cout <<"************" << endl; */
    if(isPatronValid(patron) ){
        //cout<<(int)(*(patron+2))<<" is valid"<<endl;
        int countPatron=0;
        int countTexto=0;
        
        while(*patron){
            //lo q importa son las letras y verifico si su n-1 es ? y su n-2 es *
            //si es letra
            if((int)(*patron) >= 95 && (int)(*patron) <= 122){
                cout<<*patron<<"Es letra"<<endl;
                //recorer la cadena para verificar si existe la letra
                while(*texto){ 
                    if(*patron == *texto ){
                        //tal ves todas estas comprobaciones se podrian acer en un metodo
                        if( (countPatron == countTexto) ||( countPatron < countTexto && hayAsterisco(patron, texto,countPatron, countTexto) )  ){
                            break;
                        }else{
                            return false;
                        }
                        countTexto=0;
                        countPatron=0;
                     //si ya recorrio toda la cadena y no encontro la letra del patron
                    }else if(*texto == nullptr ){
                            return false;                        
                    }
                        countTexto++;
                        *(texto++);
                }

                // return true;   
            }

            countPatron++;
            *(patron++);
        }

        return true;

    }else{
        return false;
    }

    return true;
}

bool isPatronValid(const char *patron){
    while(*patron){
        if(*patron == '*' && *patron == *(patron+1)){
            return false;
        }
        *(patron++);
    } 
    return true;        
}

bool hayAsterisco(const char * patron, const char * texto, int countPatron , int countTexto ){

    for(int i=countPatron; i>=0;i--){
       //si hay asterisco en las pociciones anteriores
        if(patron[-i] == '*'){
            cout<<patron[-i]<<endl;            
            return true;
        }
    }
    cout<<"no hay asterisco"<<endl;            
    return false;
}

bool segmentValid(const char * patron, const char * texto, int countPatron , int countTexto ){
    return true;
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
