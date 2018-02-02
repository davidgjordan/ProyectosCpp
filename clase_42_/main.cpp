//EJERCICIOS
#include <unordered_map>//esta es la libreria

//el unorder set es una tabla hash// el set es un arbol binario de busqueda
#include <iostream>
#include <string>
#include <cstring>
#include <vector> 
#include <algorithm> 
#include <fstream> 
#include <set> 

using namespace std;

struct NameID{
    int id;
    string name;
};
//me creo tres alias
using teacher = NameID;
using course = NameID;
using pupilo = NameID;
using topic = NameID;//dado un curso voya almacenar una lista de topicos

//la mejor estructura es un mapa desordenado
class School{
    unordered_map<int , teacher> teachers;
    unordered_map<int , pupilo> pupilos;
    unordered_map<int , course> courses;
    unordered_map<int , vector<topic>> topic_by_course;//la clave es el id del curso
    unordered_map<int , set<int>> pupilos_by_course;

    //map<string , int> course_by_id;
    public:
    template<typename ...T>
    //id del teacher y el resto de los campos
    void add_teacher(int id, const T& ...args ){
        teachers[id] = teacher{id, args...};
    }

    template<class ...T>
     void add_course(int id, const T& ...args ){
        courses[id] = course{id, args...};
        //aqui agregar la otra lista al reves para el ultimo metodo de abajo
    }

    template<class ...T>
     void add_pupil(int id, const T& ...args ){
        pupilos[id] = pupilo{id, args...};
    }

    
     void add_topic(int courseid, const string & topic_name,int teacherid ){
      auto & topics =   topic_by_course[courseid];
      topics.push_back(topic{teacherid,topic_name });
    }

    template<class ...T>
     void set_pupile_to_course(int courseid, const T & ...ids){
      
        auto & pupils =   pupilos_by_course[courseid];

        set_data(pupils,ids...);
    }
    
    //tipo , u tipo del primer id, y v el resto
    template<class T , class U ,class ...V>
    void set_data(T & c , const U& u, const  V &...args){
        c.insert(u);
        set_data(c, args...);
    }

    template<class T>
    void set_data(T&){}

    

};

int main(){


    School s;
    s.add_teacher(1, "Romulo Rojas");
    s.add_teacher(2, "Alvaro perez");
    s.add_teacher(3, "Marcelo");
    
    s.add_course(1, "devint24");
    s.add_course(2, "devint25");

    s.add_pupil(1,"hernan rojas 1");
    s.add_pupil(2,"carlos rojas 2");
    s.add_pupil(3,"topo rojas 3");
    s.add_pupil(4,"yansha rojas 4");

    //pirmer argumento id del curso  , id del profe
    s.add_topic(1,"c++",1);  
    s.add_topic(2,"english",1); 
    s.add_topic(3,"english", 2); 
    s.add_topic(1,"c#", 2); 


    //curso 1 alumonos 1, 2,3
    s.set_pupile_to_course(1,1,2,3);
    //curso 2    a los alumnos 1 y 4
    s.set_pupile_to_course(2,1,4);



    //le dan el curso uno y llama a esta funcion por cada profesor 
    /* s.iterate_all_teachers_by_course(1, [](auto & t){
        std::cout << t << '\n';//implemetar los dos iterates y operador mayor menor
    });
    
    cout<<s.get_course_id_by_name("devint25")<<endl;//devulve dos */
    //iterar a mano el mapa acernos otro mapa donde por nombre de cursos tenga el nombre

    return 0;
}

//s.save_to_disk(const string & fn);
//s.load_from_disk(const string & fn);