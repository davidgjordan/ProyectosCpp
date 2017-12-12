#include <Str2Image.h>

Str2Image::Str2Image()
{
}

Str2Image::~Str2Image()
{
    //dtor
}


CImg<unsigned char> Str2Image::GetImage()
{
    int RGBCounter=1;//contador
    int axisY=0;
    int axisX=0;
    int red;
    int green;
    int blue;

    string auxRgbArray;
    auxRgbArray += *_rgbArray;
    //imagen de 160X210

    CImg<unsigned char> image(DEFAULT_WIDTH, DEFAULT_HEIGTH, 1, 3);
    char* token;
    token = strtok((char*)(auxRgbArray).c_str()," ,[]");

    while(token!=NULL) 
    {
         if(axisX == DEFAULT_WIDTH)
               {axisY++; axisX = 0;}
         switch(RGBCounter)
        {
            case 1:red = atoi(token); RGBCounter++; break;
            case 2:green = atoi(token); RGBCounter++; break;
            case 3:blue = atoi(token); RGBCounter = 1;
                   image(axisX, axisY, 0) = (unsigned char)red;
                   image(axisX, axisY, 1) = (unsigned char)green;
                   image(axisX, axisY, 2) = (unsigned char)blue;
                   axisX++;
                   break;
        }       
        token = strtok(NULL," ,[]");
    }
    return image; 
}


void Str2Image::DisplayImage()
{
    _displayer = GetImage();
}

void Str2Image::SetRgbArray(string &rgbArray)
{
    _rgbArray = &rgbArray;
}

string Str2Image::GetRgbArray()
{
    return *(_rgbArray);
}

void Str2Image::SaveRgbArray(string routePath)
{ 
    ofstream saveRgbArray(routePath + ".txt");
    saveRgbArray << *_rgbArray;
    saveRgbArray.close();   
}