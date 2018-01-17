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
        //std::cout << "aqui 1" << '\n';
        Integer *int1 = dynamic_cast<Integer *>(i1);
        //std::cout << "aqui 2" << '\n';        
        Integer *int2 = dynamic_cast<Integer *>(i2);
        //std::cout << "aqui 3" << '\n';        
        // return int1->compareTo(*int2);
        //return int1->i - int2->i;
        return int1->compareTo(*int2);
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

//********************************INI PILA**********************************************
class NodePila
{
  public:
    Pair *data;
    NodePila *sig;

  public:
    NodePila(Pair *data, NodePila *sig = nullptr) : data{data}, sig{sig} {

    }
};

struct Pila{
    NodePila * ultimo = nullptr;
    public:
    void push(Pair *data){
        auto n = new NodePila(data, ultimo);
        ultimo = n;
    }

    Pair * pop(){
        if(!ultimo)return 0;
        auto aux = ultimo;
        auto data = aux->data;

        ultimo = ultimo->sig;
        delete aux;
        return data;
    }
    void print(){
        auto aux = ultimo;
        while(aux){
            cout<<"pila: "<<aux->data->key->toString()<<endl;
            aux = aux->sig;
        }
    }
};
//********************************END PILA**********************************************


//********************************INI TREEMAPITERATOR**********************************************
struct TreeMapIterator
{
    
    Pila *pila;
    Pair *p;    //apunta siempre al siguietne elemento valido de la lista

   // HashMapIterator(PairLL **data,size_t cap,size_t pos,Pair *pair):data{data},cap{cap},pos{pos}{//ESTE CONSTRUCTPOR OPCIONAL 
   //     p = findNext(data, cap, pos);                                                       //POR SI NO SE INSTANCIA BIEN EL PAIR
   //     pair = p;
   // } 
    bool operator!=(const TreeMapIterator &src)
    {
        return p != src.p;
    }
    const Pair &operator*() const
    {
        return *p;
    }
    
    TreeMapIterator &operator++()
    { //es el prefijo ++i no el postfijo
        p = findNext();
        return *this;
    }
    Pair *findNext()
    {            
       return pila->pop();
        
    }

}; 
//********************************END TREEMAPITERATOR**********************************************



//********************************INI TREEMAP**********************************************
class TreeMap : public virtual Object
{
    Node *root;
    Node *actual;
    IComparator *comparator;
   
    Pair pair[50];
    Pila pila;

    int cantidad = 0;
    using iterator = Pair *;  //alias cada ves q diga iterator remplazon por Pair *
    using iterator2 = TreeMapIterator;  //alias cada ves q diga iterator remplazon por Pair *

  public:
    ~TreeMap()
    {
        podar(root);
        delete comparator;
    }

    TreeMap() : root{nullptr}
    {                                         //no se puede instanciar un objeto con new de la anterior forma
        comparator = new DefaultComparator(); //tuve q acer asi
    }
    TreeMap(const IComparator * c) : root{nullptr}
    {                                   //no se puede instanciar un objeto con new de la anterior forma
        comparator = (IComparator *)c; //COMO EL C ES = CONST ICOMPARATOR & LO TENGO Q CASTEAR A SOLO ICOMPARATOR *
    }

    // Poda: borrar todos los nodos a partir de uno, incluido
  private:
    void podar(Node *&nodo)
    {
        // Algoritmo recursivo, recorrido en postorden
        if (nodo)
        {
            podar(nodo->izq); // Podar izquierdo
            podar(nodo->der); // Podar derecho
            delete nodo;      // Eliminar nodo
            nodo = nullptr;
        }
    }

  public:

    int size(){
        return cantidad;
    }
    Pair * operator[](int x){
        return &pair[x];
    }

   /*  iterator begin()
    { //es el i = 0 masd o menos
        cout << "begin" << endl;
        llenarVectorInOrden(root);
        return &(pair[0]);
    } */

    iterator2 begin()
    { 
        llenarPila(root);
        auto aux = pila.ultimo->data;
        pila.pop();

        return iterator2{&pila,aux};
    }

