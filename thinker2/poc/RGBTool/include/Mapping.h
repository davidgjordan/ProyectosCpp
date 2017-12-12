#ifndef MAPPING_H_
#define MAPPING_H_

#include <Defines.h>

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <map>
#include <regex>
#include <unordered_map>
#include <fstream>
#include <string>

#include <json.hpp>

using namespace std;
using Json = nlohmann::json;

class Mapping
{
        Json* _jsonRgb;
        vector<vector<char>> _array2D;
        vector<int> _pathX;
        vector<int> _pathY;
        vector<string> _replaceExceptions;
        map<string,string> _exceptionReplace;
        string ReplaceExceptions(string mapArray);
        void LoadJson();

    public:

        Mapping(Json& jsonRgb);
        ~Mapping();

        void SaveStringExceptions();
        void SavePathX();
        void SavePathY();
        void ToHtml();
        vector<vector<char>> GenerateMatrix(string mapArray);
        int ValidateArray(int array[],int sizeMax,int sizeArray);
        int Compare(int array[],int size,int value);
        string CharRepresentation(string render);

        vector<vector<char>> GetMatrix();
        vector<int> GetPathX();
        vector<int> GetPathY();
        char GetCharRgb(const int blue, const int green, const int red);
        void SetArraySize();    
        vector<vector<char>> SetObjectMatrix(char object, int x, int y);       
};
 #endif //MAPPING_H_