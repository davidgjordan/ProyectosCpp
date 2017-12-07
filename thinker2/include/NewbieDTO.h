#ifndef NEWBIEDTO_H_
#define NEWBIEDTO_H_

#include <Defines.h>
#include <iostream>
using namespace std;

class NewbieDTO
{
    string _nameTrainer;
    string _gameDirectory;
    string _serverAddress;
    string _trainMethod;
    string _thresholdsPath;
    string _keysConfigPath;
    
    public:
        NewbieDTO();
        string GetTrainer()const;
        string GetDirectory()const;
        string GetServer()const;
        string GetTrainMethod()const;
        string GetThresholdsPath()const;
        string GetKeysConfigPath()const;
        void SetTrainer(const string& newName);
        void SetDirectory(const string& newGameDirectory);
        void SetServer(const string& newServerAddress);
        void SetTrainMethod(const string& newTrainMethod);
        void SetThresholdsPath(const string& newThresholdsPath);
        void SetKeysConfigPath(const string newkeysConfigPath);
        virtual ~NewbieDTO();
};

#endif // NEWBIEDTO_H_
