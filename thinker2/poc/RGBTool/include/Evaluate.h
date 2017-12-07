#ifndef EVALUATE_H_
#define EVALUATE_H_

#include <Defines.h>

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <map>

#include <json.hpp>

using Json = nlohmann::json;
using namespace std;

class Evaluate
{
		Json _jsonRgb;
    public:

        Evaluate(Json jsonRgb);

        map<char,double> GetObjectPosition (char objectMatch, string auxRenderRGB);
        map<string,double> GetObjectAllPosition (string objectMatch, string auxRenderRGB);
		~Evaluate();
};

#endif //EVALUATE_H_
