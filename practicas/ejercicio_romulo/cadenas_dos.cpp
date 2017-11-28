
#include <iostream>

using namespace std;

bool isValid(const char *texto, const char *patron);
bool isPatronValid(const char *patron);
bool textoMayorAPatron(const char * patron, const char * texto);
bool hayAsterisco(const char* patron, const char * texto, int countPatron , int countTexto );
bool existeLetraEnElTexto(const char * patron, const char * texto, int countPatron , int *countTexto );
bool isSegmentValid(const char * patron, const char * texto, int countPatron , int countTexto );

bool isAnterioresValid(const char * patron, const char * texto, int countPatron , int countTexto );
bool isPosterioresValid(const char * patron, const char * texto, int countPatron , int countTexto );

int main()
{  
    const char *texto = "primer texto hola como estas";
    auto *patron = "*?x?*";

    if(isValid(&texto[0],patron)){
         cout<<"El patron es valido"<<endl;
    }else{
         cout<<"El patron no es valido"<<endl;
    }
    return 0;
}
bool isValid(const char *texto, const char *patron){

    if( isPatronValid(patron) && textoMayorAPatron(patron, texto)){//falta comprobar q si la ultima letra del patron es la misma q del texto
        int countPatron=0;
        int countTexto=0;   
        while(*patron){
            //si es letra
            if((int)(*patron) >= 95 && (int)(*patron) <= 122){
                if( isAnterioresValid(patron, texto, countPatron, countTexto) && isPosterioresValid(patron, texto, countPatron, countTexto) ){//sus anteriores y sus posteriores
                    countPatron=0;
                    countTexto=0;   
                }else{
                    return false;
                }
            }
            countPatron++;
            *(patron++);
        }
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






bool isAnterioresValid(const char * patron, const char * texto, int countPatron , int countTexto ){
    
    
    return false;
}
bool isPosterioresValid(const char * patron, const char * texto, int countPatron , int countTexto ){
    
    
    return false;
}