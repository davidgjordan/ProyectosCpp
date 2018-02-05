#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template<class T >
struct trienode{
	T data;
	char * key = nullptr;
	trienode * children[26];//albabeto de 26 palabras
	trienode(){
		memset(children , 0 , 26*sizeof(trienode*)); //pone todos los bites de array al valor q yo le diga
	}
public:
	~trienode(){
		delete key;
	}
};


template <class T>
class TRIE{
	trienode<T> root;//al instanciarse la clase ya se instanciara esto
	public:
		TRIE  &  insert(const char * k, const T v){ //DEVULVE REFERENCIA PARA PODER ACER ADD. ADD.
			auto lenk = strlen(k);
		
			insert(root , k , v,lenk);

			return *this;
		}
	public:
		~TRIE(){
			for (int i = 0; i < 26; ++i)
			{
				delete root.children[i];
			}
		}
	private:
		void insert(trienode<T> & root, const char * k, const T  v, int tamk){
			if(*k == 0){
				(k-=tamk);
				set_data(root, v, k);
				return;
			}
			auto len = strlen(k);
			auto index = *k - 'a';
			auto & e = root.children[index];
			if(e == nullptr){
				e = new trienode<T>();
			}
			insert(*e , k+1, v, tamk);
		}

		void set_data(trienode<T> &n , const T v, const char *k){
			
			n.data = v;
			n.key = (char *)k;
		}

		public:
		const char * find( const char * s) const {
			return find(root , s);
		}

		private:

		const char * find(const trienode<T> & n, const char * s) const{
			if(*s == 0){
				return n.data;
			}
			auto index = *s - 'a';
			auto e = n.children[index];
			cout<<(char) (index + 'a');
			if(e == nullptr){
				return nullptr;
			}

			return find(*e, s+1);
		}

	public:
	//PRINT LTODAS LAS PALABRAS CONST  INGLES ESPANOL
		void print() const{
			print_all(root);
		
		}

		void print_all(const trienode<T> & n)const{
			if(n.data != nullptr){
				 cout<<n.key<<" -  ";
				 cout<<n.data<<endl;
			}else{
				for (int i = 0; i < 26; ++i){

					if (n.children[i] != nullptr){//cout<<(char) (i + 'a');
						print_all(*n.children[i]);
					}
				}
			}
		}

		void print_prefix(const char * s)const {
				 auto lens = strlen(s);

			print_prefix_p(root,  s,  lens);
		}
	private:
		void print_prefix_p(const trienode<T> & n, const char * s, int tams)const {
			if(n.data){
				bool res = true;
				 for(int i = 0 ; i < tams; i++){
				 	if(n.key[i] != s[i]){
				 		res = false;
				 		break;
				 	}
				 }
				 if(res){
				 	cout<<n.key<<" - "<<n.data<<endl;
				 }

			}else{
				for (int i = 0; i < 26; ++i){

					if (n.children[i] != nullptr){//cout<<(char) (i + 'a');
						print_prefix_p(*n.children[i], s,tams);
					}
				}
			}
		}

   /*  TRIE  &  operator[](const char * key){//if does not find it, creates it.
    return insert;
  }  */
};

int main(){

	TRIE<int> s;//o(n)  n elementos de la palabra

  s.insert("diez", 10);
    s.insert("dieciocho", 18);
    s.insert("diecinueve", 19); 
   /*  s["veinte"] = 20;
    s["veintiuno"] = 21;
 */

	s.print_prefix("die");


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