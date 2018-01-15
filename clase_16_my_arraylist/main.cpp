#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

class object{

public:
    virtual ~object(){}
    //si las clases hijas no implementan este virtual las clases hijas se ejecutara este metodo
    virtual string to_string()const{
        return std::to_string((long long)this);
    }
};

class shape: public object{//clase abstracta
public:

    //metodo virutal puro
    virtual const char * getName()const = 0;
    virtual double getArea()const = 0;

    virtual ~shape(){//obligado
    }
    shape(){//obligado
        //cout<<getName()<<endl; //nunca llamar metodos virtuales en un cosntructor
    }

    void seyHello(){    
        cout<<"hello"<<endl;
    }

    void print() const{
        cout<<to_string()<<endl;
           
    }

    string to_string()const override{
        return string{getName()}+"(" + std::to_string(getArea())+")";//lo vuelvo string para contcaternar
    }


};

class circle : public shape{
    double r;
public:
    circle(double r):r{r}{

    }


    //metodos obligados de la clase abstracta
    const char * getName()const override{
        return "circle";
    }
    ///overrride sircve para obtener errores
    virtual double getArea() const override{
        return 3,1415 * r;
    }

};



class rectangle : public shape{


double w,h;

public:
    rectangle(double w,double h):w{w}, h{h}{

    }
    // ostream-> ofstream  ->std-> cout
     //metodos obligados de la clase abstracta
     const char * getName()const override{
        return "rectangle";
    }
    ///overrride sircve para obtener errores
    virtual double getArea() const override{
        return w*h;
    }


};
struct mah{
public:
    object * & s;  //es una referencia al puntero  con * &
    mah(object * & s):s{s}{
        // delete s;
    }
    void operator=(object *p){
        delete s;
        s=p;
    }
    object * operator->(){
    return s;
    }
};
class my_arraylist : public object {//puede tener listas en listas con object
    size_t n;//numero de elementos que existen actualmente insertados
    size_t cap;//capacidad numero de elementos q puede almacenar antes de crecer
    using iterator = object**; //alias cada ves q diga iterator remplazon por object **
public:
    object ** data;///tiene un array de punteros y a su ves cada puntero es una direccion de memoria de otro objeto
    
    my_arraylist(size_t c= 4):n(0), cap(c), data(new object * [c]){//por defecto

    }
    ~my_arraylist(){
        for(auto i=0; i<n;i++){
            delete data[i];
        }
        delete []data;
    }

   /*  my_arraylist(const my_arraylist & ){
        =delete;
        my_arraylist& operator=(const my_arraylist &) =delete;
    } */

    size_t size() const{
        return n;
    }
    object * operator[](size_t x) const {
        return data[x];
    }

    // object * & operator[](size_t x) {
    //     return data[x];
    // }

     mah operator[](size_t x){
        return mah{data[x]};
    } 

    iterator /* object ** */ begin(){ //es el i = 0 masd o menos
        return & (data[0]);
    }

    iterator /* object ** */ end(){ //es el i = n.size mas o menos
        return &  (data[n]);//
    }


    void add(object * o){//sin asterisco pierde el polimorfismo
        if(cap == n){//si ya no entrar elementos a mi array cresco
            grow();
        }
        data[n++]= o;//la siguiente ves anado en la pocision n+1
    }

    void grow(){
        //este metodo crea otro array mas grande 
        auto heap = cap*2;//crecere de dos en dos
        auto ndata = new object *[heap];//ahora sera de doble tamano
        //ahora copio los punteros de los objetos al nuevo array
        // con elmetodo memcpy
        memcpy(ndata, data, cap * sizeof(object*));//copia este numero de punteros
        cap =  heap;
        delete [] data;
        data = ndata;
    }

    string to_string()const override{
     //recorrera todos lo objetos y les ara tostring

     string x;
     for(auto i = 0; i<n;i++){
        object * s =data[i];
        if(s == nullptr){
            x+= "[nullptr]";
        }else{
            x+=s->to_string()+"\n";
        }
     }
        return x;
    }


};


    

int main(){

    circle x{5};//asi se instacia  al objeto
    // cout<<x.getName()<<endl; //llamamos 
    // cout<<x.getArea()<<endl;
    //x.print();


    // shape f[3];//no se ppuede porq es abstracta
    // shape * f[3];//tenemos punteros apuntado a objetos
    // f[0]=new circle(6);
    // f[1]=new rectangle(6,7);
    // f[2]=new circle(7);

    // // s es shape* 
    // for(auto s : f){
    //     s->print();
    // }
    // for(auto s : f){
    //  delete s;
    // }
/* 

    my_arraylist ss;
    ss.add(new circle(5));
    ss.add(new rectangle(5, 5));
    ss.add(new circle(2));
    cout<<ss.to_string()<<endl;    

        
    for(auto i=0;i<ss.size(); i++){
        cout<<ss[i]->to_string()<<endl;
    }


    ss[2] = new rectangle(9,3);

    cout<<ss.to_string()<<endl;    
    
    cout<<ss[2]->to_string()<<endl;
     */

    object * m = new rectangle{2, 23};

    auto p = dynamic_cast<circle*>(m);//le dan el tipo de objeto a la q quiere castear y este verifica si es una instancia al q quiere castear
                                        //si si es una instancia castea si no devuelve null

                            //si acemos dinamic cast a algo q no tiene metodos virtuales no compila
    if(p!=nullptr ){
     cout<<"circulo"<<endl;
    
    }else{
        cout<<"no circulo"<<endl;
    }    
    
    

    my_arraylist y;
    y.add(new circle(5));
    y.add(new rectangle(5, 5));
    y.add(new circle(2));
    for(auto i : y){
        cout<<i->to_string()<<endl;
    }

    cout<<"*********dasdsad***************"<<endl;
    
    for(auto i=0;i<y.size(); i++){
        cout<<y[i]->to_string()<<endl;
    }

    return 0; 
}
