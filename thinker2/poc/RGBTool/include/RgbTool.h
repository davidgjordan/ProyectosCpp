#ifndef RGBTOOL_H_
#define RGBTOOL_H_

#include <Defines.h>
#include <Mapping.h>
#include <Evaluate.h>
#include <Resize.h>

#include <cstdio>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream> 
#include <iostream>

#include <json.hpp>


using namespace std;
using Json = nlohmann::json;

class RgbTool
{
    private:
        Json _jsonRgb;
        Mapping* _mapping;
        Resize* _resize;
        Evaluate* _evaluate;
        string _renderRGB;
        string _charRepresentation;
        string _gameName;  

        void SaveJson();
        void ReadJson();
        void CreateJsonDefault();
    public:
        RgbTool(string gameName);
        ~RgbTool();

        void CharRepresent(string auxRenderRGB);
        void CharRepresent();
        vector<vector<char>> MappingRgb(string resizedMap);
        vector<vector<char>> MappingRgb();
        void PrintMapHtml();
        void SavePathX();
        void SavePathY();
        void SaveStringExceptions();

        string CropImage(int width, int heigth);
        string CropImage();
        string GetRenderRgb();
        vector<vector<char>> GetMap();
        string GetResizedRender(int resizeX, int resizeY);
        string GetResizedRender();
        map<char, double> GetObjectPosition(char objectMatch);
        map<string, double> GetObjectAllPosition(string objectMatch);

        void SetException(string resizedMap);
        void SetRenderRgb(const string arrayRgb);  
        void SetResizeX(int resizeX);
        void SetResizeY(int resizeY);
        void SetWidthGlobal(int resizeX);
        void SetHeightGlobal(int resizeY);

        void SetWidth(int resizeX);
        void SetHeight(int resizeY);

        string GetCharRepresentation();
        int GetWidth();
        int GetHeigth();
        int GetResizeX();
        int GetResizeY();


        void ShowCropImage();
        void ShowResizeImage();



        
};

#endif //RGBTOOL_H_