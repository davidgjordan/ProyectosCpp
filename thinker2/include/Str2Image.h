#ifndef STR2IMAGE_H_
#define STR2IMAGE_H_

#include <Defines.h>
#include <string>
#include <fstream>
#include <regex>
#include <algorithm>
#include <unistd.h>
#include <CImg.h>
using namespace cimg_library;
using namespace std;

class Str2Image
{
        string* _rgbArray;
    public:  
        CImgDisplay _displayer;
        Str2Image();
        void SetRgbArray(string& rgbArray);
        string GetRgbArray();
        void SaveRgbArray(string routePath);
        CImg<unsigned char> GetImage();
        void DisplayImage();    
        ~Str2Image();
};
#endif //STR2IMAGE_H_