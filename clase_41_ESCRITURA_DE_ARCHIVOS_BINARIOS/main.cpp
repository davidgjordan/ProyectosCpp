//ESCRITURA DE ARCHIVOS BINARIOS
#include <unordered_map>//esta es la libreria
#include <iostream>
#include <string>
#include <cstring>
#include <vector> 
#include <algorithm> 
#include <fstream> 

using namespace std;

//POD PLANE OLD POD  //tambien son tipos primitivos y structuras q solo tienen tipos primitivos
struct Product{
    int id;
    char name[32];
    char description[32];
};

template<typename T>
void write(ofstream&){

}

template<typename T, typename U, typename ...ARGS>
void write(ostream & x,const  U & u, const ARGS...args){
    //separo el primer elemento q es u y el resto
    x.write((char *)&u, sizeof(T));
    write<T>(x, args...);
}

template <typename T , typename ...ARGS>
void write(const string & x, const ARGS &...args){

    ofstream f {x, ios::binary};
    write<T>(f, args...);
}

int main(){//CIHash provee el codigo hash , CIEq compara para el hasmap no es NECESARIO SI HAY EL OPERATOR ==
    /* 
    vector<Product> ps;
    ps.push_back(Product{12, "nintendo switch", "game console"});
    ps.push_back(Product{5, "xboxonex", "game console"});
    ps.push_back(Product{8, "playstation4", "game console"});//es mas facil encontrar del disco por todos tienen el mismo tamano swi esta esctio en binario
 
    ofstream f2{"ps4.dat", ios::binary};
    for(auto & p: ps){
        //f2.write((char *)&p,sizeof(p));//le pasamos un puntero q aputna a la dreccion de miemoria donde vamos a grabar
    }
    f2.write((char *) ps.data(), sizeof(Product)* ps.size());//data me devuevle un puntero al pirmer elemento del vecor

 

    vector<Product> pp;

    ifstream g2{"ps4.dat", ios::binary| ios::app};//app es para q en ves ee sobreescibir lo anada al final

    Product auxp;
    while(g2.read((char *)&auxp,sizeof(auxp) )){//read devuelve un string
        pp.push_back(auxp);
    }

    for(auto & p:pp){
        cout<<p.name<<" - "<<p.description<<endl;
    }
    g2.close();
 */

    write<int>("arch.dat", 6,7,8,9,0,2);

    ifstream nf{"arch.dat", ios::binary};
    //dos parametros uno es la cantidad de bits q quiero recorrer y desde donde quiero hacer el ciclo
    nf.seekg(5*sizeof(int),ios::beg);   //esta funcion cuando se abre el archivo se mueve a la pocicion de memoria q le digamos
    //significa q desde el pruncipio quiero recorrer 20 bits
                            //ios beg me da un puntero a la primera pocicion de memoria
                            //ios cur desde la pocicion 20 anvanza 
                            //ios end seva al final del archivo
    int n;

    nf.read((char *)&n , sizeof(int));//con esto puedo iterar en el elemento 
    cout<<n<<endl;

    nf.seegk(0, ios::end); 
    auto size = n.tellg(); //tellg dice cuantos bits a recorrido asta el final del archivo
    cout<<size<<"\n";


    //EJERCICIO


    return 0;
}

//T tiene q ser un pod
template<typename T>
class file_vector{//no usar vectores
    string filename;
    //tendria q tener un filestream todo el treabajo accediendo a disco
    file_vector(const string & filenameR):filename{filenameR}//si no existe lo crea si no lo lee
    {
        ofstream f2{filename, ios::binary};
        
    }
    void push_back(const T & x)//agrega un elemento al final del archivo
    {
        ofstream f2{filename, ios::binary| ios::app};//app es para q en ves ee sobreescibir lo anada al final
        f2.write((char *)&x,sizeof(T));
    }
    T operator[](size_t index )const//devuelve el elemento en esa pocicion
    {
        T aux;
        ifstream nf{filename, ios::binary};
        
    }
    size_t size()const;//deveulve el numero de elementos q hay en el vector
    void set(size_t index , const T& x);//escrive en el vector en esa pocicicon si me vector no tiene  ese indice botamos una exepcion
    file_vector_iterator begin() const;
    file_vector_iterator end() const;
};