    void llenarPila(Node *root)
    {
        auto aux = root;
        if (aux != nullptr)
        {
            llenarPila(aux->izq);
            Pair *p =new Pair{aux->data->key, aux->data->value};
            // pair[cantidad] = p;
            // cantidad++;
            pila.push(p);      
            llenarPila(aux->der);
            
        }
        

    }
    iterator2 end()
    {
        return iterator2{nullptr, nullptr}; //
    }

   /*  iterator end()
    {
        cout << "end" << endl;
        return &(pair[cantidad]); //
    } */

    void add(Object *key, Object *value)
    {
        Node *nn;
        Node *padre = nullptr;
        actual = root;

        nn = new Node(new Pair{key, value}); //ARREGLAR ESTO Q SOLO SE NEW CUANDO ESTEMOS SEGUROS DE ANADIR OSEA ABAJO
        // Buscar el int en el arbol, manteniendo un puntero al nodo padre
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
        // Si padre es NULL, entonces el arbol estaba vacio, el nuevo nodo sera
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
        inOrden(root);
        return "";
    }
    void inOrden(Node *root)
    {
        auto aux = root;
        if (aux != nullptr)
        {
            inOrden(aux->izq);
   
            cout << "key: " << aux->data->key->toString() << " data: " << aux->data->value->toString() << endl;

            inOrden(aux->der);
        } /* fin de if */

        //return v;
    }

    void remove(Integer iobj)
    {
        Node *padre = nullptr;
        actual = root;
        Node *nodo;
        auto aux = new Pair();

        CIComparator *cicomp = dynamic_cast<CIComparator *>(comparator);
        Object *obj = &iobj;
        const int num = iobj.i;
        //std::cout << "unoo " <<num<<"  333"<< '\n';
        if (cicomp)
        {
            //std::cout << "entre cicom1" << '\n';
            obj = new CI(num, "prueba");
            //std::cout << "entre cicom3" <<obj->toString()<<"  333"<< '\n';
        }
        // Mientras sea posible que el valor esta en el arbol
        while (!vacio(actual))
        {
            if (comparator->compare(root->data->key, obj) == 0 && esHoja(root))
            {
                //delete root;
                root = nullptr;
                delete aux;
                return;
            }
            //cout <<" wh"<< '\n';
            if (comparator->compare(actual->data->key, obj) == 0) //// o tendria q hacer con el compare
            {                                                     // Si el valor esta en el nodo actual
                                                                  //   cout <<" 1.0"<< '\n';
                if (esHoja(actual))
                {
                    //    cout <<" 1.1"<< '\n';
                    // Y si adem�s es un nodo hoja: lo borramos
                    if (padre)
                    { // Si tiene padre (no es el nodo raiz)
                        // Anulamos el puntero que le hace referencia
                        //      cout <<" 1.2"<< '\n';

                        if (padre->der == actual)
                        {
                            padre->der = nullptr;
                            //         cout <<" 1.3"<< '\n';
                        }
                        else if (padre->izq == actual)
                        {
                            //         cout <<" 1.4"<< '\n';
                            padre->izq = nullptr;
                        }
                    }
                    // cout <<" 1.5"<< '\n';

                    delete[] actual; // Borrar el nodo //////////////////////////////////
                    actual = nullptr;
                    delete aux;
                    std::cout << "termine remove 1" << '\n';
                    return;
                }
                else
                { // Si el valor est� en el nodo actual, pero no es hoja
                    // Buscar nodo
                    //cout <<" 2.0"<< '\n';

                    padre = actual;
                    // Buscar nodo mas izquierdo de rama derecha
                    if (actual->der)
                    {
                        //cout <<" 2.1"<< '\n';
                        nodo = actual->der;
                        while (nodo->izq)
                        {
                            //cout <<" wh 2.2"<< '\n';

                            padre = nodo;
                            nodo = nodo->izq;
                        }
                    }
                    // O buscar nodo mas derecho de rama izquierda
                    else
                    {
                        //cout <<" 2.3"<< '\n';
                        nodo = actual->izq;
                        while (nodo->der)
                        {
                            //cout <<"wh 2.4"<< '\n';
                            padre = nodo;
                            nodo = nodo->der;
                        }
                    }
                    // Intercambiar valores de no a borrar u nodo encontrado
                    // y continuar, cerrando el bucle. El nodo encontrado no tiene
                    // por que ser un nodo hoja, cerrando el bucle nos aseguramos
                    // de que selo se eliminan nodos hoja.
                    aux->key = actual->data->key;
                    aux->value = actual->data->value;

                    actual->data->key = nodo->data->key;     //cambiamos el valor actual ahora vale lo de nodo
                    actual->data->value = nodo->data->value; //cambiamos el valor actual ahora vale lo de nodo

                    nodo->data->key = aux->key;
                    nodo->data->value = aux->value;

                    actual = nodo;
                }
            }
            else
            { // Todavia no hemos encontrado el valor, seguir buscandolo
                //cout <<" 3.0"<< '\n';

                padre = actual;
                if (comparator->compare(obj, actual->data->key) > 0)
                {
                    //cout <<" 3.1"<< '\n';
                    actual = actual->der;
                }
                else if (comparator->compare(obj, actual->data->key) < 0)
                {
                    //cout <<" 3.2"<< '\n';
                    actual = actual->izq;
                }
            }
        }
        std::cout << "termine remove" << '\n';
    }

