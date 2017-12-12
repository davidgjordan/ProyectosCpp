#include <ICommand.h>
#include <CommandNewbie.h>
#include <CommandInstall.h>
#include <CommandPlay.h>
#include <CommandTrain.h>
#include <CommandEvaluate.h>

CommandNewbie::CommandNewbie(int argc, const char** argv) : _amount{argc}, _values{argv}
{
    _optionParser = {_amount, _values};
    CreateCommand();
    _optionParser.Validate();
}

void CommandNewbie::CreateCommand()
{
    _optionParser.AddText("install",'i');
    _optionParser.AddText("name",'n');
    _optionParser.AddText("path",'p');
    _optionParser.AddText("server",'s');
    _optionParser.AddText("play",'l');
    _optionParser.AddText("game", 'g');
    _optionParser.AddText("keyboard",'k');
    _optionParser.AddBoolean("actionNone",'a');
    _optionParser.AddText("train",'t');
    _optionParser.AddText("NNTopology",'o');
    _optionParser.AddText("NNWeights",'w'); 
    _optionParser.AddBoolean("evaluate",'e');  
    _optionParser.AddText("trainingType",'c');
    _optionParser.AddBoolean("filter",'f');
}

void CommandNewbie::ExecuteCommand(Newbie& newbie)
{
    Command* command;
    map<string, vector<IOptionType*>> options = _optionParser.GetOptions();
    auto option = options.end();
    if((option = options.find("install")) != options.end() && option->second.size() > 0)
    {
        command = new CommandInstall(_amount, _values); 
    }
    else if((option = options.find("play")) != options.end() && option->second.size() > 0)
    {
        command = new CommandPlay(_amount, _values);     
    }
    else if ((option = options.find("train")) != options.end() && option->second.size() > 0)
    {
        command = new CommandTrain(_amount, _values);
    }
    else if ((option = options.find("evaluate")) != options.end() && option->second.size() > 0)
    {
        command = new CommandEvaluate(_amount, _values);
    }

    command->ExecuteCommand(newbie);
}
