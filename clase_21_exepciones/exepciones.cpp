#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <stdexcept>

using namespace std;
struct X {
    int *p;
    ~X(){
        cout<<"bye"<<endl;
        delete []p;
    }


};

struct my_exeption{
    string  msg ;
    ~my_exeption(){
        cout<<"destructur my _ exeption"<<endl;     
    }
};

//lo mejor es botar asi 
class devin24exption :  public exception{
    string  msg ;
    public: 
        devin24exption(const string & m):msg(m){

        }

        const char * what() const noexcept override {//no va votar exepciones esta por la no...
            return msg.c_str();     //se debe sobreescribir esta funcuin
        }
};

void d(){
    // cout<<"Hello"<<endl;

    // throw "errror t ";
    // cout<<"Hello 2"<<endl;

    // int * p = nullptr;//el c++ no recive errores umanos en sus exepciones
    // *p = 4;

    // int a = 2, b =0;
    // cout<<a/b<<endl;
    // string c = "Hola";
    // cout<<c.at(1000000)<<endl;//at imprime la pocicion 100000 y como no existe arroja una exepcion (bota un uptput_rage)
    
    // //esto ya no se ejecuta por la exepcion q arroja el at
    // c[1000000] = 'q';

    // int * p = new int[10];
    // throw 10;
    // delete []p;//nunca ace delete pporq se arroja el throw antes
    
    // int * p = nullptr;
    // try{
    //     p= new int[10];
    //     throw 10;
    // }catch(...){
    //     delete []p;
    //     throw; //la exepcion q llega aqui la bota afuera
    // }
    // delete []p;


    //RRAII

    X x {new int [10]};//en el, destructor se de este objeto es ele encargado de borrar la memoria
    throw devin24exption{"new devin24exption"}; //
    //cada q veas un puntero q declara el con * pensa en la liberacion de memoria
}
void b(){
    d();
}
void c(){
    cout<<"HOLA"<<endl;    
}

void a(){
    b();
    c();
}

void e () noexcept(false){//con este false le decimos q si puede botar excpciones
    throw 10;
}

int main(){
// try {
//     a();
// }catch(int x){//... significa capturar cualquier exepction
//     cerr<<"Error "<<x<<endl;    
    
// }catch(const char * x){
//     cerr<<"Error "<<x<<endl;    
// }
// catch(const my_exeption  & e){//*  se destruyen dos veces por estamospasando por valor aumentemos & //la mejor forma de acer es asi
//     cerr<<"Error "<<e.msg<<endl;//
//     //delete e;//devemos eliminar la exepcion encaso de q sea un puntero   
// }
// catch(const exception  & e){//captura cualquiera q erede exception
//     cerr<<"Error "<<e.what()<<endl;//
//     //delete e;//devemos eliminar la exepcion encaso de q sea un puntero   
// }
// catch(...){
//     cerr<<"catch generico "<<endl;      
// }
// cout<<"Final bye"<<endl;    

try {
    e();
}catch(...){
 cout<<"Final bye"<<endl;       
}
    return 0;
}