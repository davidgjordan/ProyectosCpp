#ifndef JSONFILE_H_
#define JSONFILE_H_

#include <Defines.h>
#include <FileEnums.h>
#include <FileStatus.h>
#include <JsonStatus.h>
#include <JsonSteps.h>

#include <iostream>
#include <vector>

#include <json.hpp>

using JSON = nlohmann::json;
using namespace std;

struct JsonFile
{
	private:
		int _ranking;
		float _score;
		vector<JsonSteps> _dataByStep;
		string _trainer;
		int _maxSizeStep;
	public:
		JsonFile();
		~JsonFile();
		void SetRanking(int ranking);
		void SetScore(float score);
		void SetDataByStep(vector<JsonSteps> dataByStep);
		void SetTrainer(string trainer);
		void SetMaxSizeStep(int maxsizestep);
		int GetRanking();
		float GetScore();
		vector<JsonSteps> GetDataByStep();
		string GetTrainer();
		int GetMaxSizeStep();
		string Load(JSON& json, fstream& file, string fileName, ModeFiles mode);
		string SaveAllData(JsonFile jsonFile, fstream& file, string fileName, ModeFiles mode);
		string SaveRepetitiveBytes(JsonFile jsonFile, fstream& file, string fileName, ModeFiles mode);
		string SavePacmanSteps(JsonFile jsonFile, fstream& file, string fileName, ModeFiles mode);
		vector<int> FilterRepetitiveBytes();

		string FilterNumberNoRepeat(JsonFile jsonFile, fstream& file, string fileName, ModeFiles mode);
};

#endif