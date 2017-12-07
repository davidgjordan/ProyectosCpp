

#include <JsonFile.h>

JsonFile::JsonFile()
{
	_ranking = 0;
	_score = 0;
	_trainer = "";
	_maxSizeStep = 0;
}

JsonFile::~JsonFile()
{}

void JsonFile::SetRanking(int ranking)
{
	_ranking = ranking;
}

void JsonFile::SetScore(float score)
{
	_score = score;
}

void JsonFile::SetDataByStep(vector<JsonSteps> dataByStep)
{
	_dataByStep = dataByStep;
}

void JsonFile::SetTrainer(string trainer)
{
	_trainer = trainer;
}

void JsonFile::SetMaxSizeStep(int maxsizestep)
{
	_maxSizeStep = maxsizestep;
}

int JsonFile::GetRanking()
{
	return _ranking;
}

float JsonFile::GetScore()
{
	return _score;
}

vector<JsonSteps> JsonFile::GetDataByStep()
{
	return _dataByStep;
}

string JsonFile::GetTrainer()
{
	return _trainer;
}

int JsonFile::GetMaxSizeStep()
{
	return _maxSizeStep;
}

vector<int> JsonFile::FilterRepetitiveBytes()
{
	vector<int> noRepetitiveBytes;
	bool isRepetitiveByte;
	int counterNoRepetitiveBytes = 0;

	for (int byte = 0; byte < NUMBER_BYTES; ++byte)
	{
		isRepetitiveByte = false;

		int step = 0;

		while((step < GetMaxSizeStep()) && (isRepetitiveByte != true))
		{
			if ((GetDataByStep()[0].GetBytesByStep()[byte]) != (GetDataByStep()[step].GetBytesByStep()[byte]))
			{
				noRepetitiveBytes.push_back(int());

				noRepetitiveBytes[counterNoRepetitiveBytes] = byte;

				isRepetitiveByte = true;
				counterNoRepetitiveBytes++;
			}

			step++;
		}
	}

	return noRepetitiveBytes;
}

string JsonFile::Load(JSON& json, fstream& file, string fileName, ModeFiles mode)
{
	MessageFiles replyFile = VerifyFile(file, fileName, mode);
	MessageJson replyJson = VerifyJson(json, file, replyFile, mode);

	if(replyJson == MessageJson::GOODFORWORK)
	{
		SetRanking(json[RANKING]);
		SetScore(json[SCORE]);
		SetTrainer(json[TRAINER]);
		SetMaxSizeStep(json[STEPS].size());

		vector<JsonSteps> Aux_jsonData;

		for (int step = 0; step < GetMaxSizeStep(); ++step)
		{
			Aux_jsonData.push_back(JsonSteps());

			Aux_jsonData[step].SetStep(step + STARTSTEP);

			for (int byte = 0; byte < NUMBER_BYTES; ++byte)
			{
				Aux_jsonData[step].SetBytesByStep(json[STEPS][to_string(step + STARTSTEP)][byte]);
			}
		}

		SetDataByStep(Aux_jsonData);

		return "THE DATA HAS BEEN UPLOADED";
	}
	else
	{
		if(replyFile == MessageFiles::GOODFORWORK)
		{
			return ShowJsonMessage(replyJson);
		}
		else
		{
			return ShowFileMessage(replyFile);
		}
	}
}

