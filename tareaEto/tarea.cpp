#include <iostream>
#include <string>
#include <cstring>

using namespace std;
//********************************INI BASE**********************************************
class Base
{
  public:
    virtual ~Base() {} //es para q se llame al destuctor de sus hijos
    virtual string toString() const = 0;
    virtual bool equals(const Base &) const = 0;
    virtual size_t getHashCode() const = 0;
};
//********************************END BASE**********************************************

//********************************INI IINTERFACE**********************************************
class IInterface : public virtual Base
{
};
//********************************END IINTERFACE**********************************************

//********************************INI OBJECT**********************************************
class Object : public virtual Base
{
  public:
    ~Object() {}
    string toString() const override
    {
        char aux[32];
        sprintf(aux, "Object@%p", this); //llenamos a la variable aux
        return aux;
    }
    bool equals(const Base &s) const override
    {
        return this == &s; //compara por su direccion de memoria
    }
    size_t getHashCode() const override
    {
        return reinterpret_cast<size_t>(this);
    }
};
//**********************************ENDO OBJECT********************************************
//********************************INI ICOMPARABLE**********************************************
class IComparable : public virtual IInterface
{
  public:
    virtual int compareTo(const IComparable &) const = 0;
};
//********************************END ICOMPARABLE**********************************************

//********************************INI ICOMPARATOR**********************************************
class IComparator : public virtual IInterface
{
  public:
    virtual int compare(Object *nit, Object *key) const = 0;
};
//********************************END COMPARATOR**********************************************

//********************************INI STRING**********************************************
class String : public virtual Object, public virtual IComparable
{
    string str;

  public:
    ~String() {}
    String(const string &s) : str{s}
    {
    }
    string toString() const override
    {
        return str;
    }
    bool equals(const Base &s) const override
    {
        const String &aux = dynamic_cast<const String &>(s);
        return str == aux.str;
    }
    size_t getHashCode() const override
    {
        std::hash<string> aux;
        return aux(str);
    }
    int compareTo(const IComparable &s) const override
    {
        const String &aux = dynamic_cast<const String &>(s);
        return str.compare(aux.str);
    }
};
//********************************END STRING**********************************************

//********************************INI INTEGER**********************************************
class Integer : public virtual Object, public virtual IComparable
{
  public:
    int i;

  public:
    ~Integer() {}
    Integer(const int &s) : i{s}
    {
    }
    string toString() const override
    {
        return to_string(i);
    }
    bool equals(const Base &s) const override
    {
        const Integer &aux = dynamic_cast<const Integer &>(s);
        return i == aux.i;
    }
    size_t getHashCode() const override
    {
        std::hash<int> aux;
        return aux(i);
    }
    int compareTo(const IComparable &s) const override
    {
        const Integer &aux = dynamic_cast<const Integer &>(s);
        return i - aux.i;
    }
};
//********************************END ITNEGER**********************************************

//********************************INI CI**********************************************
class CI : public Object
{
  public:
    int nit;
    string city;

  public:
    ~CI() {}
    CI(const int &i, const string &s) : nit{i}, city{s} {}
    string toString() const override
    {
        char aux[32];
        sprintf(aux, "CI@%p", this); //llenamos a la variable aux
        return aux;
    }
    bool equals(const Base &s) const override
    {
        const CI &aux = dynamic_cast<const CI &>(s);
        return nit == aux.nit;
    }
    size_t getHashCode() const override
    {
        std::hash<int> aux;
        return aux(nit);
    }
};
//********************************END CI**********************************************

//********************************INI DEFAULTCOMPARATOR**********************************************
class DefaultComparator : public virtual IComparator
{
  public:
    ~DefaultComparator() {}
    DefaultComparator() {}
    int compare(Object *i1, Object *i2) const override
    { //ESTE METODO TALVES DEVERIA PEDIR DOS INTEGERS PARA COMPARARLOS ENTRE ELLOS
        //Y NO PEDIR UN ICOMPARATOR
        Integer *int1 = dynamic_cast<Integer *>(i1);
        Integer *int2 = dynamic_cast<Integer *>(i2);
        // return int1->compareTo(*int2);
        return int1->i - int2->i;
    }
    //TUVE Q IMPLEMENTAR ESTOS METODOS PORQ COMO HEREDA DE BASE ESTA OBLIGADO A IMPLEMENTARLOS
    string toString() const override
    {
        char aux[32];
        sprintf(aux, "DefaultComparator@%p", this); //llenamos a la variable aux
        return aux;
    }
    bool equals(const Base &s) const override
    {
        return this == &s; //compara por su direccion de memoria
    }
    size_t getHashCode() const override
    {
        return reinterpret_cast<size_t>(this);
    }
};
//********************************END DEFAULTCOMPARATOR**********************************************

//********************************INI CICOMPARATOR**********************************************
class CIComparator : public virtual IComparator
{
  public:
    ~CIComparator() {}
    int compare(Object *nit1, Object *nit2) const override
    {
        CI *ci1 = dynamic_cast<CI *>(nit1);
        CI *ci2 = dynamic_cast<CI *>(nit2);
        return ci1->nit - ci2->nit;
    }
    //TUVE Q IMPLEMENTAR ESTOS METODOS PORQ COMO HEREDA DE BASE ESTA OBLIGADO A IMPLEMENTARLOS
    string toString() const override
    {
        char aux[32];
        sprintf(aux, "Object@%p", this); //llenamos a la variable aux
        return aux;
    }
    bool equals(const Base &s) const override
    {
        return this == &s; //compara por su direccion de memoria
    }
    size_t getHashCode() const override
    {
        return reinterpret_cast<size_t>(this);
    }
};
//********************************END CICOMPARATOR**********************************************

