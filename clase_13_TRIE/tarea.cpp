#include <iostream>
#include <cstring>
#include <string>
#include <map> 
#include <set>

using namespace std;



//Hace tiempo implementamos un TRIE en C.

//Implementarlo a manera de mapa en C++:

/* template <class U>
class node{
    U data;

    node(U & data):data{data}{
    }
};
 */
  template <typename T>
  struct TrieIterator
  {   
      map<string , T>  m;
      //pair<string, T> par;
      std::map<string, int>::iterator it = m.begin();
        //apunta siempre al siguietne elemento valido de la lista
     /*  HashMapIterator(PairLL **data,size_t cap,size_t pos,Pair *pair):data{data},cap{cap},pos{pos}{//ESTE CONSTRUCTPOR OPCIONAL 
          p = findNext(data, cap, pos);                                                       //POR SI NO SE INSTANCIA BIEN EL PAIR
          pair = p;
      } */
      bool operator!=(const TrieIterator &src)
      {
          return par.first != src.par.first;
      }
      const pair<string , T> &operator*() const
      {
          return par;
      }
      TrieIterator &operator++()
      { //es el prefijo ++i no el postfijo
         auto ot = m.begin();
          if (ot != nullptr)
          {  
              par(ot.first, ot.second);
              m.erase(ot.first);
              return *this;
          }
          return nullptr;
      }
   
  };

template <typename T>
class trie
{
map<string , T>  m;
//auto iterator = m.begin();
//std::map<string,T>::iterator it;
using iterator = pair<string, T>;

public:
  void insert(const string& key, const T& value){
    //m[key] = value;
    m.insert(make_pair(key,value ));//intuye los tipos

  }
  size_t size() const{
    return m.size();
  }
  T& operator[](const string& key){//if does not find it, creates it.
    return m[key];
  } 
  
  /* std::map<string,T>::iterator find(const string& key){
      //std::map<char,int>::iterator it;
        auto it = m.find(key);
        if (it != m.end())
            m.erase (it);
        return it;
  } */


    iterator begin(){
    auto it = m.begin();
    return iterator{m , it};
  }
  iterator end(){
    return iterator{m , nullptr };      
 //   
  }   
  template <typename PROC>
  void iterate_by_prefix(const string& prefix, PROC p){
      auto tam = prefix.size();
      for(auto & node : m){
          bool res = true;
          for(size_t i = 0; i<tam && i<node.first.size(); i++){
            if(node.first[i] != prefix[i] ){
                res = false;
                break;
            }
          }
          if(res){
              p(node);
          }
      }
  }
};

//La idea es que dada una clave (siempre como string, dada la naturaleza del Trie), 
//se pueda almacenar un valor de cualquier tipo T en el nodo específico.

int main()
{
  trie<int> s;
  s.insert("diez", 10);
  s.insert("dieciocho", 18);
  s.insert("diecinueve", 19);
  s["veinte"] = 20;
  s["veintiuno"] = 21;

cout<<s.size()<<endl;
s.iterate_by_prefix("die", [](auto& p)
   {
     cout << "Key: " << p.first << "; Value: " << p.second << "\n";
   });
//   auto it = s.find("veinte");

   /* if (it == s.end()) cerr << "Not found\n"; else cout << it->second << "\n";
   //should iterate diez, dieciocho and diecinueve
   s.iterate_by_prefix("die", [](auto& p)
   {
     cout << "Key: " << p.first << "; Value: " << p.second << "\n";
   });
   cout << "****\n";
   // should get all items as pairs
 */
   /* for (auto& i : s) { 
       cout << i.second  << "\n"; 
     } */  

cout<<"***************"<<endl;
    map<string , int> m2;
    m2.insert(make_pair<string, int>("diez", 10));
    m2.insert(make_pair<string, int>("dieciocho", 18));
    m2.insert(make_pair<string, int>("diecinueve", 19));

    cout<<m2["diez"]<<endl;

    pair<string , int> par( m2["diez"].first ,m2["diez"].second );
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