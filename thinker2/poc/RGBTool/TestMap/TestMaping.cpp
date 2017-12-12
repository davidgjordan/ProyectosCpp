#include <RgbTool.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdio>
//#include "../include/rgbTool.h"
//#include <direct.h>
#include <sys/stat.h>
#include <dirent.h>
#include <vector>
#include <map> 
#include <time.h>
using namespace std;

 vector<string> nameFiles(string path)       
{
    DIR    *dir;
    dirent *pdir;
    vector<string> files;
    dir = opendir(path.c_str());
    while (pdir = readdir(dir))
    {
        files.push_back(pdir->d_name);
    }
    return files;
}
int main(int argc, char const *argv[])
{
    clock_t tIni, tEnd;
    double secs;
    tIni = clock();
    string directoryRender = "RenderFilesMapping";
    RgbTool* rgbTool = new RgbTool("RGB");
    string directoryRGB = "RGBFilesMaping";
    mkdir(directoryRGB.c_str(), S_IRWXU);
    vector<string> nameFilesRender ;
    map<string, int> m_query;
    nameFilesRender = nameFiles(directoryRender.c_str()); 
    for (unsigned i=0; i<nameFilesRender.size(); ++i)
    {
        if(nameFilesRender[i]!="." && nameFilesRender[i]!="..")    
        {
            ifstream render_txt (directoryRender + "/" + nameFilesRender[i].c_str());
            string stringRender ;
            string matrixGenerated;
            getline(render_txt,stringRender);
            render_txt.close();
            rgbTool->SetRenderRgb(stringRender);
            rgbTool->CharRepresent(rgbTool->GetRenderRgb());
            matrixGenerated = rgbTool->GetCharRepresentation();
            ofstream fileMapingRGB(directoryRGB + "/" + "MappingRGBof" + nameFilesRender[i]);
            fileMapingRGB << matrixGenerated;
            fileMapingRGB.close();
        }   
    }
    cout<<"Datos generados de RENDER a mapeo RGB finalizado!!! "<<endl<<endl;
    tEnd = clock();
    secs = (double)(tEnd - tIni) / CLOCKS_PER_SEC;
    printf("%.16g milliseconds\n", secs * 1000.0);
    return 0;
}