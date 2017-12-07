#include <RgbTool.h>
#include "gtest/gtest.h"
using namespace std;
class ResizeRGBTest : public ::testing::Test 
{
};
TEST_F(ResizeRGBTest,MappingRGBtoResize)
{	
	string nameRGBTool="resize";
    string fileJson=nameRGBTool + ".json"; 
	RgbTool* rgbTool = new RgbTool(nameRGBTool);
    rgbTool->SetHeightGlobal(9);nameRGBTool +".json";
    rgbTool->SetWidthGlobal(14);
    Json resizeJson;
    ifstream ipf {"resize.json"};
    ipf >> resizeJson;
    Resize* resize = new Resize(resizeJson); 
    string mappingSource = "MMMMMMMMMMMMMM\nMMXXXXXPPXXMMM\nMMMMMPPPPMMMMM\nXXXXXXXXXXXXXX\nMMMXX111XXXMMM\nXXXXXX111XXXXX\nMMXXXX222XXXMM\nMMMMMXXXXXXXMM\nMMXXXXXMMMMMMM";
    string mappingExpectBy2 = "MMMMMMM\nMMMPPMM\nMMX1XXM\nMXX22XM\nMXXXMMM\n";
    string mappingExpectBy3 = "MMMMM\nXXXXX\nMX2XM\n";
    resize->SetImageMap(mappingSource);
    string resizedBy2=resize->ResizeImageMap(2,2);
    string resizedBy3 = resize->ResizeImageMap(3,3);
    EXPECT_STREQ(resizedBy2.c_str(),mappingExpectBy2.c_str());
    EXPECT_STREQ(resizedBy3.c_str(),mappingExpectBy3.c_str());
    remove(fileJson.c_str());
    delete resize;
    delete rgbTool;
}