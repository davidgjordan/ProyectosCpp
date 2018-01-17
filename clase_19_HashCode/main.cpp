#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Base
{
  public:
    virtual ~Base() {} //es para q se llame al destuctor de sus hijos
    virtual string toString() const = 0;
    virtual bool equals(const Base &) const = 0;
    virtual size_t getHashCode() const = 0;
};

class IInterface : public virtual Base
{
};

class IComparable : public virtual IInterface
{ //todas son clases abstractas
  public:
    virtual int compareTo(const IComparable &) const = 0;
};

class Object : public virtual Base
{
  public:
    string toString() const override
    {
        char aux[32];
        sprintf(aux, "Object@%p", this);
        return aux;
    }
    bool equals(const Base &s) const override
    {
        return this == &s; //compara por su direccion de memoria
    }
    size_t getHashCode() const override
    {

        return reinterpret_cast<size_t>(this); //castea  de numero a puntero
    }
};

class String : public virtual Object, public virtual IComparable
{ /*la ultima de la jerarquia decimos*/

    string s;

  public:
    String(const string &s) : s{s}
    {
    }
    string toString() const override
    {

        return s; //devolvemos una copia
    }
    bool equals(const Base &q) const override
    {
        auto &src = dynamic_cast<const String &>(q);
        return s == src.s; //compara por su direccion de memoria
    }
    size_t getHashCode() const override
    {
        std::hash<string> hs;

        return hs(s); //es un objeto pero lo estqamos llamando como una funcion es raro pero posuible
    }

    int compareTo(const IComparable &src) const override
    {

        auto &q = dynamic_cast<const String &>(src);

        return s.compare(q.s);
    }
};

//*****************
struct Pair
{
    Object *key;
    Object *value;

    Pair *next;
};
struct PairLL
{
    Pair *first, *last;
    // Pair * last;
    PairLL() : first{nullptr}, last{nullptr}
    {
    }
    void add(Pair *nn)
    {
        if (first == nullptr)
        {
            first = last = nn;
            return;
        }
        last->next = nn;
        last = nn;
    }
};

struct HashMapIterator
{
    PairLL **data;
    size_t cap;
    size_t pos; //apunta a la posicion
    Pair *p;    //apunta siempre al siguietne elemento valido de la lista
   /*  HashMapIterator(PairLL **data,size_t cap,size_t pos,Pair *pair):data{data},cap{cap},pos{pos}{//ESTE CONSTRUCTPOR OPCIONAL 
        p = findNext(data, cap, pos);                                                       //POR SI NO SE INSTANCIA BIEN EL PAIR
        pair = p;
    } */
    bool operator!=(const HashMapIterator &src)
    {
        return p != src.p;
    }
    const Pair &operator*() const
    {
        return *p;
    }
    HashMapIterator &operator++()
    { //es el prefijo ++i no el postfijo
        if (p->next != nullptr)
        {
            p = p->next;
            return *this;
        }
        pos++;
        p = findNext(data, cap, pos);

        return *this;
    }
    static Pair *findNext(PairLL **data, size_t cap, size_t &pos)
    {
        if (pos >= cap)
        {
            return nullptr;
        }
        while (pos < cap)
        {
            if (data[pos] != nullptr)
            {
                return data[pos]->first;
            }
            pos++;
        }
        return nullptr;
    }
};

class HashCode : public Object
{
    double loadFactor; //para ver si ya se esta llenando la lista
    size_t cap;        //capacidad
    size_t n;          //cantidad de datos
    PairLL **data;     //
    using iterator = HashMapIterator;
  public:
    HashCode(size_t cap = 7, double loadFactor = 0.8) : loadFactor{loadFactor}, n{0}, cap{cap}, data{new PairLL *[cap]}
    {

        memset(data, 0, cap * sizeof(PairLL *));
    }

    void add(Object *key, Object *value)
    {
        auto p = new Pair{key, value, nullptr};
        auto r = (double)n / (double)cap;
        if (r >= loadFactor)
        {
            cout << "Rehash add" << endl;
            rehash(); //division del numero de elementos con la cap
        }
        add(data, p, cap);
        n++;
    }

  private:
    void rehash()
    {
        cout << "Rehash" << endl;
        auto ncap = cap * 2 + 1;
        auto ndata = new PairLL *[ncap];

        memset(ndata, 0, ncap * sizeof(PairLL *));

        for (auto i = 0; i < cap; i++)
        {
            //PairLL * slot
            auto slot = data[i];
            if (slot == nullptr)
                continue;
            auto aux = slot->first; //aux es Pair *
            while (aux != nullptr)
            { //mientras eas diferente de null lo anado al otro array
                auto next = aux->next;
                aux->next = nullptr;
                add(ndata, aux, ncap); ///con la nueva capacidad obtengo la nueva lista de hash
                aux = next;
            }
        }
        for (auto i = 0; i < cap; i++)
        {
            delete data[i];
        }
        cap = ncap;
        delete[] data;
        data = ndata;
    }

