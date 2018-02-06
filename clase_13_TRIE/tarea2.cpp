#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template<class T>
struct trieNode{

    T data;
    char *key = nullptr;
    trieNode *children[26];   //26 es numero de letras

    trieNode(){
        memset(children, 0, 26*sizeof(trieNode*));
    }

public:
    ~trieNode(){
        delete key;

    }
};

template <class T>
struct mah{
public:
    T  & s;  //es una referencia al puntero  con  &
    mah(T  & s):s{s}{
        // delete s;
    }
    void operator=(T p){
        s=p;
    }
    T  operator->(){
    return s;
    }
};

template <class T>
class trie{
    trieNode <T> root;
    public:
    T  operator[](const char * k) const {
        T aux = find(k);
        return aux;
    }
    mah<T> operator[](const char * k){
        insert(k ,-1);
        T aux = find(k);
        return mah<T>{aux};
    } 
private:
    void insert( trieNode<T>& n , const char* k, const T  v, int lenk){
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

    static void setData(trieNode<T>& n, const T v, const char* k){
        n.data = (T)v;
        auto lenk = strlen(k);
        auto nsk =new char [lenk +1];
        memcpy(nsk, k, lenk+1);
        n.key = nsk;
    }

    T find (const trieNode<T>& n, const char* s)const {
        if(*s == 0){
            return n.data;
        }
        auto index= *s-'a';
        auto e = n.children[index];
        cout<<(char)(index+'a');
        if (e == nullptr){
            return -1;
        }
        return find(*e, s+1);
    }

    void print_prefix( const trieNode<T>& nodo, const char *c, int len)const{
        if(nodo.data > 0){
            bool igual = true;
            for (int i = 0; i < len ; ++i){
                if (c[i] != nodo.key[i]){
                    igual = false;
                    break;
                }
            }
        	if (igual){
                cout<<nodo.key<< " - "<<nodo.data<<endl;;
            }
        }else{

            for (int i = 0; i < 26; ++i){
                if (nodo.children[i] != nullptr){
                    print_prefix(*nodo.children[i], c, len);
                }
            }
        }

    }


public:
    trie& insert(const char* k, const T v ){
        int lenk = strlen(k);
        insert(root, k, v, lenk);
        return *this;

    } 

    void print() const{
        char vec[26];
        printAll(root);
    }

    void printAll(const trieNode<T>& nodo) const{
        if(nodo.data > 0){
            cout<<nodo.key<<" - ";
            cout<<nodo.data<<endl;
        }else{
            for (int i = 0; i < 26; ++i){
                if (nodo.children[i] != nullptr){
                    printAll(*nodo.children[i]);
                }
            }
        }
    }

    void print_prefix(const char* c)const{
		cout<<"1"<<endl;		
        int len = strlen(c);
        print_prefix( root, c, len);
		cout<<"1"<<endl;		
		
    }
    


    T find(const char* s) const{
        return find(root, s);
    }

    ~trie(){

        for (int i = 0; i < 26; ++i){
            delete root.children[i];			
        }
    }	


};


int main(){

	trie<int> s;//o(n)  n elementos de la palabra

    s.insert("diez", 10);
    s.insert("dieciocho", 18);
    s.insert("diecinueve", 19); 
    s.insert("veitedos", 22); 
    
    s["veinte"] = 20;
    s["veintiuno"] = 21;
 
	s.print();
    cout<<"********************"<<endl;
	s.print_prefix("die");
    int a;
    cout<<"a: "<<a<<endl;


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
  for (auto& i : s) { cout << i.second  << "\n"; }
} */