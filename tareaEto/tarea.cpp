#include <iostream>
#include <string>
#include <cstring>


using namespace std;
class Base{
    public:
    virtual ~Base(){}//es para q se llame al destuctor de sus hijos
    virtual string toString() const = 0;
    virtual bool equals( const Base &) const = 0 ;
    virtual size_t getHashCode() const = 0; 
};

class IInterface : public virtual Base{
};

class IComparable: public virtual IInterface{
    public:
    virtual int compareTo(const IComparable &) const =0;
};
class IComparator: public virtual IInterface{
    virtual int compare(const IComparator & ) const =0;
};

class DefaultComparator: public virtual IComparator{
    public:
    DefaultComparator(){}
    int compare(const IComparator & c) const override{//ESTE METODO TALVES DEVERIA PEDIR DOS INTEGERS PARA COMPARARLOS ENTRE ELLOS
                                                        //Y NO PEDIR UN ICOMPARATOR
        return 0;
    }
//TUVE Q IMPLEMENTAR ESTOS METODOS PORQ COMO HEREDA DE BASE ESTA OBLIGADO A IMPLEMENTARLOS
    string toString()const override{
        char aux[32];
        sprintf(aux , "Object@%p",this);//llenamos a la variable aux 
        return aux;
    }
    bool equals( const Base & s)const override{
        return this==&s;//compara por su direccion de memoria
    }
    size_t getHashCode()const override{
        return reinterpret_cast<size_t>(this);
    }

};
class CIComparator: public virtual IComparator{
    public:
    int compare(const IComparator & c) const override{//ESTE METODO TALVES DEVERIA PEDIR DOS CI PARA COMPARARLOS ENTRE ELLOS 
                                                    //Y NO PEDIR UN ICOMPARATOR
        return 0;
    }
//TUVE Q IMPLEMENTAR ESTOS METODOS PORQ COMO HEREDA DE BASE ESTA OBLIGADO A IMPLEMENTARLOS
    string toString()const override{
        char aux[32];
        sprintf(aux , "Object@%p",this);//llenamos a la variable aux 
        return aux;
    }
    bool equals( const Base & s)const override{
        return this==&s;//compara por su direccion de memoria
    }
    size_t getHashCode()const override{
        return reinterpret_cast<size_t>(this);
    }
};
class Object : public virtual Base{
    string toString()const override{
        char aux[32];
        sprintf(aux , "Object@%p",this);//llenamos a la variable aux 
        return aux;
    }
    bool equals( const Base & s)const override{
        return this==&s;//compara por su direccion de memoria
    }
    size_t getHashCode()const override{
        return reinterpret_cast<size_t>(this);
    }
};

class String : public virtual Object, public virtual IComparable{
    string str;
    public:
    String(const string &s):str{s}{
    }
    string toString()const override{
        return str;
    }
    bool equals( const Base & s)const override{
        const String & aux = dynamic_cast<const String &>(s);
        return str == aux.str;
    }
    size_t getHashCode()const override{
        std::hash<string> aux;
        return aux(str);
    }
    int compareTo(const IComparable & s) const override{
        const String & aux = dynamic_cast<const String &>(s);
        return str.compare(aux.str);
    }
};

class Integer : public virtual Object, public virtual IComparable{
    int i;
    public:
    Integer(const int &s):i{s}{
    }
    string toString()const override{
        return to_string(i);
    }
    bool equals( const Base & s)const override{
        const Integer & aux = dynamic_cast<const Integer &>(s);
        return i == aux.i;
    }
    size_t getHashCode()const override{
        std::hash<int> aux;
        return aux(i);
    }
    int compareTo(const IComparable & s) const override{
        const Integer & aux = dynamic_cast<const Integer &>(s);
        return i-aux.i;
    }
};

class CI: public Object{
    int nit;
    string city;
    public:
    CI(const int & i, const string & s):nit{i},city{s}{}
    string toString()const override{
        char aux[32];
        sprintf(aux , "CI@%p",this);//llenamos a la variable aux 
        return aux;
    }
    bool equals( const Base & s)const override{
        const CI & aux = dynamic_cast<const CI &>(s);
        return nit == aux.nit;
    }
    size_t getHashCode()const override{
        std::hash<int> aux;
        return aux(nit);
    }
};
struct Pair{
    Object * key;
    Object * value;
};
class Node{
    Pair * data;
    Node * izq;
    Node * der;
    public:
    Node(Pair * data, Node * izq = nullptr , Node * der= nullptr):data{data},izq{izq},der{der}{}
};

class TreeMap: public virtual Object{
    Node * root;
    IComparator * comparator;

    public:
    TreeMap():root{nullptr}{//no se puede instanciar un objeto con new de la anterior forma
        comparator = new DefaultComparator();//tuve q acer asi
    }
    TreeMap( const IComparator & c ) :root{nullptr} {//no se puede instanciar un objeto con new de la anterior forma
            comparator = new CIComparator();//tuve q acer 
    }
    void add( Object * key, Object * value ){
        auto nn = new Node(new Pair{key, value});
    }
};

int main(){
    std::hash<string> aux;
    string j= "jhose";
    size_t t =aux(j);
    std::cout << "hash(s1) = " << t << "\n";
    std::cout << "hash(s1) = " << aux(j) << "\n";

    return 0;
}

   /*  TreeMap M;//TODO ORIENTADO A OBJETOS
    //          key             value
    m.add(new Integer(2), new String("dos"));
    m.add(new Integer(4), new String("cuatro"));
    m.add(new Integer(0), new String("cero"));
    cout<<m.toString()<<endl;
    m.remove(Integer {0});
    for(auto & p: m){ //TENEMOS Q ACER ITERADOR EN EL TreeMap  //llamar al destructor borrar nodos los objetos de ;los nodeos y el comparador
        cout<<p.key->toString()<<endl;
        cout<<p.value->toString()<<endl;
    }
    cout<<m[Integer{4}]->toString()<<endl;//implementar operatror []  //accedo a la valor con la llave 4
                                            //es como un m.get
    //tendremos una propiedad de clase de tipo CIComparetor para segun a eso comparar el CI
    TreeMap pm{new CIComparator()};//nos serviria  
    m.add(new CI(4928514,"Cbba"), new String("pedro lopez"));//el default comparater compara 
    cout<<pm.toString()<<endl; *///si  nos dan ci comparariamos mediante el ci