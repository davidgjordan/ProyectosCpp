
#include <iostream>

using namespace std;

bool isValid(const char *texto, const char *patron);
bool isPatronValid(const char *patron);
bool textoMayorAPatron(const char * patron, const char * texto);
bool hayAsterisco(const char* patron, const char * texto, int countPatron , int countTexto );
bool existeLetraEnElTexto(const char * patron, const char * texto, int countPatron , int *countTexto );
bool isSegmentValid(const char * patron, const char * texto, int countPatron , int countTexto );


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
    if( isPatronValid(patron) && textoMayorAPatron(patron, texto)){//falta comprobar q si la ultima letra del patron es la misma q del texto
        //cout<<(int)(*(patron+2))<<" is valid"<<endl;
        int countPatron=0;
        int countTexto=0;   
        while(*patron){
            //si es letra
            if((int)(*patron) >= 95 && (int)(*patron) <= 122){
                // existeLetra?
                if(existeLetraEnElTexto(patron, texto , countPatron, &countTexto)){
                    *(texto+=countTexto);
                    //verifico los antecesores del patron y los antecesores del texto
                    // si el antecesor del patron n-1 es una letra entoces verifico q sea igual al del texto n-1
                    if(isSegmentValid(patron, texto , countPatron, countTexto)){
                        //seguimos iterando
                        countPatron=0;
                        countTexto=0;   
                    }else{//si no es un segmento valido
                        return false;
                    }
                    cout<<countTexto<<" -->countTexto"<<endl;
                    cout<<countPatron<<" -->countPatron"<<endl;
                    cout<<texto<<" -->texto"<<endl;
                    
                }else{//si la letra no existe
                    return false;
                } 
            }

            countPatron++;
            *(patron++);
        }
    }else{
        return false;
    }

    return false;
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

bool textoMayorAPatron(const char * patron, const char * texto){
    while(*texto){//recorro el texto
        if(!(*patron)){//si ya no hay datos en patron es true el texto es mas largo
            return true;
        }
        *(patron+=1);        
        *(texto+=1);            
    }
    return false;
}

bool hayAsterisco(const char * patron, const char * texto, int countPatron , int countTexto ){

    for(int i=countPatron; i>=0;i--){
       //si hay asterisco en las pociciones anteriores
        if(patron[-i] == '*'){
            //cout<<patron[-i]<<endl;            
            return true;
        }
    }
    cout<<"no hay asterisco"<<endl;            
    return false;
}


bool existeLetraEnElTexto(const char * patron, const char * texto, int countPatron , int *countTexto ){
    
    bool res = false;
    while(*texto){
       // cout<<*texto<<endl;
        //cout<<*patron<<endl;
        if(* texto == *patron){
            
            res = true;
            break;
        }
        *countTexto+=1;
        *(texto+=1);
    }
    //cout<<countTexto<<endl;
    
    return res;
}

bool isSegmentValid(const char * patron, const char * texto, int countPatron , int countTexto ){

    bool res= false;

    if( countPatron > countTexto ){
        res = false;
    }else if(countPatron == countTexto){
        res = true;
    }else{
        //si el tamano del patron es menor y hay asterisco
        // si el antecesor del patron n-1 es una letra entoces verifico q sea igual al del texto n-1        
        if( hayAsterisco(patron, texto, countPatron , countTexto)/*  || patron[-1] == texto[-1] || patron[1] == texto[1] */){
            res = true;
        }else{
            res= false;
        }
    }
    return res;
}





/*  while(*texto){ 
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
                } */










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
