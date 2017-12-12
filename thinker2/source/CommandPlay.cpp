#include <CommandPlay.h>
CommandPlay::CommandPlay(int argc, const char** argv)      
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
void CommandPlay::CreateCommand()
{
	_optionParser.AddText("play",'l',true);
    _optionParser.AddText("keyboard",'k');
    _optionParser.AddText("server",'s');
    _optionParser.AddBoolean("actionNone",'a');
}

void CommandPlay::ExecuteCommand(Newbie& newbie)
{
    newbie.Load();

    map<string, vector<IOptionType*>> options = _optionParser.GetOptions();
    auto option = options.end();
    _nameGame = static_cast<Text*>(options.find("play")->second[0])->GetValue();

    if(_nameGame == "true")
    {
        _nameGame = "MsPacman-ram-v0";
    }
    
    if((option = options.find("server")) != options.end())
    {
        newbie.AssignServer(static_cast<Text*>(option->second[0])->GetValue());
    }

    if((option = options.find("keyboard")) != options.end())
    {
        _keysConfig = static_cast<Text*>(option->second[0])->GetValue();
    }
 
    if ((option = options.find("actionNone")) != options.end())
    {
        _saveActionNone = static_cast<Boolean*>(option->second[0])->GetValue();
    }

    newbie.Play(_nameGame, _keysConfig, _saveActionNone);
}   