string JsonFile::SaveAllData(JsonFile jsonFile, fstream& file, string fileName, ModeFiles mode)
{
	MessageFiles replyFile = VerifyFile(file, fileName, mode);
	
	file << "<!DOCTYPE html>" << endl;
	file << "<html>" << endl;
	file << "	<head>" << endl;
	file << "		<meta charset='UTF-8'>" << endl;
	file << "		<title>" << "Save All Data" << "</title>" << endl;
	file << "		<style>" << endl;
	file << "			table { border-collapse: collapse; width: 100%; }" << endl;
	file << "			th, td { text-align: left; padding: 8px; }" << endl;
	file << "			tr:nth-child(even) { background-color: #f2f2f2; }" << endl;
	file << "			th { background-color: #4CAF50; color: white; }"<< endl;
	file << "		</style>" << endl;
	file << "	</head>" << endl;
	file << "	<body>" << endl;

	file << "		<center><h2>BYTE ANALYSIS</h2></center>" << endl;
	file << "		<h3>Profile:</h3>" << endl;
	file << "		<ul>" << endl;
	file << "			<li><p><strong>Ranking: </strong> " << jsonFile.GetRanking() << ".</p></li>" << endl;
	file << "			<li><p><strong>Score: </strong> " << jsonFile.GetScore() << ".</p></li>" << endl;
	file << "			<li><p><strong>Trainer: </strong> " << jsonFile.GetTrainer() << ".</p></li>" << endl;
	file << "		</ul>" << endl;
	file << "		<p>Then the table with all the bytes for each step made in the game will be shown.</p>" << endl;
	file << "		<div style='overflow-x:auto;'>" << endl;

	file << "		<table>" << endl;
	file << "			<tr>" << endl;
	file << "				<th>" << "#" << "</th>" << endl;

	for (int byte = 1; byte <= NUMBER_BYTES; byte++)
	{
		file << "<th>" << byte << "</th>" << endl;
	}

	file << "			</tr>" << endl;

	for (int step = 0; step < jsonFile.GetMaxSizeStep(); step++)
	{
		file << "<tr>" << endl;

		file << "<td>" << step + 1 << "</td>" << endl;

		for (int byte = 0; byte < NUMBER_BYTES; byte++)
		{
			switch(byte)
			{
				case 6:
				{
					file << "<td bgcolor='#994C00'>" << jsonFile.GetDataByStep()[step].GetBytesByStep()[byte] << "</td>" << endl;
				}
				break;
				case 12:
				{
					file << "<td bgcolor='#994C00'>" << jsonFile.GetDataByStep()[step].GetBytesByStep()[byte] << "</td>" << endl;
				}
				break;
				case 7:
				{
					file << "<td bgcolor='#00CCCC'>" << jsonFile.GetDataByStep()[step].GetBytesByStep()[byte] << "</td>" << endl;
				}
				break;
				case 13:
				{
					file << "<td bgcolor='#00CCCC'>" << jsonFile.GetDataByStep()[step].GetBytesByStep()[byte] << "</td>" << endl;
				}
				break;
				case 8:
				{
					file << "<td bgcolor='#4C0099'>" << jsonFile.GetDataByStep()[step].GetBytesByStep()[byte] << "</td>" << endl;
				}
				break;
				case 14:
				{
					file << "<td bgcolor='#4C0099'>" << jsonFile.GetDataByStep()[step].GetBytesByStep()[byte] << "</td>" << endl;
				}
				break;
				case 9:
				{
					file << "<td bgcolor='#FF0000'>" << jsonFile.GetDataByStep()[step].GetBytesByStep()[byte] << "</td>" << endl;
				}
				break;
				case 15:
				{
					file << "<td bgcolor='#FF0000'>" << jsonFile.GetDataByStep()[step].GetBytesByStep()[byte] << "</td>" << endl;
				}
				break;
				case 10:
				{
					file << "<td bgcolor='#FFFF00'>" << jsonFile.GetDataByStep()[step].GetBytesByStep()[byte] << "</td>" << endl;
				}
				break;
				case 16:
				{
					file << "<td bgcolor='#FFFF00'>" << jsonFile.GetDataByStep()[step].GetBytesByStep()[byte] << "</td>" << endl;
				}
				break;
				default:
				{
					file << "<td>" << jsonFile.GetDataByStep()[step].GetBytesByStep()[byte] << "</td>" << endl;
				}
				break;
			}
		}

		file << "</tr>" << endl;
	}

	file << "</table>" << endl;
	file << "</div>" << endl;


	file << "</body>" << endl;
	file << "</html>" << endl;

	file.close();

	return "THE WEBSITE WAS CREATED";
}

