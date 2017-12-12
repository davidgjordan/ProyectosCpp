#include <Controller.h>

Controller::Controller(string game, string jsonPath, string typeKeyboard)
{
	_typeKeyboard = typeKeyboard;
	Load(game, jsonPath);
}

Controller::Controller()
{

}

string Controller::ValidateKeyboard(string game)
{
	if(_typeKeyboard == "A")
	{
		for (auto& x : Json::iterator_wrapper(jsonKeyboard))
		{	
			for(auto& i : x.value()["games"])
			{
				if( i == game )
				{
					cout<<"Configuration: " << x.key() <<"\n";
					return x.key();
				}
			}
		}
		cout<<"WARNING : This configuration may not be compatible with the game \n";
	}
	else
	{
		return _typeKeyboard;
	}
}

void Controller::Load(string game, string jsonPath)
{

    ifstream fileJson ((jsonPath).c_str());

    if (fileJson.peek() == EOF)
    {
        //ERROR
    }    
    else
    {
        if(fileJson.good())
		{
			fileJson >> jsonKeyboard;

			if(jsonKeyboard.empty())
			{
				//ERROR
			}
			else
			{
				_typeKeyboard = ValidateKeyboard(game);
				ProcessKeyboard();
			}
		}
		else
		{
			printf("SOME THING ABOUT THIS FILE <%s.json> IS WRONG!\n", jsonPath.c_str());
		}
    }

    fileJson.close();

}

void Controller::ProcessKeyboard()
{
	int bitPosition = 0;

	int keysNumber = jsonKeyboard[_typeKeyboard]["keys"].size();
	keysNumber += jsonKeyboard[_typeKeyboard]["Combinations"].size();
 	for (auto& x : Json::iterator_wrapper(jsonKeyboard[_typeKeyboard]["keys"]))
    {
    	string key = x.key();
    	auto keyValues = x.value();
    	auto values = keyValues.begin();

		ControllerKey newKey;
		newKey.SetKeyRepresent(values.key());
		newKey.SetGameAccion((float)values.value());
		newKey.SetAccionRepresent(key);
		newKey.SetBinaryAccion(bitPosition, keysNumber);
		
    	_pairCommand.insert(make_pair(newKey.GetKeyCode(), newKey));
        bitPosition++;        
	}	
	ProcessCombinations(bitPosition,keysNumber);
}

void Controller::ProcessCombinations(int &bitPosition, int &keysNumber)
{
 	for (auto& x : Json::iterator_wrapper(jsonKeyboard[_typeKeyboard]["Combinations"]))
	{
    	auto keyValues = x.value();
    	auto gameAccion = keyValues["GameAccion"];

    	vector<unsigned int> combinationKeys;
    	int keycode = 0;
    	for(auto& combination : keyValues["Keys"])
    	{
    		combinationKeys.push_back(ControllerKey::GetKeyCode(combination));
    		keycode += ControllerKey::GetKeyCode(combination);

    	}
    	_combinations[keycode] =  combinationKeys;
    	
    	

    	ControllerKey newKey;
		newKey.SetKeyRepresent();
		newKey.SetGameAccion((float)gameAccion);
		newKey.SetAccionRepresent(x.key());
		newKey.SetBinaryAccion(bitPosition, keysNumber);
		
    	_pairCommand.insert(make_pair(keycode, newKey));
        bitPosition++;        
	}	
}

float Controller::GetAction(int posicionByte) 
{
	for(auto& i : _pairCommand)
	{
		if(i.second.GetBinaryAccion()[posicionByte]==1.00)
			return i.second.GetGameAccion();
	}
}


pair <float, vector<float>> Controller::pressKey(const unsigned int keycode)
{
	auto i = _pairCommand.find(keycode);
	ControllerKey key;

	if(i==_pairCommand.end() || keycode == 0)
	{
		auto none = jsonKeyboard[_typeKeyboard]["keys"]["NONE"];
		int noneKey = ControllerKey::GetKeyCode(none.begin().key());
		key = _pairCommand[noneKey];
		return make_pair(key.GetGameAccion(), key.GetBinaryAccion());
	}
	key = _pairCommand[keycode];
	return make_pair(key.GetGameAccion(), key.GetBinaryAccion());
}

Controller::~Controller()
{

}