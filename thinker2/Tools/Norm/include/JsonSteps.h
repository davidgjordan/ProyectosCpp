#ifndef JSONSTEPS_H_
#define JSONSTEPS_H_

#include <vector>

using namespace std;

struct JsonSteps
{
	private:
		int _step;
		vector<float> _bytesByStep;
	public:
		JsonSteps();
		~JsonSteps();
		void SetStep(int step);
		void SetBytesByStep(int bytes);
		int GetStep();
		vector<float> GetBytesByStep();
};

#endif