string JsonFile::SaveRepetitiveBytes(JsonFile jsonFile, fstream& file, string fileName, ModeFiles mode)
{
	MessageFiles replyFile = VerifyFile(file, fileName, mode);

	file << "<!DOCTYPE html>" << endl;
	file << "<html>" << endl;
	file << "	<head>" << endl;
	file << "		<meta charset='UTF-8'>" << endl;
	file << "		<title>" << "TITLE OF WEB" << "</title>" << endl;
	file << "		<style>" << endl;
	file << "			table { border-collapse: collapse; width: 100%; }" << endl;
	file << "			th, td { text-align: left; padding: 8px; }" << endl;
	file << "			tr:nth-child(even) { background-color: #f2f2f2; }" << endl;
	file << "			th { background-color: #4CAF50; color: white; }"<< endl;
	file << "		</style>" << endl;
	file << "	</head>" << endl;
	file << "	<body>" << endl;

	file << "		<center><h2>ANALISIS DE BYTES</h2></center>" << endl;
	file << "		<h3>Perfil:</h3>" << endl;
	file << "		<ul>" << endl;
	file << "			<li><p><strong>Ranking: </strong> " << jsonFile.GetRanking() << ".</p></li>" << endl;
	file << "			<li><p><strong>Score: </strong> " << jsonFile.GetScore() << ".</p></li>" << endl;
	file << "			<li><p><strong>Trainer: </strong> " << jsonFile.GetTrainer() << ".</p></li>" << endl;
	file << "		</ul>" << endl;
	file << "		<p>A continuacion se mostrara la tabla con todos los bytes por cada paso realizado en el juego.</p>" << endl;
	file << "		<div style='overflow-x:auto;'>" << endl;

	file << "		<table>" << endl;
	file << "			<tr>" << endl;
	file << "				<th>" << "#" << "</th>" << endl;

	vector<int> auxFilterRepetitiveBytes = jsonFile.FilterRepetitiveBytes();

	for (int i = 0; i < auxFilterRepetitiveBytes.size(); ++i)
	{
		file << "<th>" << auxFilterRepetitiveBytes[i]+1 << "</th>" << endl;
	}

	file << "			</tr>" << endl;

	for (int step = 0; step < jsonFile.GetMaxSizeStep(); step++)
	{
		file << "<tr>" << endl;

		file << "<td>" << step + 1 << "</td>" << endl;

		for (int byte = 0; byte < auxFilterRepetitiveBytes.size(); byte++)
		{
			file << "<td>" << jsonFile.GetDataByStep()[step].GetBytesByStep()[auxFilterRepetitiveBytes[byte]] << "</td>" << endl;
		}

		file << "</tr>" << endl;
	}

	file << "</table>" << endl;
	file << "</div>" << endl;


	file << "</body>" << endl;
	file << "</html>" << endl;

	file.close();

	return "THE WEBSITE WAS CREATED";
}

string JsonFile::SavePacmanSteps(JsonFile jsonFile, fstream& file, string fileName, ModeFiles mode)
{
	MessageFiles replyFile = VerifyFile(file, fileName, mode);

	file << "<!DOCTYPE html>" << endl;
	file << "<html>" << endl;
	file << "	<head>" << endl;
	file << "		<meta charset='UTF-8'>" << endl;
	file << "		<title>" << "TITLE OF WEB" << "</title>" << endl;
	file << "	</head>" << endl;
	file << "	<body>" << endl;
	file << "		<canvas id='myCanvas' width='500' height='500' style='border:1px solid #d3d3d3;'> Your browser does not support the canvas element.</canvas>" << endl;
	file << "		<script>" << endl;
	file << "			var canvas = document.getElementById('myCanvas');" << endl;
	file << "			var ctx = canvas.getContext('2d');" << endl;

	file << "ctx.moveTo(" << 50 << "," << 50 << ");" << endl;

	for (int i = 0; i < jsonFile.GetMaxSizeStep(); ++i)
	{
		float x = GetDataByStep()[i].GetBytesByStep()[17];
		float y = GetDataByStep()[i].GetBytesByStep()[11];

		file << "ctx.lineTo(" << 200+i << "," << 100 << ");" << endl;
		file << "ctx.stroke();" << endl;
	}

	file << "		</script>" << endl;
	file << "</body>" << endl;
	file << "</html>" << endl;

	file.close();

	return "THE WEBSITE WAS CREATED";
}


