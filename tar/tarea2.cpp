#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Base
{
  public:
    virtual string toString() const = 0;
    virtual bool equals(const Base &) const = 0;
};
class Object : public virtual Base
{
  public:
    string toString() const
    {

        char res[25];
        printf(res, "Object@%p", this);
        return res;
    }
    bool equals(const Base &b) const
    {
        return this == &b;
    }
};

class IInterface : public virtual Base
{
};

class IComparable : public virtual IInterface
{
  public:
    virtual int compareTo(const IComparable &) const = 0;
};

class IComparator : public virtual IInterface
{
  public:
    virtual int compare(const Object &, const Object &) const = 0;
};

class String : public virtual Object, public virtual IComparable
{

    string data;

  public:
    String(string data) : data{data}
    {
    }

    string toString() const
    {
        return data;
    }
    bool equals(const Base &b) const
    {
        return this == &b;
    }

    int compareTo(const IComparable &comparable) const
    {
        const String *aux = dynamic_cast<const String *>(&comparable);
        return data.compare(aux->data);
    }
};

class Integer : public virtual Object, public virtual IComparable
{
  public:
    int data;

  public:
    Integer(int data) : data{data}
    {
    }

    string toString() const
    {
        return to_string(data);
    }
    bool equals(const Base &b) const
    {
        return this == &b;
    }

    int compareTo(const IComparable &comparable) const
    {
        const Integer *aux = dynamic_cast<const Integer *>(&comparable);
        return data - aux->data;
    }
};

class CI : public virtual Object
{

    int nit;
    string city;

  public:
    CI(const int &nit, const string &city) : nit{nit}, city{city}
    {
    }
    int getNit()
    {
        return nit;
    }
    string getCity()
    {
        return city;
    }

    string toString() const
    {
        return to_string(nit);
    }
    bool equals(const Base &b) const
    {
        return this == &b;
    }

    int compareForNit(CI &comparator1)
    {
        //const   CI * aux = dynamic_cast<const CI*> (&comparator1);
        return nit - comparator1.getNit();
    }

    int operator-(CI &comparator)
    {
        return nit - comparator.nit;
    }
};

class DefalutComparator : public virtual Object, public virtual IComparator
{
  public:
    DefalutComparator() {}
    string toString() const
    {
        char res[25];
        printf(res, "DefalutComparator%d", this);
        return res;
    }
    bool equals(const Base &b) const
    {
        return this == &b;
    }
    int compare(const Object &comparator1, const Object &comparator2) const
    {
        const Integer *aux1 = dynamic_cast<const Integer *>(&comparator1);
        const Integer *aux2 = dynamic_cast<const Integer *>(&comparator2);

        return aux1->compareTo(*aux2);
    }
};

class CIComparator : public virtual Object, public virtual IComparator
{
  public:
    string toString() const
    {
        char res[25];
        printf(res, "CIComparator%d", this);
        return res;
    }

    int compare(const Object &comparator1, const Object &comparator2) const override
    {
        CI *aux1 = dynamic_cast<CI *>(&((Object &)comparator1));
        CI *aux2 = dynamic_cast<CI *>(&((Object &)comparator2));
        //const CI * aux1 = dynamic_cast<const CI *>(&comparator1);
        //const CI * aux2 = dynamic_cast<const CI *>(&comparator2);
        return aux1->compareForNit(*aux2);
        //return aux1-aux2;
    }
};

class Node
{
  public:
    Object *key; //TUVE PROBLEMAS POR Q NO ERAN PUNTEROS MEJOR PUNTEROS
    Object *value;
    Node *izq;
    Node *der;

    
    Node(const Object *key, const Object *value, Node *izq = nullptr, Node *der = nullptr) : key{(Object *)key}, value{(Object *)value}, izq{izq}, der{der}
    {
    }
};

class TreeMap : public virtual Object
{

    Node *root;
    IComparator *comparator;
    //Pair pair[50];

    int cantidad = 0;
    //using iterator = Pair *; 

  public:
    ~TreeMap()
    {
        podar(root);
        delete comparator;
    }
    TreeMap() : root{nullptr}
    {
        comparator = new DefalutComparator();
    }

    TreeMap(IComparator *comparator) : root{nullptr}, comparator{comparator} {}

    void add(const Object *key, const Object *value)
    {
        /* if(!root){
            root = new Node{(key),(value)};
        } */
        auto actual = root;
        Node *padre = nullptr;
        while (!isEmpty(actual) && comparator->compare(*(key), *(actual->key)) != 0)
        {
            padre = actual;
            if (comparator->compare(*(key), *(actual->key)) > 0)
            {
                actual = actual->der;
            }
            else if (comparator->compare(*(key), *(actual->key)) < 0)
            {
                actual = actual->izq;
            }
        }
        if (!isEmpty(actual))
        {
            //cout<<"entre add 5 "<<endl;
            return;
        }
        if (isEmpty(padre))
        { //siempre tendriamos q tener un padre si no el arbol estaria vacio
            root = new Node{(key), (value)};
        }
        else if (comparator->compare(*(key), *(padre->key)) < 0)
        {
            padre->izq = new Node{(key), (value)};
        }
        else if (comparator->compare(*(key), *(padre->key)) > 0)
        {
            padre->der = new Node{(key), (value)};
        }
    }

    string toString()
    {
        inOrden(root);
        return ""; ///ya q no concatena bien en string el inorden
    }
    
