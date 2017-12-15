#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <Python.h>

#define pi 3.141592653589793

using namespace std;

int main(int argc, char **argv)
{
    //     cout<<"hello"<<endl;
    //     // cout<<js.dump();<<endl;
    //     //Inicio el interprete Python e imprimo informacion relevante
    //Py_Initialize();
    //PyRun_SimpleString("print 'hello world python'");
    //      //****
    //     PyObject *FileScript;
    //     FileScript = PyFile_FromString("script.py","r");
    //     cout<<"1"<<endl;
    //     PyRun_SimpleFile(PyFile_AsFile(FileScript),"r");
    //     cout<<"2"<<endl;
    //     PyObject *retorno, *modulo, *clase, *metodo, *argumentos, *objeto;
    //     cout<<"3"<<endl;
    //     int *resultado;
    //     //modulo = PyImport_ImportModule("script");
    //     cout<<"4"<<endl;
    //     clase = PyObject_GetAttrString(modulo, "Numeros");
    //     cout<<"5"<<endl;
    //     argumentos = Py_BuildValue("ii",5,11);
    //     cout<<"6"<<endl;
    //     objeto = PyEval_CallObject(clase, argumentos);
    //     cout<<"7"<<endl;
    //     metodo = PyObject_GetAttrString(objeto, "suma");
    //     cout<<"8"<<endl;
    //     argumentos = Py_BuildValue("()");
    //     cout<<"9"<<endl;
    //     retorno = PyEval_CallObject(metodo,argumentos);
    //     cout<<"10"<<endl;
    //     PyArg_Parse(retorno, "i", &resultado);
    //     cout<<"11"<<endl;
    //     cout<<"El resultado es: "<<(int)(*resultado)<<endl;
    //     cout<<"12"<<endl;

    // // //***********
    //     Py_Finalize();
    // 	char terminar;
    // 	cin>>terminar;

    //

    // Py_SetProgramName(argv[0]); /* optional but recommended */
    // Py_Initialize();
    // PyRun_SimpleString("from time import time,ctime\n"
    //                    "print 'Today is',ctime(time())\n");
    // //FILE * pFile;
    // PyObject *FileScript;
    // FileScript = PyFile_FromString("script.py", "r");
    // PyRun_SimpleFile(PyFile_AsFile(FileScript), "r");
    // Py_Finalize();

    system("python argumentos.py uno dos tres cuatro");

    return 1;
}

// g++ -o users -I/usr/local/include/python2.4 pyembed.cpp
// main.cpp -L/usr/local/lib/python2.4/config -Xlinker
// -export-dynamic -lpython2.4 -lm -lpthread -ltk -lutil