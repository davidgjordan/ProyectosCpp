//PUNTEROS A FUNCIONES
//los punteros a funciones no almacenan estado

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

using POPTS  = void(*)();

int sum(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

//son punteros del array a comparar
int cMayor(const void * a,const void * b){
    auto aa= (int*)(a);
    auto bb= (int*)(b);
    return * bb - *aa;//retorna segun a esto ordena

}

int cMenor(const void * a,const void * b){
    auto aa= (int*)(a);
    auto bb= (int*)(b);
    return * aa - *bb;//retorna segun a esto ordena

}



int show_menu(){
    std::cout << "*********" << '\n';
    std::cout << "0. say hi" << '\n';
    std::cout << "1. say goodmorning" << '\n';
    std::cout << "2. salir" << '\n';
    std::cout << "Enter option" << '\n';
    int op;
    do{
        cin>>op;
    }while(!(op>=0 && op<=2));
    
    return op;
}

void op1(){
    std::cout << "HIII" << '\n';
}
void op2(){
    std::cout << "GOODMORNIG" << '\n';
}void op3(){
    std::cout << "BYEE" << '\n';

    exit(0);
}






void show_progress(int perc){
    std::cout << perc << '\n';
}

void decode(void (*p)(int )){//la funcion a la q llamaremos se llamara p
    for (size_t i = 0; i < 100'0000'000; i++)
    {
        if(i%10'000'000 == 0){
            p(i/10'000'000);
        }
        auto s = log(i);
    }
}


//typedef void (*POPTS)();//significa puntero a funcio

void show(const int * x ,size_t n){
    for (size_t i = 0; i < n; i++)
    {   
        if(x[i] ==1 && x[i]<=5)
        std::cout << x[i] << '\n';
    }//como no tengo estado no puedo 
}

void invoke(void (*p)(const int * , size_t ), const int * q, size_t n){
    p(q,n);
}

//LOS FUNTORS SON OBJETOS CON ATRIBUTOS Y SE COMPORTAN COMO FUNCIONES
struct ShowRange{
    size_t min, max;

    void operator()(const int * q, size_t n)const{
        for (size_t i = 0; i < n; i++)
        {
            auto val = q[i];
            if(val>=min&&val<=max)
            std::cout << val << '\n';
            
        }
    }
};

/* para que intuya tipos de llamada*/
template <class P>
void invoke(P p, const int * q, size_t n){
    p(q,n);
} 


//EL FUNTOR ES CUALQUIER CLASE Q SOBRECARGA EL OPERADOR ()
//HERERNCIA POLIFORMISMO
 int main(){
    

    //es un p8unterpo a esta funcion sunm
    auto f = sum;
    int (*g)(int, int) = sub;//g es un punyrtp a una funcion  q recive dos enteros y devuelve un entero

    cout<<f(4,6)<<endl;
    cout<<g(4,6)<<endl;
    g= sum;//solo porq tienen el mismo retorno y parametros se puede hacer esta asignacion

    cout<<g(4,6)<<endl;
    
   

    int p [] = {1,6,9,3,0};
    qsort(p, 5, sizeof(int), cMayor);//array , numero d eelementos, tamano de cada elemento, y la funcion q compara

    for(int x:p){
    cout<<x<<endl;
    }
    qsort(p, 5, sizeof(int), cMayor);//array , numero d eelementos, tamano de cada elemento, y la funcion q compara
    cout<<"************************"<<endl;
    
    for(int x:p){
        cout<<x<<endl;
    }
    cout<<"************************"<<endl;


   /* POPTS opts[]= {op1,op2,op3};

    while(true){
        int op = show_menu();
        opts[op]();
    } */
    cout<<"***********decode*************"<<endl;
    
    //decode(show_progress);//le pasamos el puntero a un afuncion

    cout<<"***********f-show*************"<<endl;
    int q [] ={1,34,6,8,0,9};  
    //void (*f)(const int *, size_t) = show; 
    //auto f =show;
    //f(q,6);


    invoke(show,q , 6);
    cout<<"***********6-10*************"<<endl;
    
    ShowRange r{6,10};
    invoke(r,q , 6);//void (*)(const int*, size_t)
    
    return  0;


 }