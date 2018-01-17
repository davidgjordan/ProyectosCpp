//LIBRERIAS ANADIDAS POR SI ACASO. . .
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdio>

using namespace std;

//****************************************************************************

struct SllNode{
public:
    char * str;
    int frecuencia;
    SllNode * next;
    SllNode * previous;
    // SllNode(){
    // }
    ~SllNode(){
            //cout<<"entre SllNode"<<endl;
}

};

struct StringLinkedList{
public:
    SllNode * first = nullptr;
    SllNode * last/*ultimo*/ = nullptr;

    StringLinkedList& push_back( const char * s){//anade al nodo fin
        auto ns = copy(s);
        auto nn = new SllNode{ns,1,nullptr, nullptr};//tiene n q estar en el heap
        if(first == nullptr){
            first = last = nn; 
            return *this;
        }
        last->next = nn;
        nn->previous = last;
        last = nn;
        return *this;
    }
    StringLinkedList& push_back( const char * s, int frecuencia){//anade al nodo fin
        auto ns = copy(s);
        auto nn = new SllNode{ns,frecuencia,nullptr, nullptr};//tiene n q estar en el heap
        if(first == nullptr){
            first = last = nn; 
            return *this;
        }
        last->next = nn;
        nn->previous = last;
        last = nn;
        return *this;
    }
    StringLinkedList(SllNode * first1,SllNode * last2){
        first = first1;
        last = last2;
    }
    StringLinkedList & push_front( const char * s){//anade al nodo ini
        auto ns = copy(s);
        auto nn = new SllNode{ns,1, nullptr, nullptr};//tiene n q estar en el heap
        if(first == nullptr){
            first = last = nn; 
            return *this;
        }
        nn->next = first;
        first->previous = nn;
        first = nn;	
        return *this;
    }
    void print() const{
        // es *
            auto aux  = first;
            while(aux != nullptr){
                cout<<aux->str<<":  "<<aux->frecuencia<< " occurrences(s) " <<endl;
                aux = aux->next ;
            }
        }
// VOID PRINT_REVERSE
        void print_reverse() const{
        // es *
            auto aux  = last;
            while(aux != nullptr){
                cout<<aux->str<<endl;
                aux = aux->previous ;
            }
        }
        ~StringLinkedList(){
            auto aux = first;
            while(aux){
                auto next = aux->next;
                delete [] aux->str;
                delete aux;
                aux = next;
            }
            //cout<<"entre StringLinkedList"<<endl;
        }
        static char * copy(const char * s){
            auto len = strlen(s);
            auto ns = new char[len+1];
            memcpy(ns , s, len+1);
            return ns;
         }
    //constructor copia
    StringLinkedList (const StringLinkedList & src){
        auto aux = src.first;
        while(aux){
            push_back(aux->str);
            aux = aux->next;
        }
        cout<<"entre constructor copia "<<endl;
    }
// ejercicio es
// HACER El OPERTOR =
        StringLinkedList & operator=(const StringLinkedList & sll){
            if(&sll == this){
                return *this;
            }
            this->~StringLinkedList();

            auto aux = sll.first;
        while(aux){
            push_back(aux->str);
            aux = aux->next;
        }
        cout<<"entre operator= "<<endl;
            return *this;
        }
        
// EL CONSTRUCTOR copia de movida
        StringLinkedList(StringLinkedList && src){
            auto aux = src.first;
            //src = nullptr;
            while(aux){
                auto auxNdo = aux->next;
                push_back(aux->str);
                aux->str =  nullptr;
                aux = nullptr;
                aux = auxNdo;
             }
            cout<<"entre CONSTRUCTOR copia de movida "<<endl;
        }

    //OPERADOR = DE MOVIDA
    StringLinkedList & operator=(StringLinkedList && src){
        if(&src == this){
            return *this;
        }
        this->~StringLinkedList();
        auto aux = src.first;
        while(aux){
            auto auxNo = aux->next;
            push_back(aux->str);
            aux->str =  nullptr;
            aux = nullptr;
            aux = auxNo;
        }
        cout<<"OPERADOR = DE MOVIDA "<<endl;
        return *this;
    }

//  CONSTRUCTOR SIN PARAMETROS
        StringLinkedList(){
        }

// VOID REMOVE(CONST CHAR * S)  TODOS LOS ELEMENTOS IGUALES A ESTA CADENA
        void remove(const char *c){
            int i = 0;
            if(first == nullptr){
                cout<<"lista vacia"<<endl;
            }else{
                auto aux = first;
                                
                while(aux){
                    auto auxNo =  aux->next;
                    if ( strcmp(aux->str , c) == 0)
                    {	
                        if(aux->next == nullptr && aux->previous == nullptr ){
                            aux->str = nullptr;
                            aux = nullptr;
                        }else if(aux->next != nullptr && aux->previous == nullptr ){
                            first = aux->next;
                            aux->next->previous = nullptr;
                            aux->str = nullptr;
                            aux = nullptr;		 				
                        }else if(aux->next == nullptr && aux->previous != nullptr){
                            last = aux->previous;
                            aux->previous->next = nullptr;
                            aux->str = nullptr;
                            aux = nullptr;
                        }else{
                            aux->previous->next = aux->next;
                            aux->next->previous = aux->previous; 
                            aux->str = nullptr;
                            aux = nullptr;
                        }
                    }
                        aux = auxNo;
                }
            }
        }

