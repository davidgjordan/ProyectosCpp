#include "RgbTool.h"
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
	RgbTool *tool = new RgbTool("RGB");

	ifstream render_txt ("render.txt");
	string s ;
	getline(render_txt,s);
	render_txt.close();

	tool->SetRenderRgb(s);
	tool->CharRepresent(tool->GetRenderRgb());

	tool->MappingRgb(tool->GetResizedRender());

	tool->PrintMapHtml();

	
	return 0;
}