int cmp_int(const void* a, const void* b)
{
	int x= *((int*)a);  
	int y= *((int*)b);
	if (x>y) return 1;
	if (x<y) return -1;  
	return 0; 
}

string JsonFile::FilterNumberNoRepeat(JsonFile jsonFile, fstream& file, string fileName, ModeFiles mode)
{
	vector<JsonSteps> AuxData;

	AuxData.push_back(JsonSteps());

	int comparator = 0;
	int possibleValues = 255;

	for (int byte = 0; byte < NUMBER_BYTES; ++byte)
	{
		int index = 0;

		for (int step = 0; step < GetMaxSizeStep(); ++step)
		{
			for (int j = 0; j < possibleValues; ++j)
			{
				if (AuxData[j].GetBytesByStep()[byte] == GetDataByStep()[step].GetBytesByStep()[byte])
				{
					comparator = 0;
					break;
				}
				else
				{
				comparator = 1;
				}
			}
			if (comparator == 1)
			{
				AuxData[index].GetBytesByStep()[byte] = GetDataByStep()[step].GetBytesByStep()[byte];
				index++;
			}

	comparator = 0;
		}
	}

int NumberOrdered[possibleValues];

for (int byte = 0; byte < NUMBER_BYTES; ++byte)
{
	for (int step = 0; step < possibleValues; ++step)
	{
		NumberOrdered[step] = AuxData[step].GetBytesByStep()[byte];
	}

	qsort(NumberOrdered, possibleValues, sizeof(int), cmp_int);

	for (int step = 0; step < possibleValues; ++step)
	{
		AuxData[step].GetBytesByStep()[byte] = NumberOrdered[step];
	}
}

MessageFiles replyFile = VerifyFile(file, fileName, mode);

file << "<!DOCTYPE html>" << endl;
file << "<html>" << endl;
file << " <head>" << endl;
file << " <meta charset='UTF-8'>" << endl;
file << " <title>" << "TITLE OF WEB" << "</title>" << endl;
file << " <style>" << endl;
file << " table { border-collapse: collapse; width: 100%; }" << endl;
file << " th, td { text-align: left; padding: 8px; }" << endl;
file << " tr:nth-child(even) { background-color: #f2f2f2; }" << endl;
file << " th { background-color: #4CAF50; color: white; }"<< endl;
file << " </style>" << endl;
file << " </head>" << endl;
file << " <body>" << endl;

file << " <center><h2>ANALISIS DE BYTES</h2></center>" << endl;
file << " <h3>Perfil:</h3>" << endl;
file << " <ul>" << endl;
file << " <li><p><strong>Ranking: </strong> " << GetRanking() << ".</p></li>" << endl;
file << " <li><p><strong>Score: </strong> " << GetScore() << ".</p></li>" << endl;
file << " <li><p><strong>Trainer: </strong> " << GetTrainer() << ".</p></li>" << endl;
file << " </ul>" << endl;
file << " <p>A continuacion se mostrara la tabla con todos los bytes por cada paso realizado en el juego.</p>" << endl;
file << " <div style='overflow-x:auto;'>" << endl;

file << " <table>" << endl;
file << " <tr>" << endl;
file << " <th>" << "#" << "</th>" << endl;

for (int step = 0; step < possibleValues; step++) 
{
	file << "<th>" << step +1 << "</th>" << endl;
}

file << " </tr>" << endl;


for (int byte = 0; byte < NUMBER_BYTES; byte++)
{
	file << "<tr>" << endl;

	file << "<td>" << byte +1<< "</td>" << endl;
	for (int step = 0; step < possibleValues; step++)
	{
		if (AuxData[step].GetBytesByStep()[byte]!=0.000000)
		{
		file << "<td>" << AuxData[step].GetBytesByStep()[byte] << "</td>" << endl;
		}
	}

	file << "</tr>" << endl;
}

	file << "</table>" << endl;
	file << "</div>" << endl;


	file << "</body>" << endl;
	file << "</html>" << endl;
	file.close();

return "THE WEBSITE WAS CREATED WITH NUMBERS ORDERED NOT REPEATS";
}
