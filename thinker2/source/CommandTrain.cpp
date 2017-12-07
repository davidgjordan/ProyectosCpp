#include <CommandTrain.h>

CommandTrain::CommandTrain(int argc, const char** argv)
{
    try
    {
        _optionParser = {argc, argv};
        CreateCommand();
        _optionParser.Validate();
    }
    catch (exception& e)
    {
        cerr<<e.what()<<endl;
    }
}

void CommandTrain::CreateCommand()
{
    _optionParser.AddText("train",'t',true);
    _optionParser.AddText("game",'g',true);
    _optionParser.AddText("keyboard",'k');
    _optionParser.AddText("NNTopology",'o',true);
    _optionParser.AddText("NNWeights",'w',true); 
    _optionParser.AddBoolean("filter",'f');   
}

void CommandTrain::ExecuteCommand(Newbie& newbie)
{
    newbie.Load();
    bool filter = false;
    map<string, vector<IOptionType*>> options = _optionParser.GetOptions();
    _typeMethod = static_cast<Text*>(options.find("train")->second[0])->GetValue();
    _gameName = static_cast<Text*>(options.find("game")->second[0])->GetValue();
    _NNTopology = static_cast<Text*>(options.find("NNTopology")->second[0])->GetValue();
    _NNWeights = static_cast<Text*>(options.find("NNWeights")->second[0])->GetValue();

    auto option = options.end();
    if((option = options.find("keyboard")) != options.end())
    {
        _keysConfig = static_cast<Text*>(option->second[0])->GetValue();
    }
    
   
    if((option = options.find("filter")) != options.end() && option->second.size() > 0)
    {
        filter = static_cast<Boolean*>(option->second[0])->GetValue();
    }
    newbie.SetDataSource(_typeMethod, _gameName, _keysConfig, _NNTopology, _NNWeights, filter);    
}