        bool existeWorld(const char *c){
            auto aux  = first;
            bool res = false;
            while(aux != nullptr){
                if(strcmp(c, aux->str)  == 0 ){
                    res = true;
                    break;
                }
                aux = aux->next ;
            }
            return res;
        }
        void addFrecuencia(const char *c){
            auto aux  = first;
            
            while(aux != nullptr){
                if(strcmp(c, aux->str)  == 0 ){
                    aux->frecuencia++;
                    break;
                }
                aux = aux->next ;
            }   
        }

        int getMayorFrecuencia(){
            auto aux = first;
            //auto aux2 = first;
            int frecuenciaAux = aux->frecuencia;
            while(aux != nullptr){
                if(aux->next != nullptr){    
                    if(frecuenciaAux < aux->next->frecuencia){
                        frecuenciaAux = aux->next->frecuencia;
                        //aux2 = aux;
                    }
                }
                aux = aux->next;
            }
            //cout<<aux2->str<<aux2->frecuencia<<endl<<frecuenciaAux;
            return frecuenciaAux;
        }
        int getMenorFrecuencia(){
            auto aux = first;
            auto aux2 = first;
            int frecuenciaAux = aux->frecuencia;
            while(aux != nullptr){
                if(aux->next != nullptr){
                    
                    if(frecuenciaAux > aux->next->frecuencia){
                        frecuenciaAux = aux->next->frecuencia;
                        aux2 = aux;
                    }
                }
                aux = aux->next;
            }
            //cout<<aux2->str<<aux2->frecuencia<<endl<<frecuenciaAux;
            return frecuenciaAux;
        }

        void ordenarList(int frecuencia ,StringLinkedList & o){
            auto aux  = first;
            while(aux != nullptr){
                
                if(frecuencia == aux->frecuencia ){
                    o.push_back(aux->str, aux->frecuencia);
                }
                aux = aux->next ;
            }   
        }

        int getFrecuenciaWorld(const char *c){
            auto aux  = first;
           int res = 0;
            while(aux != nullptr){
                if(strcmp(c, aux->str)  == 0 ){
                    res = aux->frecuencia;
                    break;
                }
                aux = aux->next ;
            }
            return res;
        }



};

//*****************************************************************************


class text_processor{
public:
    char * p;
    StringLinkedList sll;//todas las palabras
    StringLinkedList sllOrder;//mayortes o menores

    //char *p[1000];


    public :
        text_processor(const char *src){

            auto len = strlen(src);
            p = new char[len+1];
            strcpy(p, src);
            llenarListaPalabras();
            //cout<<p<<endl;
        }
        ~text_processor(){
            delete p;
        }
        text_processor & add_word(const char * src){
        
            auto len = strlen(p)+strlen(src)+strlen(" ");
            auto pAux = new char[len+1];
            strcpy(pAux, (const char *)p);
            strcat(pAux,(const char *)" ");
            strcat(pAux,src);
            delete p; 
            
            p = new char[len+1];
            strcpy(p,(const char *)pAux);

            if(!sll.existeWorld((const char *)src)){
                sll.push_back((const char *)src);                
            }else{
                sll.addFrecuencia((const char *)src);
            }

            return *this;
        }

        void print(){
            sllOrder.print();
        }
        text_processor & get_most_frequent_words(){//obtener las palabras más frecuentes

            int mayorFrecuencia = sll.getMayorFrecuencia();
            //cout<<mayorFrecuencia<<endl;
            sll.ordenarList(mayorFrecuencia, sllOrder);
            return *this;
        }
        //metodo llamado desde el constructor para llenar la lista de palabras
        void llenarListaPalabras(){
            auto len = strlen(p);
            char * aux = new char[len+1];
            strcpy(aux , p);
            char * c = strtok(aux," -(),.");
            int count = 1 ;
            while(c != nullptr){
                if(!sll.existeWorld((const char *)c)){
                    sll.push_back((const char *)c);                
                }else{
                    sll.addFrecuencia((const char *)c);
                }
                c = strtok(nullptr, " -(),.");
                count++;
            }
        }
        //con la lista llenada obtenemos en otra lista ordenada segun lo q nos pide el metodo
        text_processor & get_least_frequent_words(){//obtener palabras menos frecuentes

            int menorFrecuencia = sll.getMenorFrecuencia();
            cout<<"menor"<<menorFrecuencia<<endl;
            sll.ordenarList(menorFrecuencia, sllOrder);

            return *this;
        }

