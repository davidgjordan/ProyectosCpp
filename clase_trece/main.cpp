#include <iostream>
#include <cstring>
#include <string>

using namespace std;

//doomsday wed 14 2 16

struct trienode{

	char * data;
	char * key;
	trienode * children[26];//albabeto de 26 palabras
	trienode():data{nullptr}{
		memset(children , 0 , 26*sizeof(trienode*)); //pone todos los bites de array al valor q yo le diga
	}
public:
	~trienode(){
		delete data;
		delete key;

	}
};


class TRIE{
	trienode root;//al instanciarse la clase ya se instanciara esto
	public :
		TRIE  &  add(const char * k, const char * v){ //DEVULVE REFERENCIA PARA PODER ACER ADD. ADD.
			auto lenk = strlen(k);
		
			add(root , k , v,lenk);

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
		void add(trienode & root, const char * k, const char * v, int tamk){
			if(*k == 0){
				(k-=tamk);
				set_data(root, v, k);
				return;
			}
				auto len = strlen(k);

			auto index = *k - 'a';
			//era sin el & trienode *
			auto & e = root.children[index];
			if(e == nullptr){
				e = new trienode();
			}
			add(*e , k+1, v, tamk);
		}

		void set_data(trienode &n , const char *v, const char *k){
			auto len = strlen(v);
			auto ns =  new char[len+1];
			memcpy(ns, v, len+1);			
			n.data = ns;
			auto lenk = strlen(k);
			auto nsk =  new char[lenk+1];
			memcpy(nsk, k, lenk+1);			
			n.key = nsk;
		}

		public :
		const char * find( const char * s) const {
			return find(root , s);
		}

		private :

		const char * find(const trienode & n, const char * s) const{
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


		void print_all(const trienode & n)const{
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
		void print_prefix_p(const trienode & n, const char * s, int tams)const {
			if(n.data != nullptr){
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

				 //comprobamos q key contenga s
			}else{
				for (int i = 0; i < 26; ++i){

					if (n.children[i] != nullptr){//cout<<(char) (i + 'a');
				 		//cout<<"entro if 3";
						//
						print_prefix_p(*n.children[i], s,tams);

					}
				}
			}
		}

};



//PRINT _PREFIX("GALL");
//implementar q ke damos perro y da dog y otro q 
//dammos una letra y tiene q imprimir todas las q empiezan con eso 


int main(){

// estructura de datos trie para allmacenar texto


	TRIE X;//o(n)  n elementos de la palabra

	X.add("perro", "dog").
	add("gato", "cat").
	add("pato", "duck").
	add("gallo", "chicken").
	add("gallina", "hen").
	add("pez", "fish").
	add("gallina", "hen").
	add("raton st", "mice");


	X.print_prefix("p");


	// if(auto n = X.find("raton"); n!= nullptr){
	// 	//cout<<n<<endl;

	// }

	return 0;
}