  public:
    string toString() const override
    {
        string r;
        for (auto i = 0; i < cap; i++)
        {
            auto slot = data[i];
            if (slot == nullptr)
                continue; //si el elemento en esta pocicion es null continuo

            auto aux = slot->first; //apunto al primer alemento de mi lita

            while (aux != nullptr)
            {
                r += aux->key->toString() + " ";

                auto nl = aux->value;
                r += (nl == nullptr) ? " nullptr " : nl->toString() + "\n";

                aux = aux->next;
            }
        }
        return r;
    }

    Object *operator[](const Object &src) const
    { //el q use la funcion elije q acer con el objeto
        auto hc = src.getHashCode();

        auto pos = hc % cap;
        auto slot = data[pos];
        if (slot == nullptr)
            return nullptr; //si el slot es null no existe si no
        //si no es nulo entro a la lista y recorro asta en contrar el object
        auto aux = slot->first;
        while (aux != nullptr)
        {
            if (aux->key->equals(src))
            {
                return aux->value;
            }
            aux = aux->next;
        }
        return nullptr;
    }

  private:
    void add(PairLL **d, Pair *p, size_t cap)
    {
        auto hc = p->key->getHashCode(); //saca hascode
        auto pos = hc % cap;             //obtengo la pocision
        auto &slot = d[pos];             //asi saco una refercnia de esa posicion el la tabla hasc
        if (slot == nullptr)
        {
            slot = new PairLL(); //si el slot es nulo creo otro
        }
        //si no anado directamente
        slot->add(p);
    }

  public:
    ~HashCode()
    {
        for (auto i = 0; i < cap; i++)
        {
            auto slot = data[i];
            if (slot == nullptr)
                continue;
            auto aux = slot->first;
            while (aux != nullptr)
            {
                auto next = aux->next;
                delete aux->key;
                delete aux->value;
                delete aux;
                aux = next;
            }
        }
        delete[] data;
    }
    // using iterator = HasMapIterator;//clase hasiterator deve implemetntar el operdor ++ * !=

    // ++ si este apunta a null encuentro el siguiente value_op_iterator
    // * nos devuelve el un par(un object)
    // y el != para el
    // //implemtar el iterator begin(){
    //     return //el iterador deberia apuntar al primer elemento y end al ultimo
    // }
    // //implemtar el iterator end(){} //para q de
    // //acer
    // for(auto & p:hm){
    // //mostara
    //     p.key->toString
    // }

    
    iterator begin()
    {
        size_t pos = 0;
        auto dataAux = data[0];//PairLL*
        return iterator{data, cap, pos, dataAux->first};
    }

    iterator end()
    {
        size_t pos = cap;
        return HashMapIterator{data, cap, pos, nullptr};
    }

    
  public: //frien sirve para decir q una funcio o clase es amiga de esta clase
    //  es amiga si tiene acceso a todo lo protected y privado de esta clase
    //con esto le damos acceso a todo
    //friend struct HashMapIterator;
    
};

int main()
{

    // String s{"Hola"};
    // cout<<s.toString()<<endl;

    HashCode hm;
    hm.add(new String("unoo"), new String("one"));
    hm.add(new String("dos"), new String("two"));
    hm.add(new String("tres"), new String("three"));
    hm.add(new String("cuatro"), new String("four"));
    hm.add(new String("cinco"), new String("five"));
    hm.add(new String("seis"), new String("six"));
    hm.add(new String("siete"), new String("seven"));
    hm.add(new String("ocho"), new String("eicht"));
    hm.add(new String("nueve"), new String("nine"));
    hm.add(new String("diez"), new String("ten"));
    cout << hm.toString() << endl;

    cout << "**********fooor*************" << endl;

    for (auto i :hm)
    {
        std::cout << i.key->toString() << '\n';
    } 
    cout << "***************fin fooor********" << endl;

    /* for(Pair & i = iterator.begin();i!= iterator.end(); i++ ){

    } */

    String s{"siete"};
    auto f1 = hm[s];
    auto f2 = hm[String{"uno"}];

    if (f1)
        cout << f1->toString() << endl;
    if (f2)
        cout << f2->toString() << endl;

    return 0;
}


