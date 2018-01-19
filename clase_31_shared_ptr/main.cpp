//SHARED_PTR<t> junto con cada punteros almacena el jnumero dew punteros  q estan apuntando a ese objeto


//a-----16   1
//a-----16   2  
//b-----15   1
//b-----15   0   cuantos obejtos estan apuntando cuando esta cero ce boora el objeto
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <memory> //contiene punteros inteligentes hay tres

using namespace std;


struct N{
    int x;
    N(int x):x{x}{
        std::cout << "N" << '\n';
        //throw 1;
    }
    ~N(){
        std::cout << "bye N" << '\n';
    }
    void show()const{
        std::cout << x << '\n';
    }
};


void print(N * a){
    a->show();
}

struct KyloRen;

struct HanSolo{
    shared_ptr<KyloRen> kid;
    ~HanSolo(){
        std::cout << "you killed me  HanSolo" << '\n';
    }

    void say(){
        std::cout << "LEIAAAAAAAAA" << '\n';
    }
};

struct KyloRen{
    weak_ptr<HanSolo> daddy;
    ~KyloRen(){
        std::cout << "KyloRen muajaja" << '\n';
    }    
};


int main(){


    /* auto a = new N(10);
    auto b = new N(15);
    auto c = new N(17);

    auto d = a;


    a = new N(30);
    d = new N(50);


    auto e= d;
    d= c;

    c= nullptr;


    delete a;
    delete b;
    delete c;
    delete d;
    delete e; */

    //a es de este tipo  shared_ptr<N>
    auto a = make_shared<N>(10); //mejor usar 

    shared_ptr<N> b{ new N(15)};

    auto c = make_shared<N>(17);//templates  todos las variables son pasadas al constructor de la clase N

    auto d = a;


    a = make_shared<N>(30);
    d = make_shared<N>(50);


    auto e= d;
    d= c;

    c.reset();  //c = nullptr  baja el contador de refereecnia con el nullptr quita el puntero


    a->show();
    b->show();
    d->show();
    e->show();



    print(a.get());//tenemos q convertir a puntero con get()

    std::cout << "*****************no funciona punteros inteligentes en este escenario***************" << '\n';

    auto hs= make_shared<HanSolo>(); // no funcionan en referencias circulares porq nunca llegan a cero y por eso no se destruyen
    auto kr= make_shared<KyloRen>();

    hs->kid = kr;
    kr->daddy = hs;

    kr->daddy.lock()->say();//metodo lock se crea un shared_pointer    //como daddy esun weak pointer tenemos q optener el shared pointer con lock
    
    // para estp es el tercer tipo de punteros

    //weak_ptr /// si esta apuntando a un objeto se elimina  tiene un shared_pointer eset  
    //elegir aly el hijo usa esto  porq es composision pintadito al lado de padre q sale del hijo
    //weak_ptr



    return 0;






}