//********************************INI PAIR**********************************************
struct Pair
{
    Object *key;
    Object *value;
};
//********************************END PAIR**********************************************

//********************************INI NODE**********************************************
class Node
{
  public:
    Pair *data;
    Node *izq;
    Node *der;

  public:
    Node(Pair *data, Node *izq = nullptr, Node *der = nullptr) : data{data}, izq{izq}, der{der} {}
};
//********************************END NODE**********************************************

//********************************INI TREEMAP**********************************************
class TreeMap : public virtual Object
{
    Node *root;
    Node *actual;
    IComparator *comparator;

  public:
    TreeMap() : root{nullptr}
    {                                         //no se puede instanciar un objeto con new de la anterior forma
        comparator = new DefaultComparator(); //tuve q acer asi
    }
    TreeMap(const IComparator &c) : root{nullptr}
    {                                    //no se puede instanciar un objeto con new de la anterior forma
        comparator = new CIComparator(); //tuve q acer
    }
    void add(Object *key, Object *value)
    {
        Node *nn;
        Node *padre = nullptr;
        actual = root;
        //PIENSO PRIMERO TENEMOS Q VER SI EL KEY ES UN INTEGER O UN CI PARA PODER
        //ANADIRLO AL ARBOL
        //Y COMPARLO SEGUN SU NIT O COMO INTEGER LO QUE SEA
        //SI ES UN CI CREAMOS
        //si es un ci acemos algo . . .         EL NODO CON KEY CI
        nn = new Node(new Pair{key, value}); //
        /* comparator = dynamic_cast<CIComparator *>(comparator);
        if(!comparator){
            comparator = dynamic_cast<DefaultComparator * >(comparator);
        } */
        // Buscar el int en el �rbol, manteniendo un puntero al nodo padre
        while (!vacio(actual) && comparator->compare(actual->data->key, key) != 0)
        {
            cout << "1" << endl;
            padre = actual;
            if (comparator->compare(key, actual->data->key) > 0)
            { //si el key es mayor devolvera mayor a cero y nos vamos por la derecha
                actual = actual->der;
                cout << "2" << endl;
            }
            else if (comparator->compare(key, actual->data->key) < 0)
            {
                actual = actual->izq;
                cout << "3" << endl;
            }
        }
        // Si se ha encontrado el elemento, regresar sin insertar
        if (!vacio(actual))
        {
            cout << "4" << endl;
            return;
        }

        // Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
        // el nodo raiz
        if (vacio(padre))
        {
            cout << "5" << endl;
            root = nn;
        }
        // Si el int es menor que el que contiene el nodo padre, lo insertamos
        // en la rama izquierda
        else if (comparator->compare(key, actual->data->key) < 0)
        {
            cout << "6" << endl;
            padre->izq = nn;
        }
        // Si el int es mayor que el que contiene el nodo padre, lo insertamos
        // en la rama derecha
        else if (comparator->compare(key, actual->data->key) > 0)
        {
            cout << "7" << endl;
            padre->der = nn;
        }
        //add(c);
        cout << "termine add" << endl;
    }

    string toString()
    {
        cout << "termine toString" << endl;

        return inOrden(root);
    }
    string inOrden(Node *root)
    {
        auto aux = root;
        string r;
        cout << "in 0" << endl;
        /* si el árbol no está vacío, entonces recórrelo */
        if (aux != nullptr)
        {
            cout << "in 1" << endl;
            inOrden(aux->izq);
            r += aux->data->value->toString() + " ";
            inOrden(aux->der);
            //r+=aux->data->value->toString()+" ";
        } /* fin de if */

        return r;
    }

   /*  void InOrden(void (*func)(int &), Nodo *nodo, bool r)
    {
        if (r)
            nodo = raiz;
        if (nodo->izquierdo)
            InOrden(func, nodo->izquierdo, false);
        func(nodo->dato);
        if (nodo->derecho)
            InOrden(func, nodo->derecho, false);
    } */

    bool vacio(Node *root)
    {
        return root == nullptr;
    }
};
//********************************END TREEMAP**********************************************

int main()
{
    std::hash<string> aux;
    string j = "jhose";
    size_t t = aux(j);
    std::cout << "hash(s1) = " << t << "\n";
    std::cout << "hash(s1) = " << aux(j) << "\n";

    IComparable *a = new Integer(8);
    IComparable *b = new Integer(10);

    cout << a->toString() << endl; //es uin metodo eeredado en
                                   //la clase basic y tyambien esta implementado en tla otra rama y funciona por el virtual
                                   //todo en java es virtual
    cout << a->compareTo(*b) << endl;
    std::cout << "*****************************************************"
              << "\n";

    TreeMap M;
    M.add(new Integer(2), new String("dos"));
    cout << M.toString() << endl;

    M.add(new Integer(4), new String("cuatro"));
    // M.add(new Integer(0), new String("cero"));
    cout << M.toString() << endl;

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
    cout<<pm.toString()<<endl; */ //si  nos dan ci comparariamos mediante el ci