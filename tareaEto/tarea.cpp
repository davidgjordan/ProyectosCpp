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
    string toString() const override
    {
        return to_string(nit);
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

        nn = new Node(new Pair{key, value}); //
        // Buscar el int en el �rbol, manteniendo un puntero al nodo padre
        while (!vacio(actual) && comparator->compare(actual->data->key, key) != 0)
        {
            padre = actual;
            if (comparator->compare(key, actual->data->key) > 0)
            { //si el key es mayor devolvera mayor a cero y nos vamos por la derecha
                actual = actual->der;
            }
            else if (comparator->compare(key, actual->data->key) < 0)
            {
                actual = actual->izq;
            }
        }
        // Si se ha encontrado el elemento, regresar sin insertar
        if (!vacio(actual))
        {
            return;
        }
        // Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
        // el nodo raiz
        if (vacio(padre))
        {
            root = nn;
        }
        // Si el int es menor que el que contiene el nodo padre, lo insertamos
        // en la rama izquierda
        else if (comparator->compare(key, padre->data->key) < 0)
        {
            padre->izq = nn;
        }
        // Si el int es mayor que el que contiene el nodo padre, lo insertamos
        // en la rama derecha
        else if (comparator->compare(key, padre->data->key) > 0)
        {
            padre->der = nn;
        }
    }

    string toString()
    {
        cout << "termine toString" << endl;

        return inOrden(root);
    }
    string inOrden(Node *root)
    {
        auto aux = root;
        string v = "";
        string k = "";
        /* si el árbol no está vacío, entonces recórrelo */
        if (aux != nullptr)
        {
            inOrden(aux->izq);
            v += aux->data->value->toString() + " ";
            k = aux->data->key->toString();

            cout << "key: " << k << " data: " << v << endl;

            inOrden(aux->der);
        } /* fin de if */

        return v;
    }

    void remove(Object obj)
    {

        Node *padre = nullptr;
        Node *nodo;
        int aux;

        Object * auxk;


        actual = root;

        Object * obj1 = dynamic_cast<Object *>(&obj);
        // Mientras sea posible que el valor est� en el �rbol
        while (!vacio(actual))
        {
            if ( comparator->compare(obj1 , actual->data->key ) == 0) 
            { // Si el valor est� en el nodo actual
                if (esHoja(actual))
                {              // Y si adem�s es un nodo hoja: lo borramos
                    if (padre) // Si tiene padre (no es el nodo raiz)
                        // Anulamos el puntero que le hace referencia
                        if (padre->der == actual)
                            padre->der = nullptr;
                        else if (padre->izq == actual)
                            padre->izq = nullptr;
                    delete actual; // Borrar el nodo
                    actual = nullptr;
                    return;
                }
                else
                { // Si el valor est� en el nodo actual, pero no es hoja
                    // Buscar nodo
                    padre = actual;
                    // Buscar nodo m�s izquierdo de rama derecha
                    if (actual->der)
                    {
                        nodo = actual->der;
                        while (nodo->izq)
                        {
                            padre = nodo;
                            nodo = nodo->izq;
                        }
                    }
                    // O buscar nodo m�s derecho de rama izquierda
                    else
                    {
                        nodo = actual->izq;
                        while (nodo->der)
                        {
                            padre = nodo;
                            nodo = nodo->der;
                        }
                    }
                    // Intercambiar valores de no a borrar u nodo encontrado
                    // y continuar, cerrando el bucle. El nodo encontrado no tiene
                    // por qu� ser un nodo hoja, cerrando el bucle nos aseguramos
                    // de que s�lo se eliminan nodos hoja.
                    /* aux = actual->data;
                    actual->dato = nodo->dato;
                    nodo->dato = aux;
                    actual = nodo;
 */
                    auxk = actual->data->key;
                    actual->data->key = nodo->data->key;
                    nodo->data->key = auxk;
                    actual = nodo;
                }
            }
            else
            { // Todav�a no hemos encontrado el valor, seguir busc�ndolo
                padre = actual;
                if (comparator->compare(obj1, actual->data->key) > 0)
                    actual = actual->der;
                else if (comparator->compare(obj1, actual->data->key) < 0)
                    actual = actual->izq;
            }
        } 
    }

    bool vacio(Node *root)
    {
        return root == nullptr;
    }
    bool esHoja(Node *r) { return !r->der && !r->izq; }
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

    TreeMap M1;
    M1.add(new Integer(2), new String("dos"));
    M1.add(new Integer(4), new String("cuatro"));
    M1.add(new Integer(0), new String("cero"));
    cout << M1.toString() << endl;
    //M1.remove(Integer{0}); //AQUI SE CUELGA SI LLAMAMOS AL REMOVE FALTA SOLUCIONAR ESTE METODO
    std::cout << "*****************************************************"
              << "\n";

    //*********************************************
   /*  Integer obj{7};
    if(Object * data = dynamic_cast<Object * >(&obj)){
            cout<<"se puede"<<endl;
     } */
   CIComparator *n = new CIComparator();
    TreeMap *M = new TreeMap(*n);
    M->add(new CI(2, "cbba1"), new String("topo1"));
    M->add(new CI(4, "cbba2"), new String("topo2"));
    M->add(new CI(0, "cbba3"), new String("topo3"));
    cout << M->toString() << endl; 

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