#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char* strrev( char* s ){
    char  c;
    char* s0 = s - 1;
    char* s1 = s;
    while (*s1) ++s1;
    while (s1-- > ++s0){
      c   = *s0;
      *s0 = *s1;
      *s1 =  c;
      }
    return s;
}


int main(){

    							//para crear otra cadena con este len es len + 1
	const char *p = "hoy es 17 de diciembre de 2017";
	const  char * c1 = strstr(p,"17");//Localiza la primera aparición en la cadena apuntada por s1 de la secuencia de caracteres (excluyendo el carácter nulo) en la cadena apuntada por s2.
   
    /* char mesage[] = "hola cocacola";
    strrev(mesage);
    std::cout << mesage << '\n';
    strrev(mesage); */
    std::cout << c1 << '\n';


    auto s = "bolivia";
	auto a = "argentina";
	auto c2 = "brasil";
	cout<<strcmp(s,a)<<endl;
	cout<<strcmp(s,c2)<<endl;
    cout<<strcmp(s,a)<<endl;
    cout<<'b'-'a'<<endl;
    





    cout<<"*******************************"<<endl;
    const char * texto ="primer texto hola como estass";
    cout << texto << endl;         //primer texto hola como estas
    cout << *texto << endl;         //p
    cout << &texto << endl;         //0x7
    cout << *(&(*texto)+1) << endl;    //r

    int a1 = 9;
    int * n = &a1;
    cout << n << endl;    //r

    char * cc = "fsdf";
    cout << *cc << endl;         //primer texto hola como estas

    
    
    return 0;
}