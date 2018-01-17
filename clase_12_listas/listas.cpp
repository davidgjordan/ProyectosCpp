#include <iostream>
#include <cstring>
#include <string>

using namespace std;


// VOLVERLA DOBLEMENTE ENLAZADA

struct SllNode{
public:
	char * str;
	SllNode * next;
	SllNode * previous;
	// SllNode(){
	// }
	~SllNode(){
 		//cout<<"entre SllNode"<<endl;
}

};

struct StringLinkedList{
public:
	SllNode * first = nullptr;
	SllNode * last/*ultimo*/ = nullptr;

	StringLinkedList& push_back( const char * s){//anade al nodo fin
		auto ns = copy(s);
		auto nn = new SllNode{ns,nullptr, nullptr};//tiene n q estar en el heap
		if(first == nullptr){
			first = last = nn; 
			return *this;
		}
		last->next = nn;
		nn->previous = last;
		last = nn;
		return *this;

	}

	StringLinkedList(SllNode * first1,SllNode * last2){
		first = first1;
		last = last2;
	}

	StringLinkedList & push_front( const char * s){//anade al nodo ini
		auto ns = copy(s);
		auto nn = new SllNode{ns,nullptr, nullptr};//tiene n q estar en el heap
		if(first == nullptr){
			first = last = nn; 
			return *this;
		}

		nn->next = first;
		first->previous = nn;
		first = nn;	
		return *this;

	}

	void print() const{
		// es *
		 auto aux  = first;
		 while(aux != nullptr){
		 	cout<<aux->str<<endl;
		 	aux = aux->next ;
		 }
 	}

// VOID PRINT_REVERSE
 	void print_reverse() const{
		// es *
		 auto aux  = last;
		 while(aux != nullptr){
		 	cout<<aux->str<<endl;
		 	aux = aux->previous ;
		 }
 	}

 	~StringLinkedList(){
 		auto aux = first;
 		while(aux){
 			auto next = aux->next;
 			delete [] aux->str;
 			delete aux;
 			aux = next;
 		}
 		//cout<<"entre StringLinkedList"<<endl;
 	}

	 static char * copy(const char * s){
		auto len = strlen(s);
		auto ns = new char[len+1];
		memcpy(ns , s, len+1);

		return ns;
	}

	//constructor copia
	StringLinkedList (const StringLinkedList & src){
		auto aux = src.first;
		while(aux){
			push_back(aux->str);
			aux = aux->next;
		}
		cout<<"entre constructor copia "<<endl;

	}
// ejercicio es
// HACER El OPERTOR =
	 StringLinkedList & operator=(const StringLinkedList & sll){
	 	if(&sll == this){
	 		return *this;
	 	}
	 	this->~StringLinkedList();

	 	auto aux = sll.first;
		while(aux){
			push_back(aux->str);
			aux = aux->next;
		}
		cout<<"entre operator= "<<endl;
	 	return *this;
	 }
	 
// EL CONSTRUCTOR copia de movida
	 StringLinkedList(StringLinkedList && src){
	 	auto aux = src.first;
			//src = nullptr;
		while(aux){
	 		auto auxNdo = aux->next;
			push_back(aux->str);
			 aux->str =  nullptr;
 			 aux = nullptr;
			aux = auxNdo;
		}
		cout<<"entre CONSTRUCTOR copia de movida "<<endl;

	 }


	 //OPERADOR = DE MOVIDA
    StringLinkedList & operator=(StringLinkedList && src){
        if(&src == this){
            return *this;
        }
        this->~StringLinkedList();
        auto aux = src.first;
		while(aux){
	 		auto auxNo = aux->next;
			push_back(aux->str);
			 aux->str =  nullptr;
 			 aux = nullptr;
			aux = auxNo;
		}
		cout<<"OPERADOR = DE MOVIDA "<<endl;
		return *this;
    }


//  CONSTRUCTOR SIN PARAMETROS
	 StringLinkedList(){
	 }


// VOID REMOVE(CONST CHAR * S)  TODOS LOS ELEMENTOS IGUALES A ESTA CADENA
	 void remove(const char *c){
		 int i = 0;
	 	if(first == nullptr){
	 		cout<<"lista vacia"<<endl;
	 	}else{
		 	auto aux = first;
			 				
		 	while(aux){
		 		auto auxNo =  aux->next;
		 		if ( strcmp(aux->str , c) == 0)
		 		{	
		 			if(aux->next == nullptr && aux->previous == nullptr ){
		 				aux->str = nullptr;
		 				aux = nullptr;
		 			}else if(aux->next != nullptr && aux->previous == nullptr ){
		 				first = aux->next;
		 				aux->next->previous = nullptr;
		 				aux->str = nullptr;
		 				aux = nullptr;		 				
		 			}else if(aux->next == nullptr && aux->previous != nullptr){
		 				last = aux->previous;
		 				aux->previous->next = nullptr;
		 				aux->str = nullptr;
		 				aux = nullptr;
		 			}else{
		 				aux->previous->next = aux->next;
			 			aux->next->previous = aux->previous; 
			 			aux->str = nullptr;
			 			aux = nullptr;
		 			}
		 		}
					 aux = auxNo;
	 		}
	 	}
	 }
};

int main(){
	StringLinkedList sll;
	sll.push_back("uno")
	.push_back("dos")
	.push_back("tres")
	.push_back("cuatro")
	.push_back("cinco")
	.push_back("dos")
	.push_back("seis");;
	cout<<"****************print******************"<<endl;
	sll.print();
	cout<<"****************fin - print******************"<<endl<<endl;
	// cout<<"reverse*************"<<endl;
	// sll.print_reverse();
	char * world = "dos";
	cout<<"****************remove - "<<world<< " *****print****" <<endl;
	sll.remove(world);
	sll.print();
	cout<<"****************fin - remove - print******************"<<endl<<endl;	
	cout<<"****************print - reverse ******************"<<endl;
	sll.print_reverse();
	cout<<"****************fin - print******************"<<endl<<endl;	

	cout<<"****************ENTRA AL CONSTRUCTOR COPIA******************"<<endl<<endl;		
	StringLinkedList sll3 = sll; //ENTRA AL CONSTRUCTOR COPIA

	cout<<"****************ENTRA AL OPERADOR =******************"<<endl<<endl;			
	sll3 = sll;
	sll3.print();

	cout<<"****************ENTRA AL CONSTRUCTOR COPIA DE MOVIDA******************"<<endl<<endl;			
	StringLinkedList sll2 = move(sll);////ENTRA AL CONSTRUCTOR COPIA DE MOVIDA  Y LE QUITE SUS DATOS A SLL
	sll2.print();

	cout<<"****************VACIO SLL******************"<<endl<<endl;		 
	sll.print();

	// cout<<"entre "<<sll.last->str <<endl;
	//StringLinkedList sll4{ new SllNode() , new SllNode()};
    return 0;
}