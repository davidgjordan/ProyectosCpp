#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <PythonByHand.h>

using namespace std;

PythonByHand::PythonByHand(string path){
    //asigna el path de los scripts a la propiedad de clase _pathScript
}
void PythonByHand::addParameter(Json configUser){
    //asigna el configUser(configuracion del usuario sobre como quire 
        //que el agente trabaje y produzca observations) 
}
void PythonByHand::addParameter(string inputStreaming){
    
}
void PythonByHand::run(){
    //ejecuta el script segun el json configuser y carga los resultados a la propiedad
    //de clase _result
}
Json PythonByHand::getResult(){
    //retorna el json con las observaciones 
    return _result;
}

