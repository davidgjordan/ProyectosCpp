#include <BrainPersistence.h>

BrainPersistence::BrainPersistence()
{}

BrainPersistence::~BrainPersistence()
{}

void BrainPersistence::Save(Json& persistenceBrain, const string& path)
{
	ofstream jsonBrainWrite{path};
	jsonBrainWrite << setw(INDENTATION) << persistenceBrain;
	jsonBrainWrite.close();
}

Json BrainPersistence::Load(const string& path)
{
	ifstream jsonBrainRead{path};
	Json persistenceBrain;
	jsonBrainRead >> persistenceBrain;
	return persistenceBrain;
}