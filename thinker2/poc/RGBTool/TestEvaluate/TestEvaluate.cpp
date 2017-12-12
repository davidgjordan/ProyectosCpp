#include <RgbTool.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <map>

int main(int argc, char const *argv[])
{
    std::map<string,double> position;
    
	RgbTool* tool = new RgbTool("RGB");
    ifstream render_txt ("render.txt");
	string stringRender ;
    string matrixGenerated;
	getline(render_txt,stringRender);
	render_txt.close();

	tool->SetRenderRgb(stringRender);


	tool->CharRepresent(tool->GetRenderRgb());
    puts(tool->GetCharRepresentation().c_str());

    string object = "P1234";

	position = tool->GetObjectAllPosition(object);

	printf("\n PACMAN X: [%f]", position["PX"]);
    printf("\n PACMAN Y: [%f]", position["PY"]);

    printf("\n GHOST 1X: [%f]", position["1X"]);
    printf("\n GHOST 1Y: [%f]", position["1Y"]);

    printf("\n GHOST 2X: [%f]", position["2X"]);
    printf("\n GHOST 2Y: [%f]", position["2Y"]);

    printf("\n GHOST 3X: [%f]", position["3X"]);
    printf("\n GHOST 3Y: [%f]", position["3Y"]);

    printf("\n GHOST 4X: [%f]", position["4X"]);
    printf("\n GHOST 4Y: [%f]\n", position["4Y"]);

	return 0;
}