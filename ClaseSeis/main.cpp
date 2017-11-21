#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
using namespace std::string_literals;
/*
auto p = "hellorwordl"s;   se vuelve string*/

//es ineficeiente porq ace una copia de esa variable mejor usar referencia
//cuando no es un tipo primitivo simepre pasar referencia
void print_string(const string &z)
{
    cout << z << endl;
}
void reverse_string(string &z)
{
    int tam = z.length();
    int c = 1;
    string y = z;

    /*mejorar este algorimo con len/2*/
    for (int i = 0; i < z.length(); i++)
    {
        //char aux = z[z.length()-c];
        z[i] = y[tam - c];
        //cout<<z[i];
        c++;
    }
}

int main()
{

    string x = "November";

    cout << x.length() << endl;

    //imprimir
    //puts(x.c_str());
    //puts(x.data());

    x += ", 2017";
    //puts(x.data());

    //x += "is monday";

    //puts(x.data());

    print_string(x);

    reverse_string(x);

    print_string(x);

    //anadimos un punto al final
    //x.push_bacle('.');
    //cout<< x.length()<<endl;

    //wstring q = "Hola";
    //cout<< q.length()<<endl;
    //cout<< q.size()<<endl;

    auto p = "Hello world";

    //string::npos es -1

    /*auto i = p.find("world");
if(i==string::npos){


}
*/

    //FUNCION SUBSTRING
    auto r = "Esta noche wolking deant a las 11"s;

    //size_t es el auto en este caso
    auto i = r.find("wolking deant");
    if (i != string::npos){
        //le damos un indice y nos devuve una nueva cadena desde i asta el final
        //el otro substring pide dos parametros  desde (i, a) i desde donde a cuantas
    auto r2 = r.substr(i);
        cout << r2 << endl;
    }

    return 0;
}
                            