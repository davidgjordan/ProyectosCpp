
#include <iostream>

using namespace std;

bool esLetraInicioFinValida(const char *texto, const char *patron, int tamT, int tamP);
bool hayLetraIni(const char *patron);
bool hayLetraFin(const char *patron);

bool esPatronSinDobleAstrisco( const char *patron);
int verificarTamanos(const char *texto, const char *patron);// -1 texto mayor 0 iguales 1 patron mayor
bool tieneAsterisco( const char *patron);
bool hayLetras( const char *patron);

bool isPatronValid(const char *texto, const char *patron);

 int getTam(const char *text);
/* bool isPatronValid(const char *patron);
bool hayAsterisco(const char* patron, const char * texto, int countPatron , int countTexto );
bool segmentValid(const char * patron, const char * texto, int countPatron , int countTexto ); */

int main(){
    const char *texto = "p*?x?*a1232f";
    auto *patron = "12345";

    cout<<"----------------------------"<<endl;
    cout<<getTam(patron)<<endl;




    
    return 0;

}



bool esLetraInicioFinValida(const char *texto, const char *patron, int tamT, int tamP){
        return texto[tamT] == patron[tamP] ;
}

bool hayLetraIni(const char *patron){
    return (int)(*patron) >= 95 && (int)(*patron) <= 122 ?  true:false ;
}

bool hayLetraFin(const char *patron){
    return (int)(patron[getTam(patron)-1]) >= 95 && (int)(patron[getTam(patron)-1]) <= 122 ?  true:false;
}


bool esPatronSinDobleAstrisco( const char *patron){
    while(*patron){
        if(*patron == '*' && *patron == *(patron+1)){
            return false;
        }
        *(patron++);
    } 
    return true;
}

// -1 texto mayor 0 iguales 1 patron mayor
int verificarTamanos(const char *texto, const char *patron){
    int countTexto = 0, countPatron = 0;
    while(*texto || *patron){
        if(*patron){
            countPatron++;
            *(patron++);
        }
        if(*texto){
            countTexto++;
            *(texto++);
        }        
    }
    if(countTexto>countPatron){
        return -1;
    }else if(countTexto<countPatron){
        return 1;
    }
    return 0;
}

bool tieneAsterisco( const char *patron){
    bool res = false;
    while(*patron){
        if(*patron == '*'){
            res = true; 
            break;
        }

        *(patron++);
    }
    return res;
}

bool hayLetras( const char *patron){
    while(*patron){
        if((int)(*patron) >= 95 && (int)(*patron) <= 122 ){
            return true;
        }
        *(patron++);
    }
    return false;
}

bool isPatronValid(const char *texto, const char *patron){

    if((int)(*patron) >= 95 && (int)(*patron) <= 122 ){
        
                return *texto == *patron ;
    }

            
    return true;
}


int getTam(const char *text){
    int c=0; 
    while(*text){
        c++;
        cout<<*text<<endl;
        *(text++);
    }
    cout<<c<<endl;
    
    return c;
}