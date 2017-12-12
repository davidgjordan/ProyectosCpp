#ifndef RESIZE_H_
#define RESIZE_H_

#include <Defines.h>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <regex>
#include <cstdio>

#include <json.hpp>

using namespace std;
using Json = nlohmann::json;

class Resize
{
        Json* _jsonRgb;;
        int _width;
        int _height;
        int _mapWidth;
        int _mapHeight;
        int _resizeX;
        int _resizeY;
        string _imageMap;
        string _resizeImage;
        void LoadJsonRgb();
    public:
        Resize(Json& json_rgb);
        ~Resize();
        void UpdateJsonRGB();
        void SetImageMap(string imageMap);
        void SetResizeX(int resizeX);
        void SetResizeY(int resizeY);
        void SetMapWidth(int mapWidth);
        void SetMapHeigth(int mapHeight);
        int GetResizeX();
        int GetResizeY();
        int GetWidth();
        int GetHeight();
        int GetMapWidth();
        int GetMapHeight();
        string CropImageMap(int mapWidth, int mapHeight);
        string CropImageMap();
        string ResizeImageMap(int resizeX, int resizeY);
        string ResizeImageMap();

        void ShowResizeImage();
        void ShowCropImage();
        void SetWidth(int width);
        void SetHeigth(int height);
};
#endif //RESIZE_H_