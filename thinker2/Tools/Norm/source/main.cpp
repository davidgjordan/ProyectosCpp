#include <JsonSteps.h>
#include <JsonFile.h>

int main(int argc, char const *argv[])
{
	JsonFile Manager;
	JSON Json;
	fstream File;

	printf("%s\n", Manager.Load(Json, File, "template.json", ModeFiles::READ).c_str());
	printf("%s\n", Manager.SaveAllData(Manager, File, "AllBytesData.html", ModeFiles::WRITE).c_str());
	printf("%s\n", Manager.SaveRepetitiveBytes(Manager, File, "filterRepetitiveBytes.html", ModeFiles::WRITE).c_str());
	printf("%s\n", Manager.SavePacmanSteps(Manager, File, "pacmanSteps.html", ModeFiles::WRITE).c_str());
	printf("%s\n", Manager.FilterNumberNoRepeat(Manager, File, "numberNoRepeat.html", ModeFiles::WRITE).c_str());
    
    return 0;
}