//Usando sólo char* y no la clase string, escribir un StringBuilder(cosntructor de cadenas):
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdio>

using namespace std;


  class StringBuilder{
    char * p;
  public:
    StringBuilder(){
      p = new char[10000000000];
    }

    void append(const char * c){
      strcat(p, c); 
    }
     void append(int c){
      char  Cadena[10];  // Se declara la cadena, donde almacenaremos el valor de tipo int
           // Éste será el valor que pasaremos a la cadena
      sprintf(Cadena, "%d", c);  // De este modo se copia el valor de 'Num' a la cadena 'Cadena'
      //printf("%s", Cadena);
      strcat(p, Cadena);

    }

    const char * to_string(){
      return p; 
    }

    ~StringBuilder(){
      delete p;
    }
 };

int main()
{
  StringBuilder sb;

  for (int i = 0; i < 1000; i++)
  {
     for (int j = 0; j < 1000; j++)
     {
        sb.append("(");
        sb.append(i);
        sb.append(", ");
        sb.append(j);
        sb.append(");");
     }
     sb.append("\n");
  }

  cout << sb.to_string() << "\n";
  return 0;
}

