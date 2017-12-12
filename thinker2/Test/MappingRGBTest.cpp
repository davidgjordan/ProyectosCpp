#include <RgbTool.h>
#include "gtest/gtest.h"
using namespace std;
class MappingRGBTest : public ::testing::Test 
{
 
};
TEST_F(MappingRGBTest,RenderRGBtoMappingRGB)
{
	string nameRGBJson = "RGB";
	RgbTool* rgbTool = new RgbTool(nameRGBJson);
	Json manager;
	ifstream ipf {nameRGBJson+".json"};
    ipf >> manager;
	string stringRenderWall =  "[228, 111, 111], [228, 111, 111], [228, 111, 111], [228, 111, 111] ";
	string MappingWallExpected = "MMMM";
	string stringRenderWay =  "[0, 28, 36], [0, 28, 36], [0, 28, 36], [0, 28, 36] ";
	string MappingWayExpected = "XXXX";
	string stringRenderPacman =  "[210, 164, 74], [210, 164, 74], [210, 164, 74], [210, 164, 74] ";
	string MappingPacmanExpected = "PPPP";
	string stringRenderFruit =  "[184, 50, 50], [184, 50, 50], [184, 50, 50], [184, 50, 50] ";
	string MappingFruitExpected = "OOOO";
	string stringRenderGhostEat =  "[68, 114, 194], [68, 114, 194], [68, 114, 194], [68, 114, 194] ";
	string MappingGhostEatExpected = "XXXX";
	string stringRenderGhostTimeOuT =  "[214, 214, 214], [214, 214, 214], [214, 214, 214], [214, 214, 214] ";
	string MappingGhostTimeOuTExpected = "NNNN";

	string stringRenderGhost1 =  "[180, 122, 48], [180, 122, 48], [180, 122, 48], [180, 122, 48] ";
	string MappingGhost1Expected = "1111";
	string stringRenderGhost2 =  "[200, 72, 72], [200, 72, 72], [200, 72, 72], [200, 72, 72] ";
	string MappingGhost2Expected = "2222";
	string stringRenderGhost3 =  "[84, 184, 153], [84, 184, 153], [84, 184, 153], [84, 184, 153] ";
	string MappingGhost3Expected = "3333";
	string stringRenderGhost4 =  "[198, 89, 179], [198, 89, 179], [198, 89, 179], [198, 89, 179] ";
	string MappingGhost4Expected = "4444";
	string stringRenderPacman_Score =  "[187, 187, 53], [187, 187, 53], [187, 187, 53], [187, 187, 53] ";
	string MappingPacman_ScoreExpected = "VVVV";
	string stringRenderSpace =  "[0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0] ";
	string MappingSpaceExpected = "    ";

	string mappingGenerated;
	rgbTool->SetRenderRgb(stringRenderWall);
	rgbTool->CharRepresent(rgbTool->GetRenderRgb());
	mappingGenerated  =  rgbTool->GetCharRepresentation();
	
	EXPECT_STREQ(MappingWallExpected.c_str(),mappingGenerated.c_str());

	rgbTool->SetRenderRgb(stringRenderWay);
	rgbTool->CharRepresent(rgbTool->GetRenderRgb());
	mappingGenerated  =  rgbTool->GetCharRepresentation();
	EXPECT_STREQ(MappingWayExpected.c_str(),mappingGenerated.c_str());

	rgbTool->SetRenderRgb(stringRenderPacman);
	rgbTool->CharRepresent(rgbTool->GetRenderRgb());
	mappingGenerated  =  rgbTool->GetCharRepresentation();
	EXPECT_STREQ(MappingPacmanExpected.c_str(),mappingGenerated.c_str());

	rgbTool->SetRenderRgb(stringRenderFruit);
	rgbTool->CharRepresent(rgbTool->GetRenderRgb());
	mappingGenerated  =  rgbTool->GetCharRepresentation();
	EXPECT_STREQ(MappingFruitExpected.c_str(),mappingGenerated.c_str());

	rgbTool->SetRenderRgb(stringRenderGhostEat);
	rgbTool->CharRepresent(rgbTool->GetRenderRgb());
	mappingGenerated  =  rgbTool->GetCharRepresentation();
	EXPECT_STREQ(MappingGhostEatExpected.c_str(),mappingGenerated.c_str());

	rgbTool->SetRenderRgb(stringRenderGhostTimeOuT);
	rgbTool->CharRepresent(rgbTool->GetRenderRgb());
	mappingGenerated  =  rgbTool->GetCharRepresentation();
	EXPECT_STREQ(MappingGhostTimeOuTExpected.c_str(),mappingGenerated.c_str());

	rgbTool->SetRenderRgb(stringRenderGhost1);
	rgbTool->CharRepresent(rgbTool->GetRenderRgb());
	mappingGenerated  =  rgbTool->GetCharRepresentation();
	EXPECT_STREQ(MappingGhost1Expected.c_str(),mappingGenerated.c_str());

	rgbTool->SetRenderRgb(stringRenderGhost2);
	rgbTool->CharRepresent(rgbTool->GetRenderRgb());
	mappingGenerated  =  rgbTool->GetCharRepresentation();
	EXPECT_STREQ(MappingGhost2Expected.c_str(),mappingGenerated.c_str());

	rgbTool->SetRenderRgb(stringRenderGhost3);
	rgbTool->CharRepresent(rgbTool->GetRenderRgb());
	mappingGenerated  =  rgbTool->GetCharRepresentation();
	EXPECT_STREQ(MappingGhost3Expected.c_str(),mappingGenerated.c_str());

	rgbTool->SetRenderRgb(stringRenderGhost4);
	rgbTool->CharRepresent(rgbTool->GetRenderRgb());
	mappingGenerated  =  rgbTool->GetCharRepresentation();
	EXPECT_STREQ(MappingGhost4Expected.c_str(),mappingGenerated.c_str());

	rgbTool->SetRenderRgb(stringRenderPacman_Score);
	rgbTool->CharRepresent(rgbTool->GetRenderRgb());
	mappingGenerated  =  rgbTool->GetCharRepresentation();
	EXPECT_STREQ(MappingPacman_ScoreExpected.c_str(),mappingGenerated.c_str());

	rgbTool->SetRenderRgb(stringRenderSpace);
	rgbTool->CharRepresent(rgbTool->GetRenderRgb());
	mappingGenerated  =  rgbTool->GetCharRepresentation();
	EXPECT_STREQ(MappingSpaceExpected.c_str(),mappingGenerated.c_str());
	delete rgbTool;
		
}