#ifndef JSONSTATUS_H_
#define JSONSTATUS_H_

#include <FileEnums.h>
#include <JsonEnums.h>

#include <fstream>

#include <json.hpp>

using JSON = nlohmann::json;
using namespace std;

bool IsJsonEmpty(JSON& json);

MessageJson VerifyJson(JSON& json, fstream& file, MessageFiles message, ModeFiles mode);

string ShowJsonMessage(MessageJson message);

#endif//JSONSTATUS_H_