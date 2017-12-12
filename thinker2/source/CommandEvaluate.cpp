#include <CommandEvaluate.h>
#include <Agent.h>

CommandEvaluate::CommandEvaluate(int argc, const char** argv) 
{
    _optionParser = {argc, argv};
    CreateCommand();
    _optionParser.Validate();
}

void CommandEvaluate::CreateCommand()
{
	_optionParser.AddBoolean("evaluate",'e',true);
    _optionParser.AddText("server",'s');
    _optionParser.AddText("NNWeights",'w',true);
}

void CommandEvaluate::ExecuteCommand(Newbie& newbie)
{
    newbie.Load();
    Agent* agent;
    map<string, vector<IOptionType*>> options = _optionParser.GetOptions();
    auto option = options.end();
    if((option = options.find("server")) != options.end())
    {
        _serverIP = static_cast<Text*>(options.find("server")->second[0])->GetValue();
    }
    else
    {
        _serverIP = newbie.GetServer();
    }
    _NNWeights = static_cast<Text*>(options.find("NNWeights")->second[0])->GetValue();
    _typeMethod = newbie.GetTrainMethod();
    agent = new Agent(_serverIP, _typeMethod, _NNWeights);
    delete agent;
}