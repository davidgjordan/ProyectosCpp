#include <iostream>
#include <string>
#include <cstring>


using namespace std;

struct trieNode{

    char *data;
    char *key = nullptr;
    trieNode *children[26];   //26 es numero de letras

    trieNode():data{nullptr}{
        memset(children, 0, 26*sizeof(trieNode*));
    }

public:
    ~trieNode(){
        delete data;
        delete key;
    }
};

class trie{

private:
    trieNode root;

    void add( trieNode& n , const char* k, const char* v, int lenk){
        if (*k == 0){
            k-=lenk;
            setData(n,v, k);
            return;
        }

        auto index = *k - 'a';
        auto& e = n.children[index];
        if (e == nullptr){
            e= new trieNode();
        }

        add(*e, k+1, v, lenk);
    }


    static void setData(trieNode& n, const char* v, const char* k){
        auto len = strlen(v);
        auto ns =new char [len +1];
        memcpy(ns, v, len+1);
        n.data = ns;
        auto lenk = strlen(k);
        auto nsk =new char [lenk +1];
        memcpy(nsk, k, lenk+1);
        n.key = nsk;
    }

    const char* find (const trieNode& n, const char* s)const {
        if(*s == 0){
            return n.data;
        }
        auto index= *s-'a';
        auto e = n.children[index];
        cout<<(char)(index+'a');
        if (e == nullptr){
            return nullptr;
        }

        return find(*e, s+1);
    }

    void print_prefix( const trieNode& nodo, const char *c, int len)const{

        if(nodo.data != nullptr){
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
    trie& add(const char* k, const char* v ){
        int lenk = strlen(k);

        add(root, k, v, lenk);
        return *this;

    } 

    void print() const{
        char vec[26];
        printAll(root);
    }

    void printAll(const trieNode& nodo) const{
        if(nodo.data != 0){
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
        int len = strlen(c);
        print_prefix( root, c, len);
    }
    


    const char* find(const char* s) const{
        return find(root, s);
    }

    ~trie(){

        for (int i = 0; i < 26; ++i){
            delete root.children[i];			
        }
    }	

};

int main(){
    
    trie x;
    x.add("perro", "dog")
    .add("gato", "cat")
    .add("pato", "duck")
    .add("gallo", "chicken")
    .add("gallina", "hen")
    .add("raton", "mice") 
    .add("tortugas", "turtle");

  x.print();


/*	if (auto n = x.find("tortuga"); n!= nullptr){
        cout<<n<<endl;
    }
*/
    x.print_prefix("t");
    return 0;
}