    bool update(const Object * key,const Object * newValue )
    { //el q use la funcion elije q acer con el objeto
        std::cout << "update"<< '\n';
        
        actual = root;

        Object *copia;

        Integer * in = dynamic_cast<Integer *>((Object *)key);
        CI * ci = dynamic_cast<CI *>((Object *)key);        
        if(in){
            const int num = in->i;
            copia = new Integer{num};
        }else{
            const int nit = ci->nit;
            const string city = ci->city;
            copia = new CI{nit, city};
        }

        //CIComparator *cicomp = dynamic_cast<CIComparator *>(comparator);

        //std::cout << "1"<< '\n';

        while (!vacio(actual))
        {
        //std::cout << "2"<< '\n';
        
            if (comparator->compare(copia, actual->data->key) == 0){
                //std::cout << "3"<< '\n';
                actual->data->value = nullptr;
                delete actual->data->value;
                actual->data->value = (Object *)newValue;
        
                return true; // int encontrado
            }
            else if (comparator->compare(copia, actual->data->key) > 0){
                //std::cout << "4"<< '\n';                
                actual = actual->der; // Seguir
            }
            else if (comparator->compare(copia, actual->data->key) < 0){
                //std::cout << "5"<< '\n';
                
                actual = actual->izq;
            }
        }
        //std::cout << "6"<< '\n';        
        return false; // No esta en arbol
    }

    bool vacio(Node *root)
    {
        return root == nullptr;
    }
    bool esHoja(Node *r) { return !r->der && !r->izq; }

    Object *operator[](const Object &key)
    { //el q use la funcion elije q acer con el objeto
        actual = root;
        
        Object *copia;

        Integer * in = dynamic_cast<Integer *>((Object *)&key);
        CI * ci = dynamic_cast<CI *>((Object *)&key);        
        if(in){
            const int num = in->i;
            copia = new Integer{num};
        }else{
            const int nit = ci->nit;
            const string city = ci->city;
            copia = new CI{nit, city};
        }
        
        while (!vacio(actual))
        {
            if (comparator->compare(copia, actual->data->key) == 0)
                return actual->data->value; // int encontrado
            else if (comparator->compare(copia, actual->data->key) > 0)
                actual = actual->der; // Seguir
            else if (comparator->compare(copia, actual->data->key) < 0)
                actual = actual->izq;
        }
        return new String("no hay"); // No est� en �rbol
    }

    /*  public:
    using iterator = TreeMapIterator; */
};
//********************************END TREEMAP**********************************************

