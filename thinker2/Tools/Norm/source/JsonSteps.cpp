
#include <JsonSteps.h>

JsonSteps::JsonSteps()
{
	_step = 0;
}

JsonSteps::~JsonSteps()
{}

void JsonSteps::SetStep(int step)
{
	_step = step;
}

void JsonSteps::SetBytesByStep(int bytes)
{
	_bytesByStep.push_back(bytes);
}

int JsonSteps::GetStep()
{
	return _step;
}

vector<float> JsonSteps::GetBytesByStep()
{
	return _bytesByStep;
}