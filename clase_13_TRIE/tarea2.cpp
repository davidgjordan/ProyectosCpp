#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template<class T>
struct trieNode{

    T  * second=nullptr;
    char *first = nullptr;
    trieNode *children[26];   //26 es numero de letras

    trieNode(){
        memset(children, 0, 26*sizeof(trieNode*));
    }

public:
    ~trieNode(){
        delete first;
        delete second;

    }
};

template<class V>
struct trieNodeR{
    char *first = nullptr;    
    V  second;
    trieNodeR(char *first , V second):first{first}, second{second}{
    }

public:
    ~trieNodeR(){
        delete first;
    }
};

template <class T>
struct mah{
public:
    T & s;  //es una referencia al puntero  con &
    mah(T & s):s{s}{
        // delete s;
    }
    void operator=(const T p){
        //delete s;
        s = p;
    }
    T operator->(){
    return s;
    }
};




template <class T>
class trie{
    trieNode <T> root;
    public:
    using iterator =  trieNode <T> *;
    /* T & operator[](const char * k) const {
        T * aux = findR(k);
        return *aux;
    }    */
    mah<T> operator[](const char * k){
        
        insert(k ,-5);
        return mah<T>(findR(k));
    }   
private:
    void insert( trieNode<T>& n , const char* k, const T * v, int lenk){
        if (*k == 0){
            k-=lenk;
            setData(n,v, k);
            return;
        }

        auto index = *k - 'a';
        auto& e = n.children[index];
        if (e == nullptr){
            e= new trieNode<T>();
        }

        insert(*e, k+1, v, lenk);
    }

    static void setData(trieNode<T>& n, const T * v, const char* k){
        n.second = (T *)v;
        auto lenk = strlen(k);
        auto nsk =new char [lenk +1];
        memcpy(nsk, k, lenk+1);
        n.first = nsk;
    }

    T & findR (const trieNode<T>& n, const char* s)const {
        if(*s == 0){
            return *n.second;
        }
        auto index= *s-'a';
        auto e = n.children[index];
        //cout<<(char)(index+'a');
        if (e == nullptr){
            return *n.second;//hjukhiughiuygi
        }
        return findR(*e, s+1);
    }

    void print_prefix_default( const trieNode<T>& nodo, const char *c, int len)const{
        if(nodo.second != nullptr){
            bool igual = true;
            int lenAux = strlen(nodo.first);
            for (int i = 0; i < len && i < lenAux; ++i){
                if (c[i] != nodo.first[i]){
                    igual = false;
                    break;
                }
            }
        	if (igual){
                cout<<nodo.first<< " - "<<*(nodo.second)<<endl;;
            }
        }else{

            for (int i = 0; i < 26; ++i){
                if (nodo.children[i] != nullptr){
                    print_prefix_default(*nodo.children[i], c, len);
                }
            }
        }

    }
//esta es la solucion
public:
    trie& insert(const char* k, const T & v ){
        int lenk = strlen(k);
        T * auxv = new T(v);
        insert(root, k, auxv, lenk);
        return *this;

    } 

    void print() const{
        printAll(root);
    }

    void printAll(const trieNode<T>& nodo) const{
        if(nodo.second != nullptr){
            cout<<nodo.first<<" - ";
            cout<<*(nodo.second)<<endl;
        }else{
            for (int i = 0; i < 26; ++i){
                if (nodo.children[i] != nullptr){
                    printAll(*nodo.children[i]);
                }
            }
        }
    }

    void print_prefix_default(const char* c)const{
        int len = strlen(c);
        print_prefix_default( root, c, len);
		
    }
    


    T  & findR(const char* s) const{
        return findR(root, s);
    }

    ~trie(){

        for (int i = 0; i < 26; ++i){
            delete root.children[i];			
        }
    }

    iterator find(const string& first){
        const char * aux = ( const char *)first.c_str();
        T s = findR(aux);
        if(s >0){/////////////////>0
            trieNode <T> * node = new trieNode <T>();
            node->first = (char *)first.c_str();
            node->second = new T(s);
            return node;
        }
        return nullptr;

        
    }
    iterator begin(){
        return nullptr;        
    }
    iterator end(){
        return nullptr;
    } 

    template <typename PROC>
    void iterate_by_prefixr( const trieNode<T>& nodo, const char *c, int len, PROC p )const{
        if(nodo.second != nullptr){
            bool igual = true;
            int lenAux = strlen(nodo.first);
            for (int i = 0; i < len && i < lenAux; ++i){
                if (c[i] != nodo.first[i]){
                    igual = false;
                    break;
                }
            }
        	if (igual){
                //cout<<nodo.first<< " - "<<*(nodo.second)<<endl;
                trieNodeR<T> nod{nodo.first, *(nodo.second)};
                p(nod);
            }
        }else{
            for (int i = 0; i < 26; ++i){
                if (nodo.children[i] != nullptr){
                    iterate_by_prefixr(*nodo.children[i], c, len, p);
                }
            }
        }
    } 
    
    template <typename PROC>
    void iterate_by_prefix(const string& prefix, PROC p){
        int len = prefix.size();
        const char * aux = ( const char *)prefix.c_str();
        iterate_by_prefixr( root, aux, len, p);
    }	
    
    


};


int main(){

	trie<int> s;//o(n)  n elementos de la palabra

    s.insert("diez", 10);
    s.insert("dieciocho", 18);
    s.insert("diecinueve", 19); 
    s.insert("veintidos", 22); 
    
    s["veinte"] = 20;
    s["veintiuno"] = 21;
    s["diez"] = 30;
 
	s.print();
    cout<<"********************"<<endl;
	s.print_prefix_default("vei");
    cout<<"********************"<<endl;

    s.iterate_by_prefix("die", [](auto& p)
    {
      cout << "Key: " << p.first << "; Value: " << (p.second) << "\n";
    });

    cout<<"********************"<<endl;

    auto it = s.find("veinte");
    if (it == s.end()) {
        cerr << "Not found\n"; 
    }else {
        cout << *(it->second) << "\n";
    }
	return 0;
}

/* 
template <typename T>
class trie
{
public:
  void insert(const string& key, const T& value);
  size_t size() const;
  T& operator[](const string& key); //if does not find it, creates it.
  iterator find(const string& key);
  iterator begin();
  iterator end();

  template <typename PROC>
  void iterate_by_prefix(const string& prefix, PROC p);
};

La idea es que dada una clave (siempre como string, dada la naturaleza del Trie), se pueda almacenar un valor de cualquier tipo T en el nodo específico.

int main()
{
  trie<int> s;
  s.insert("diez", 10);
  s.insert("dieciocho", 18);
  s.insert("diecinueve", 19);
  s["veinte"] = 20;
  s["veintiuno"] = 21;

  auto it = s.find("veinte");
  if (it == s.end()) cerr << "Not found\n"; else cout << it->second << "\n";

  //should iterate diez, dieciocho and diecinueve
  s.iterate_by_prefix(die", [](auto& p)
  {
    cout << "Key: " << p.first << "; Value: " << p.second << "\n";
  });

  cout << "****\n";

  // should get all items as pairs
  for (auto& i : s) { cout << i->second  << "\n"; }
} */