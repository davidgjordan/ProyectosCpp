#include <Persistence.h>

Persistence::Persistence()
{}

Persistence::~Persistence()
{}

void Persistence::Save(Json& persistenBreins, const string& path)
{
	ofstream ofs{path};
	ofs << setw(4) <<persistenBreins;
	ofs.close();
}

Json Persistence::Load(const string& path)
{
	ifstream ifs{path};
	ifs >> _persistenBreins;
return _persistenBreins;
}