    void remove(Integer iobj)
    {
        Node *padre = nullptr;
        auto actual = root;
        Node *nodo;
        Object *key;
        Object *value;

        CIComparator *cicomp = dynamic_cast<CIComparator *>(comparator);
        Object *obj = &iobj;
        const int num = iobj.data;
        //std::cout << "unoo " <<num<<"  333"<< '\n';
        if (cicomp)
        {
            //std::cout << "entre cicom1" << '\n';
            obj = new CI(num, "prueba");
            //std::cout << "entre cicom3" <<obj->toString()<<"  333"<< '\n';
        }
        // Mientras sea posible que el valor esta en el arbol
        while (!isEmpty(actual))
        {
            if (comparator->compare(*(root->key), *obj) == 0 && isLeaf(root))
            {
                //delete root;
                root = nullptr;
                //delete aux;
                return;
            }
            //cout <<" wh"<< '\n';
            if (comparator->compare(*(actual->key), *obj) == 0) //// o tendria q hacer con el compare
            {                                                     // Si el valor esta en el nodo actual
                                                                  //   cout <<" 1.0"<< '\n';
                if (isLeaf(actual))
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
                    //delete aux;
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
                    key = actual->key;
                    value = actual->value;

                    actual->key = nodo->key;     //cambiamos el valor actual ahora vale lo de nodo
                    actual->value = nodo->value; //cambiamos el valor actual ahora vale lo de nodo

                    nodo->key = key;
                    nodo->value = value;

                    actual = nodo;
                }
            }
            else
            { // Todavia no hemos encontrado el valor, seguir buscandolo
                //cout <<" 3.0"<< '\n';

                padre = actual;
                if (comparator->compare(*obj, *(actual->key)) > 0)
                {
                    //cout <<" 3.1"<< '\n';
                    actual = actual->der;
                }
                else if (comparator->compare(*obj, *(actual->key)) < 0)
                {
                    //cout <<" 3.2"<< '\n';
                    actual = actual->izq;
                }
            }
        }
        std::cout << "termine remove" << '\n';
    }

    Object *operator[](const Object &src)
    { //el q use la funcion elije q acer con el objeto
        auto actual = root;
        Object *copia = (Object *)&src;
        // Todavia puede aparecer, ya que quedan nodos por mirar
        Integer *in = dynamic_cast<Integer *>(copia);
        CIComparator *cicomp = dynamic_cast<CIComparator *>(comparator);
        Object *obj = copia;
        const int num = in->data;
        //std::cout << "unoo " <<num<<"  333"<< '\n';
        if (cicomp)
        {
            //std::cout << "entre cicom1" << '\n';
            obj = new CI(num, "prueba");
            //std::cout << "entre cicom3" <<obj->toString()<<"  333"<< '\n';
        }
        while (!isEmpty(actual))
        {
        cout<<"manaa"<<endl;
            if (actual->key->equals(*obj))
                return actual->value; // int encontrado
            else if (comparator->compare(*obj, *(actual->key)) > 0)
                actual = actual->der; // Seguir
            else if (comparator->compare(*obj, *(actual->key)) < 0)
                actual = actual->izq;
        }
        return new String("no hay"); // No est� en �rbol
    }
  private:
    bool isEmpty(Node *node)
    {
        return node == nullptr;
    }
    bool isLeaf(Node * node){
        return !node->izq && !node->der; 
    }
    void inOrden(Node *node)
    {
        auto aux = node;
        //string res;
        if (aux != nullptr)
        {
            inOrden(aux->izq);
            cout << "key: " << aux->key->toString() << "  value: " << aux->value->toString() << endl;
            /* res+="key: ";
            res+=aux->key->toString();
            res+=" value: ";            
            res+=aux->value->toString();
            res+=+"\n"; */
            inOrden(aux->der);
        }
        //return res;
    }

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

    // iterator /* Pair ** */ begin()
    // { //es el i = 0 masd o menos
    //     cout << "begin" << endl;
    //     llenarVectorInOrden(root);
    //     return &(pair[0]);
    // }

    // void llenarVectorInOrden(Node *root)
    // {
    //     auto aux = root;
    //     if (aux != nullptr)
    //     {
    //         llenarVectorInOrden(aux->izq);
    //         Pair p =Pair{aux->key, aux->value};
    //         pair[cantidad] = p;
    //         cantidad++;
    //         llenarVectorInOrden(aux->der);
    //     }

    // }

    // iterator /* Pair ** */ end()
    // {
    //     cout << "end" << endl;
    //     return &(pair[cantidad]); //
    // }
};

int main()
{
    DefalutComparator d;
    //cout<<d.compare(String{"a"},String{"b"})<<endl;
    //cout<<d.compare(String{"b"},String{"a"})<<endl;
    cout << d.compare(Integer{57}, Integer{1}) << endl;
    cout << d.compare(Integer{57}, Integer{100}) << endl;

    CIComparator c;
    cout << "nit " << c.compare(CI{1, "cbba1"}, CI{2, "cbba2"}) << endl;
    cout << "***************************************************" << endl;

    TreeMap m;
    m.add(new Integer(10), new String("diez"));

    m.add(new Integer(8), new String("ocho"));
    m.add(new Integer(12), new String("doce"));
    m.add(new Integer(4), new String("cuatro"));
    //m.add(new Integer(16), new String("dieciseis"));
    cout << "*****************tooo**********************************" << endl;

    cout << m.toString() << endl;

    cout << "*****************remove**********************************" << endl;
    cout << "*****************remove**********************************" << endl;

    m.remove(Integer{4});
    m.remove(Integer{10});
    cout << m.toString() << endl;
    cout << "*****************remove**********************************" << endl;
    
    cout<<m[Integer{12}]->toString()<<endl;//implementar operatror []  //accedo a la valor con la llave 4

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