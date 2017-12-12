#include <CommandInstall.h>

CommandInstall::CommandInstall(int argc, const char** argv) 
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

void CommandInstall::CreateCommand()
{
    _optionParser.AddBoolean("install",'i',true);
    _optionParser.AddText("name", 'n');
    _optionParser.AddText("path",'p',true);
    _optionParser.AddText("server",'s');
}

void CommandInstall::ExecuteCommand(Newbie& newbie)
{
    map<string, vector<IOptionType*>> options = _optionParser.GetOptions();
    IOptionType* option = nullptr;
	for (auto &o : options)
    {
        switch((option = o.second[0])->GetAbbr())
        {
            case 'n':
                _valueOption = static_cast<Text*>(option)-> GetValue();
                if(_valueOption != "true")
                {
                    newbie.AssignTrainer(_valueOption);                    
                }
                else
                {
                    newbie.AssignTrainer(TRAINER);
                }
               
            break;
            case 'p':
            {
                _valueOption = static_cast<Text*>(option)-> GetValue();
                ifstream validDirectory{_valueOption};
                if(validDirectory.is_open())
                {
                    newbie.Install();
                    newbie.AssignDirectory(_valueOption);
                }
                else
                {           
                    throw ExceptionNoPath();
                }
            }
            break;
            case 's':
                _valueOption = static_cast<Text*>(option)-> GetValue();
                newbie.AssignServer(_valueOption);
            break;
        }
    }
}