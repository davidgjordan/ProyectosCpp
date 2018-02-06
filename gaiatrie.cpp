/*Hace tiempo implementamos un TRIE en C.

Implementarlo a manera de mapa en C++:*/
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

template <typename T>
struct MapIterator
{
    map<string,T>* mapa;
    pair<string, T>* data;
    int pos;
    bool operator==(const MapIterator& m)
    {
      if (m.data == nullptr)
      {
        return data == m.data;
      }
      else
        return data->first.compare(m.data->first) && data->second == m.data->second;
    }

    bool operator!=(const MapIterator m)
    {
      return data != m.data;
    }

    const pair<string, T>& operator*()
    {
      return *data;
    }

    const pair<string, T>* operator->()
    {
      return data;
    }

    MapIterator& operator++()
    {
      auto it = mapa->begin();
      pos++;
      for (int i = 0; i < pos; ++i)
      {
        it++;
      }
      if (it == mapa->end())
      {
        data = nullptr;
        return *this;
      }
      else
      {
        data->first = it->first;
        data->second = it->second;
        return *this;
      }
    }

    ~MapIterator()
    {
      delete data;
    }
};

template <typename T>
class trie
{
  map<string,T> mapa;
  public:
    void insert(const string& key, const T& value)
    {
      mapa.insert(make_pair(key,value));
    }
    size_t size() const
    {
      return mapa.size();
    }
    T& operator[](const string& key) //if does not find it, creates it.
    {
        return mapa[key];
    }
    using iterator = MapIterator<T>;
    iterator find(const string& key)
    {
      auto it = mapa.find(key);
      if (it == mapa.end())
      {
        return MapIterator<T>{&mapa, nullptr, 0};
      }
      else
      {
        return MapIterator<T>{&mapa, new pair<string, T>{it->first, it->second}, 0};
      }
    }
    iterator begin()
    {
      auto it = mapa.begin();
      if (it == mapa.end())
      {
        return MapIterator<T>{&mapa, nullptr, 0};
      }
      else
      {
        return MapIterator<T>{&mapa, new pair<string, T>{it->first, it->second}, 0};
      }
    }

    iterator end()
    {
      return MapIterator<T>{&mapa, nullptr, 0};
    }

    template <typename PROC>
    void iterate_by_prefix(const string& prefix, PROC p)
    {
      vector<pair<string, T>> v;
      for (auto& i : mapa) 
      {
        size_t found = i.first.find(prefix);
        if (found!=string::npos)
          v.push_back(pair<string, T>{i.first, i.second});
      }
      for (auto& i : v) 
      { 
        p(i); 
      }
    }
};

/*La idea es que dada una clave (siempre como string, dada la naturaleza del Trie), 
se pueda almacenar un valor de cualquier tipo T en el nodo específico.*/

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
  s.iterate_by_prefix("die", [](auto& p)
  {
    cout << "Key: " << p.first << "; Value: " << p.second << "\n";
  });

  cout << "****\n";

  // should get all items as pairs
  for (auto& i : s) { cout << i.second  << "\n"; }

  /*for (auto& i = hm.begin(); i != hm.end(); ++i)
  {
    
  }*/
}