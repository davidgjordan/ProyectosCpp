#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Base{
public:
    virtual string toString() const =0;
    virtual bool equals(const Base &)const = 0;

};
class Object: public virtual Base{
public:
    string toString() const {
        
        char res[25];
        printf(res,"Object%d",this);
        return res;
    }
    bool equals(const Base & b) const{
        return this == &b;
    }
};

class IInterface: public virtual Base{

};

class IComparable: public virtual IInterface{
public:
    virtual int compareTo(const IComparable &) const= 0;
};

class IComparator: public virtual IInterface{
public:
    virtual int compare(const Object & ,const Object & ) const= 0;
};


class String: public virtual Object, public virtual IComparable{

    string data;

public:
    String(string data):data{data}{        
    }

    string toString() const {
        return data;
    }
    bool equals(const Base & b) const{
        return this == &b;
    }

    int compareTo(const IComparable & comparable) const {
        const String * aux = dynamic_cast<const String *>(&comparable);
        return data.compare(aux->data);
    }
};



class Integer: public virtual Object, public virtual IComparable{
    
        int data;
    
    public:
        Integer(int data):data{data}{        
        }
    
        string toString() const {
            return to_string(data);
        }
        bool equals(const Base & b) const{
            return this == &b;
        }
    
        int compareTo(const IComparable & comparable) const{
            const Integer * aux = dynamic_cast<const Integer *>(&comparable);
            return data-aux->data;
        }
    };

    class CI: public virtual Object{
    
            int nit;
        
        public:
            int getNit(){
                return nit;
            }
            CI(int nit=0):nit{nit}{        
            }
        
            string toString() const {
                return to_string(nit);
            }
            bool equals(const Base & b) const{
                return this == &b;
            }
        
            int compareForNit( CI & comparator1) {
                //const   CI * aux = dynamic_cast<const CI*> (&comparator1);
                return nit - comparator1.getNit();
            } 
        };

    class DefalutComparator: public virtual Object, public virtual IComparator{


        public:
        DefalutComparator(){}
        string toString() const {   
            char res[25];
            printf(res,"DefalutComparator%d",this);
            return res;
        }
        bool equals(const Base & b) const{
            return this == &b;
        }
        int compare(const Object &comparator1 , const Object & comparator2 ) const{
            const IComparable * aux1 = dynamic_cast<const IComparable *>(&comparator1);
            const IComparable * aux2 = dynamic_cast<const IComparable *>(&comparator2);
            return aux1->compareTo(*aux2);
        }   
    };

    class CIComparator:public virtual Object, public virtual IComparator{
    public:
        string toString() const {   
            char res[25];
            printf(res,"CIComparator%d",this);
            return res;
        }

        int compare(const Object &comparator1, const Object & comparator2)const {
            CI * aux1 = dynamic_cast<CI *>(&((Object&)comparator1));
            CI * aux2 = dynamic_cast<CI *>(&((Object&)comparator2));
            //const CI * aux1 = dynamic_cast<const CI *>(&comparator1);
            //const CI * aux2 = dynamic_cast<const CI *>(&comparator2);
            return aux1->compareForNit(*aux2);
        } 

    };
          
    



int main(){


    DefalutComparator d;

    cout<<d.compare(String{"a"},String{"b"})<<endl;

    cout<<d.compare(String{"b"},String{"a"})<<endl;

    
    cout<<d.compare(Integer{57},Integer{1})<<endl;
    cout<<d.compare(Integer{57},Integer{100})<<endl;

    return 0;
}


/*  TreeMap M;//TODO ORIENTADO A OBJETOS
    //          key             value
    m.add(new Integer(2), new String("dos"));
    m.add(new Integer(4), new String("cuatro"));
    m.add(new Integer(0), new String("cero"));
    cout<<m.toString()<<endl;
    m.remove(Integer {0});
    for(auto & p: m){ //TENEMOS Q ACER ITERADOR EN EL TreeMap  //llamar al destructor borrar nodos los objetos de ;los nodeos y el comparador
        cout<<p.key->toString()<<endl;
        cout<<p.value->toString()<<endl;
    }
    cout<<m[Integer{4}]->toString()<<endl;//implementar operatror []  //accedo a la valor con la llave 4
                                            //es como un m.get
    //tendremos una propiedad de clase de tipo CIComparetor para segun a eso comparar el CI
    TreeMap pm{new CIComparator()};//nos serviria  
    m.add(new CI(4928514,"Cbba"), new String("pedro lopez"));//el default comparater compara 
    cout<<pm.toString()<<endl; */ //si  nos dan ci comparariamos mediante el ci