        int get_char_count(){//obtener el número total de char
            auto len = strlen(p);
            char * aux = new char[len+1];
            strcpy(aux , p);
            int count = 1 ;
            //cout<<"*********************************************"<<endl;
            //cout<<p<<endl;
            while(*aux){
                count++;
                 *(aux++);
            }
            return count;
        }

        int get_letter_count(){//obtener el conteo total de letras
            auto len = strlen(p);
            char * aux = new char[len+1];
            strcpy(aux , p);
            int count = 1 ;  //
                 while(*aux){
                     if((int)(*aux) >= 97 && (int)(*aux) <= 122){
                      count++;                        
                     }
                     *(aux++);
                 }
            return count;
        }

        int get_digit_count(){  //obtener el total de digitos numericos
            auto len = strlen(p);
            char * aux = new char[len+1];
            strcpy(aux , p);
            int count = 1 ;
           
            while(*aux){
                if((int)(*aux) >=48 && (int)(*aux) <= 57){
                      count++;
                }
             *(aux++);
            }
            return count;
        }
        int get_word_count(){//CONTEO DE PALABRAS
            auto len = strlen(p);
            char * aux = new char[len+1];
            strcpy(aux , p);
            char * c = strtok(aux," -(),.");
            int count = 1 ;
            while(c != nullptr){
                //cout<<c<<count<<endl;
                c = strtok(nullptr, " -(),.");
                count++;
            }
            return count;
        }

        int get_frequency_by_word( const char * src){//obtener frecuencia por palabra
            return sll.getFrecuenciaWorld(src);
        }


        void print_all_frequencies(){
            sll.print();
        }
        
};


int main()
{
                text_processor ts { "hp and asus have announced the first windows 10 pcs running on arm - snapdragon 835 - and they're boasting about instant-on, 22 hour battery life, and gigabit lte. these machines run full windows 10 - so not some crippled windows rt nonsense - and support 32bit x86 applications. microsoft hasn't unveiled a whole lot just yet about their x86-on-arm emulation, but ars did compile some information. "
                                "the emulator runs in a just-in-time basis, converting blocks of x86 code to equivalent blocks of arm code. this conversion is cached both in memory (so each given part of a program only has to be translated once per run) and on disk (so subsequent uses of the program should be faster, as they can skip the translation). moreover, system libraries - the various dlls that applications load to make use of operating system feature - are all native arm code, including the libraries loaded by x86 programs. calling them compiled hybrid portable executables (or 'chippie' for short), these libraries are arm native code, compiled in such a way as to let them respond to x86 function calls."
                                "while processor-intensive applications are liable to suffer a significant performance hit from this emulation - photoshop will work in the emulator, but it won't be very fast - applications that spend a substantial amount of time waiting around for the user - such as word - should perform with adequate performance. as one might expect, this emulation isn't available in the kernel, so x86 device drivers won't work on these systems. it's also exclusively 32-bit; software that's available only in a 64-bit x86 version won't be compatible. " };
                 cout<<"ts.get_most_frequent_words().print()"<<endl;//cumple
                 ts.get_most_frequent_words().print();//cumple
                 cout<<"ts.get_least_frequent_words().print()"<<endl;//cumple
                 ts.get_least_frequent_words().print();//cumple
                  
                  cout << "ts.get_char_count()" << "\n";//cumple
                  cout << ts.get_char_count() << "\n";//cumple
                  cout << "ts.get_letter_count()" << "\n";//cumple
                  cout << ts.get_letter_count() << "\n";//cumple
                  cout << "ts.get_digit_count()" << "\n";//cumple
                  cout << ts.get_digit_count() << "\n";//cumple
                  cout <<" ts.get_word_count()" << "\n";//cumple
                  cout << ts.get_word_count() << "\n";//cumple

                 cout <<" ts.get_frequency_by_word(emulator)" << "\n";//cumple
                 cout << ts.get_frequency_by_word("emulator") << "\n";//cumple
                 cout <<" ts.get_frequency_by_word(atari)" << "\n"; //cumple
                 cout << ts.get_frequency_by_word("atari") << "\n";//cumple

                 cout <<"ts.print_all_frequencies()"<<endl;
                 ts.print_all_frequencies();

                 cout<<"ts.add_word(asus).add_word(asus).add_word(asus).add_word(asus).add_word(asus).add_word(asus)"<<endl;
                 ts.add_word("asus").add_word("asus").add_word("asus").add_word("asus").add_word("asus").add_word("asus").add_word("the") ;
                // cout << "*****************\n";
                ts.print_all_frequencies();
                /* should print something like:
                   hp: 2 occurrence(s)
                   asus: 6 occurrence(s)
                  while: 1 occurrence(s)
                   ...
                */

                return 0;
}




