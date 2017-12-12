//LIBRERIAS ANADIDAS POR SI ACASO. . .
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdio>

using namespace std;
class palabra{
    char * p;
    int frecuencia;
public:
    void setPal(const char * src){
        p = new char[strlen(src)+1];
        strcpy(p,src);
    }
    void setFrecuencia(int src){
        frecuencia = src;
    }
    char * getPal(){
        return p;
    }
    int getFrecuencia(){
        return frecuencia; 
    }
};

class text_processor{

    char * p;

    public :
        text_processor(const char *src){

            auto len = strlen(src);
            p = new char[len+1];
            strcpy(p, src);
            //cout<<p<<endl;
        }
        ~text_processor(){
            delete p;
        }
        text_processor & add_word(const char * src){
            //strcat(p, src);
            //cout<<p<<endl;
            return *this;
        }

        void print(){
            cout<<p<<endl;
        }
        text_processor & get_most_frequent_words(){//obtener las palabras más frecuentes
            auto aux = p;
            char * c = strtok(aux," -(),.");
            while(c != nullptr){
                c = strtok(nullptr, " -(),.");
            }
            return *this;
        }


        text_processor & get_least_frequent_words(){//obtener palabras menos frecuentes

            return *this;
        }

        int get_char_count(){//obtener el número de char
            auto len = strlen(p);
            char * aux = new char[len+1];
            strcpy(aux , p);
            int count = 1 ;
            while(*aux){
                count++;
                 *(aux++);
            }
            return count;
        }

        int get_letter_count(){//obtener el conteo de letras
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

        int get_digit_count(){  
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
            auto len = strlen(p);
            char * aux = new char[len+1];
            strcpy(aux , p);
            char * c = strtok(aux," -(),.");
            int count = 1 ;
            palabra pal[strlen(p)+1]; 
            int i = 0;
            while(c != nullptr){
                //cout<<c<<endl;
                if(!existe(pal , c)){
                    pal[i].setPal(c); 
                    pal[i].setFrecuencia(1);
                    i++;
                }else{

                    pal[i].setFrecuencia(pal[i].getFrecuencia()+1);
                }
                c = strtok(nullptr, " -(),.");
                count++;
            }
            return 0;
        }
    private:
        existe(palabra p[],  char * c){
                cout<<"entre"<<endl;

            for (int i = 0; i <100; ++i)
            {
                cout<<"entre 2"<<endl;

                cout<<p[i].getPal()<<endl;
            }
            return false;
        }

};


int main()
{
                text_processor ts { "hp and asus have announced the first windows 10 pcs running on arm - snapdragon 835 - and they're boasting about instant-on, 22 hour battery life, and gigabit lte. these machines run full windows 10 - so not some crippled windows rt nonsense - and support 32bit x86 applications. microsoft hasn't unveiled a whole lot just yet about their x86-on-arm emulation, but ars did compile some information. "
                                "the emulator runs in a just-in-time basis, converting blocks of x86 code to equivalent blocks of arm code. this conversion is cached both in memory (so each given part of a program only has to be translated once per run) and on disk (so subsequent uses of the program should be faster, as they can skip the translation). moreover, system libraries - the various dlls that applications load to make use of operating system feature - are all native arm code, including the libraries loaded by x86 programs. calling them compiled hybrid portable executables (or 'chippie' for short), these libraries are arm native code, compiled in such a way as to let them respond to x86 function calls."
                                "while processor-intensive applications are liable to suffer a significant performance hit from this emulation - photoshop will work in the emulator, but it won't be very fast - applications that spend a substantial amount of time waiting around for the user - such as word - should perform with adequate performance. as one might expect, this emulation isn't available in the kernel, so x86 device drivers won't work on these systems. it's also exclusively 32-bit; software that's available only in a 64-bit x86 version won't be compatible. " };
                 //ts.get_most_frequent_words().print();
                 //ts.get_least_frequent_words().print();
                 // cout << "ts.get_char_count()" << "\n";
                 // cout << ts.get_char_count() << "\n";
                 // cout << "ts.get_letter_count()" << "\n";
                 // cout << ts.get_letter_count() << "\n";

                 // cout << "ts.get_digit_count()" << "\n";
                 // cout << ts.get_digit_count() << "\n";

                 // cout <<" ts.get_word_count()" << "\n";
                 // cout << ts.get_word_count() << "\n";

                 cout << ts.get_frequency_by_word("emulator") << "\n";
                // cout << ts.get_frequency_by_word("atari") << "\n";

                // ts.print_all_frequencies();
                 //ts.add_word("asus").add_word("asus").add_word("asus").add_word("asus").add_word("asus").add_word("asus");
                // cout << "*****************\n";
                // ts.print_all_frequencies();
                /* should print something like:
                   hp: 2 occurrence(s)
                   asus: 6 occurrence(s)
                  while: 1 occurrence(s)
                   ...
                */

                return 0;
}