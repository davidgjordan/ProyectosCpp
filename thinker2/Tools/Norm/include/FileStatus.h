#ifndef FILESTATUS_H_
#define FILESTATUS_H_

#include <FileEnums.h>

#include <fstream>

using namespace std;

bool IsFileExist(fstream& file);

bool IsFileGood(fstream& file);

bool IsFileEmpty(fstream& file);

MessageFiles VerifyFile(fstream& file, string fileName, ModeFiles mode);

string ShowFileMessage(MessageFiles message);

#endif//FILESTATUS_H_