int main()
{
    std::cout << "*****************************************************"
              << "\n";

    TreeMap M1;
    M1.add(new Integer(2), new String("dos"));
    M1.add(new Integer(4), new String("cuatro"));
    M1.add(new Integer(0), new String("cero"));
    std::cout << "ini rostring" << '\n';
    cout << M1.toString() << endl;
    std::cout << "ini remove" << '\n';
    //M1.remove(Integer{0}); //AQUI SE CUELGA SI LLAMAMOS AL REMOVE FALTA SOLUCIONAR ESTE METODO
    std::cout << "ini remove" << '\n';
    //M1.remove(Integer{4}); //AQUI SE CUELGA SI LLAMAMOS AL REMOVE FALTA SOLUCIONAR ESTE METODO
    std::cout << "ini tostring" << '\n';
    cout << M1.toString() << endl;
    std::cout << "ini remove" << '\n';
    //M1.remove(Integer{2}); //AQUI SE CUELGA SI LLAMAMOS AL REMOVE FALTA SOLUCIONAR ESTE METODO

    std::cout << "ini tostring" << '\n';
    cout << M1.toString() << endl;
    std::cout << "************************OPERATOR [] INTEGER*****************************"<<endl;    
    cout << M1[Integer{4}]->toString() << endl; //implementar operatror []  //accedo a la valor con la llave 4
    std::cout << "************************FIN OPERATOR INTEGER []*****************************"<<endl; 


    CIComparator *n = new CIComparator();
    TreeMap M(new CIComparator());
    M.add(new CI(15, "cbba1"), new String("NAME15"));
    M.add(new CI(10, "cbba2"), new String("NAME10"));
    M.add(new CI(9, "cbba2"), new String("NAME9"));
    M.add(new CI(6, "cbba2"), new String("NAME6"));
    M.add(new CI(5, "cbba3"), new String("NAME5"));
    M.add(new CI(4, "cbba3"), new String("NAME4"));
    M.add(new CI(13, "cbba3"), new String("NAME3"));

    std::cout << "************************OPERATOR [] CI*****************************"<<endl;    
    cout << M[CI{5,"cbba5"}]->toString() << endl; //implementar operatror []  //accedo a la valor con la llave 4
    std::cout << "************************FIN OPERATOR CI []*****************************"<<endl; 

    
    std::cout << "***********ITERATOR CI******************************************"
              << "\n";
    for (auto &p : M) //SI ARRIBA ES NODE ** ESTO ES LO Q DEVUELVE AL FOR NODE * &
    {                 //TENEMOS Q ACER ITERADOR EN EL TreeMap  //llamar al destructor borrar nodos los objetos de ;los nodeos y el comparador
        cout << p.key->toString() << " - ";
        cout << p.value->toString() << endl;
    }

    std::cout << "***********ITERATOR integer******************************************"
              << "\n";
    for (auto & p : M1) //SI ARRIBA ES NODE ** ESTO ES LO Q DEVUELVE AL FOR NODE * &
    {                 //TENEMOS Q ACER ITERADOR EN EL TreeMap  //llamar al destructor borrar nodos los objetos de ;los nodeos y el comparador
        cout << p.key->toString() << " - ";
        cout << p.value->toString() << endl;
    }
    

    std::cout << "***********For normal******************************************"
    << "\n";
    /* for (int i =0 ; i<M.size(); i++) //SI ARRIBA ES NODE ** ESTO ES LO Q DEVUELVE AL FOR NODE * &
    {                 //TENEMOS Q ACER ITERADOR EN EL TreeMap  //llamar al destructor borrar nodos los objetos de ;los nodeos y el comparador
        cout << M[i]->key->toString() << " - ";
        cout << M[i]->value->toString() << endl;
    
    } */

    std::cout << "***********Fin For normal**************************************"<<endl;

    std::cout << "***********Update Integer**************************************"<<endl;

    //M[Integer{4}]->toString() ;
    cout << M1.toString() << endl;
    cout<<M1.update(new Integer {0},new String{"ziro"})<<endl;
    cout << M1.toString() << endl;
    
    cout << M1.toString() << endl;
    cout<<M1.update(new Integer {4},new String{"cuatro Actualizado"})<<endl;
    cout << M1.toString() << endl;


    std::cout << "***********Update CI**************************************"<<endl;
    cout << M.toString() << endl;
    cout<<M.update(new CI {5,"cbba5"},new String{"topo5 actual"})<<endl;
    cout << M.toString() << endl;
    //M.update(new CI {0,"cbba1"},new String{"ziro"});
    

    return 0;
}

/*  TreeMap M;//TODO ORIENTADO A OBJETOS
    //          key             value
    m.add(new Integer(2), new String("dos"));
    m.add(new Integer(4), new String("cuatro"));
    m.add(new Integer(0), new String("cero"));
    cout<<m.toString()<<endl;
    m.remove(Integer {0});
    m.update(Integer {0},new String{"ziro"});
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