#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
//herenecia multiple

using namespace std;

// struct A{
// int x;
// };
// struct B{
// int y;
// };
// struct Point: public A, public B{
// };
// //*******************
// class Vehiculo{
// public: 
// 	void moverse(){
// 		cout<<"me muevo"<<endl;
// 	}
// };
// class Volador{
// public: 
// 	void volar() const{
// 		cout<<"vuela vuela"<<endl;
// 	}
// };
// class Animal{
// public: 
// 	void comer(){
// 		cout<<"comer"<<endl;
// 	}
// };

// class Aguila:public Animal , public Volador{
// };

// class Helicoptero:public Vehiculo , public Volador{
// };

// void work(const Volador & x){
// 	x.volar();
// }

struct X {
	int x;
	void m(){
		cout<<x<<endl;   //DREAD DIAMOND PROBLEM
	}
};

struct  Y : X{  
 };
struct Z : X{
};
struct A : Y,Z{
	void m(){ //el metodo m de la clase padre se cultan
		Y::m();
		Z::m();
	}
};

int main(){

// Point p;
// p.x = 12;
// p.y = 25;
// cout<<p.y<<endl;

// Aguila a;
// Helicoptero h;
// Volador x;
// //aqui sabe q tipo de oibjeto es y llamara a su metodo segun su funcuaoin

// work(a);
// work(h); // work(x);


A a;

a.Y::x = 25;
a.Z::x = 30;

//cout<<a.Z::x<<endl;



a.Y::m();
a.Z::m();




    return 0;
}