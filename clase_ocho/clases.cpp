#include <iostream>

#include <string>

 using namespace std;

class persona{
string nombre;
string apellido;
int ci;

public:
    // forma correcta de inicializar        el primer nombre es el atributo de la clase(el orden de las variables es importante)     esto se llama lista de incializadores
    persona(const string &nombre,const  string &apellido, int ci) : nombre{nombre}, apellido{apellido} , ci{ci}  {
        
        // el this es un pountero por eso con flechita al objeto q esta invocando este metodo
        /* this->nombre = nombre;
        this->apellido = apellido;
        this->ci = ci; */

    }
/* NEGACION DE BITS SI SE UTLIZA EN ESTO INT A = 8  A = ~A  NIGA LOS BITS */
/* EN ESTE AMBITO SOLO PUEDE TENER UN DESTRUCTOR  */
    ~persona(){
        cout<<"adios"<<endl;
    }
// dentro de esta funcion no se puede modificar el this por el const
// disenar siempore con const al menos q se encesite acer una modificacion
  void  print() const{
        cout<<nombre <<endl;
        cout<<apellido <<endl;
        cout<<ci <<endl;

    }


};


class binary{
    char num;

    // char getNum(const string &s);
private:
    // constructor privado
    binary( char n):num{n}{

    }

    public :
    binary(const string &s) :num{getNum(s)}{
        // cuando me pase una cadena transformarlo a binario

    }
    char getNum(const string &s){
        char n = 0;
    
        for(auto k : s){
            n*=2;
            n+= k=='1' ? 1:0;
        }
        return n;
    }

    char get_decimal()const{
        return num;
    }


    // sobrecargamos el operador mas
    operator+( const binary &p) const {
        binary b{(char)(num+p.num )};
        return b;
    }

};







 int main(){
     /* NO ES INICIALIZACION ASI Q SE DESTRUIRA CUANDO TERMINE ESTA FUNCION */
persona p{"Eva","Lopez",1234};


/* if(1){
 destruye el this porq ya hay return 
    return 1;
}
p.print();
 */


binary b { "1010"};

cout<<(int)(b.get_decimal())<<endl;

binary b1 {"0011"};
cout<<(b+b1).get_decimal()<<endl;


return 0;

}


