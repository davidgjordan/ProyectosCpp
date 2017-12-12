#ifndef CONTROLLERKEY_H_
#define CONTROLLERKEY_H_

#include <Defines.h>

#include <utility> 
#include <vector>
#include <string>
#include <map>

#include <CImg.h>


using namespace std;
using namespace cimg_library;

class ControllerKey
{
    float _gameAccion;
    vector<float> _binaryAccion;
    string _accionRepresent;
    string _keyRepresent;
    public:
        ControllerKey();

        void SetGameAccion(float gameAccion);
        void SetAccionRepresent(string direction);
        void SetKeyRepresent(string keyRepresent="HOME");
        void SetBinaryAccion(int bitPosition, int size);

        float GetGameAccion();
        vector<float> GetBinaryAccion();
        string GetAccionRepresent();
        string GetKeyRepresent();
        int GetKeyCode();
        static int GetKeyCode(string key);

        ~ControllerKey();
        
};
#endif//CONTROLLERKEY_H_