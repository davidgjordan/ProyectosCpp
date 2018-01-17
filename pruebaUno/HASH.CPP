//La herencia virtual, une todos los parametros y los junta los que son iguales para que no haya datos dobles
#include <iostream>
#include <cstring>

using namespace std;

class Base
{
public:
virtual string toString() const = 0;
virtual bool equals(const Base& s) const = 0;
virtual size_t getHashCode() const = 0;
virtual ~Base(){}
};

class IInterface : public virtual Base
{

};

class IComparable : public virtual IInterface
{
public:
virtual int compareTo(const IComparable& c) const = 0;
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
bool equals(const Base& s) const override
{
return this == &s;
}
size_t getHashCode() const override
{
return reinterpret_cast<size_t> (this);
}
};

class String final : public virtual Object, public virtual IComparable
{
string s;
public:
String(const string& s) : s{s}
{

}
string toString() const override
{
return s;
}
bool equals(const Base& q) const override
{
auto& src = dynamic_cast<const String&> (q);
return s == src.s;
}
size_t getHashCode() const override//un codigo hash, es una representacion numerica de un objeto
{
std::hash<string> hs;
return hs(s);//es un functor
}
int compareTo(const IComparable& src) const override
{
auto& q = dynamic_cast<const String&>(src);
return s.compare(q.s);
}
};

struct Pair
{
Object* key;
Object* value;
Pair* next;
};

struct PairLL//pair linked list
 {
  Pair *first, *last;
  PairLL():first{nullptr}, last{nullptr}
  {

  }
  void add(Pair* nn)
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
PairLL** data;
size_t cap;
size_t pos;
Pair* p;//va a apuntar al siguiente valor valido,o si es null
bool operator!=(const HashMapIterator src) const
{
return p != src.p;
}
const Pair& operator*() const
{
return *p;
}
/*const Pair* operator*() const
{
return p;
}*/
HashMapIterator& operator++()
{
if(p->next != nullptr)
{
p = p->next;
return *this;
}
pos++;
p = findNext(data, cap, pos);
return *this;
}
static Pair* findNext(PairLL** data, size_t cap, size_t& pos)
{
if (pos >= cap)
{
return nullptr;
}
while(pos < cap)
{
if(data[pos] != nullptr)
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
double loadFactor;
size_t cap;
size_t n;
PairLL** data;
void add(PairLL** d, Pair* p, size_t ncap)
{
auto hc = p->key->getHashCode();
auto pos = hc % cap;
auto& slot = d[pos];
if(slot == nullptr)
slot = new PairLL();
slot->add(p);
}
void rehash()
{
cout << "REHASHSWING\n";
auto ncap = cap * 2 + 1;
auto ndata = new PairLL*[ncap];
memset(ndata, 0, ncap * sizeof(PairLL*));
for (auto i = 0; i < cap; ++i)
{
auto slot = data[i];
if(slot == nullptr) 
{
continue;
}
auto aux = slot->first;
while(aux != nullptr)
{
auto next = aux->next;
aux->next = nullptr;
add(ndata, aux, ncap);
aux = next;
}
}
for (auto i = 0; i < cap; ++i)
{
delete data[i];
}
cap = ncap;
delete [] data;
data = ndata;
}
public:
HashCode(size_t cap = 7, double loadFactor = 0.8) : loadFactor{loadFactor}, cap{cap}, n{0}, data{new PairLL*[cap]}
{
memset(data, 0, cap * sizeof(PairLL*));
}
void add(Object* key, Object* value)
{
auto p = new Pair{key, value, nullptr};
auto r = (double)n/(double)cap;
if(r > loadFactor)
rehash();
add(data, p, cap);
n++;
}
string toString() const override
{
string r;
for (auto i = 0; i < cap; ++i)
{
auto slot = data[i];
if(slot == nullptr)
continue;
auto aux = slot->first;
while(aux != nullptr)
{
r += aux->key->toString() + ": ";
auto val = aux->value;
r += (val == nullptr)?"null\\n" : val->toString() + "\n";
aux = aux->next;
}
}
return r;
}
Object* operator[](const Object& src) const
{
auto hc = src.getHashCode();
auto pos = hc%cap;
auto slot = data[pos];
if (slot == nullptr)
return nullptr;
auto aux = slot->first;
while(aux != nullptr)
{
if(aux->key->equals(src))
return aux->value;
aux = aux->next;
}
return nullptr;
}
using iterator = HashMapIterator;
iterator begin()
{
size_t pos = 0;
auto slot = data[0];
return HashMapIterator{data, cap, pos, slot->first};
}
iterator end()
{
size_t pos = cap;
return HashMapIterator{data, cap, pos, nullptr};
}
//friend struct HashMapIterator;//es para decir que una funcion o una clase es amiga e esta clase
~HashCode()
{
for (int i = 0; i < cap; ++i)
{
auto slot = data[i];
if(slot == nullptr) continue;
auto aux = slot->first;
while(aux != nullptr)
{
auto next = aux->next;
delete aux->key;
delete aux->value;
delete aux;
aux = next;
}
delete slot;
}
delete [] data;
}
};

int main()
{
String s {"hola"};
String a {"hola"};
cout << s.toString() << "\n";
cout << s.equals(a) << "\n";
cout << s.getHashCode() << "\n";
HashCode hm;
hm.add(new String("uno"), new String ("one"));
hm.add(new String("siete"), new String ("seven"));
hm.add(new String("hola"), new String ("hi"));
hm.add(new String("chau"), new String ("bye"));
hm.add(new String("dos"), new String ("two"));
hm.add(new String("cinco"), new String ("five"));
hm.add(new String("ocho"), new String ("eight"));
hm.add(new String("nueve"), new String ("nine"));
hm.add(new String("cuatro"), new String ("four"));
hm.add(new String("tres"), new String ("tree"));
//cout << hm.toString() << "\n";
String str{"siete"};
auto f1 = hm[str];
auto f2 = hm[String{"ocho"}];
if(f1)
cout << f1->toString() << "\n";
if(f2)
cout << f2->toString() << "\n";
for (auto& g : hm)
{
cout << g.key->toString() << endl;
}
/*for (std::vector<>::iterator& i = hm.begin(); i != hm.end(); ++i)
{
}
for (auto g : hm)
{
cout << g->key->toString() << endl;
}*/
}

