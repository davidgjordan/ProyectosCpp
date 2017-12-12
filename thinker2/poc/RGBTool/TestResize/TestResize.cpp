#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <cstdio>
#include <RgbTool.h>

#include "json.hpp"
using namespace std;
using Json = nlohmann::json;

int main()
{
    RgbTool* rgbTool = new RgbTool("RGB");
    ifstream render_txt ("render.txt");
    string stringRender ;
    string matrixGenerated;
    getline(render_txt,stringRender);
    render_txt.close();
    rgbTool->SetRenderRgb(stringRender);
    rgbTool->CharRepresent(rgbTool->GetRenderRgb());
    rgbTool->GetResizedRender();
    rgbTool->ShowResizeImage();
    rgbTool->ShowCropImage();

    return 0;
}