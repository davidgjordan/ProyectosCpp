#include <ControllerKey.h>

ControllerKey::ControllerKey()
{

}

ControllerKey::~ControllerKey()
{

}

void ControllerKey::SetGameAccion(float gameAccion)
{
	_gameAccion = gameAccion;
}

void ControllerKey::SetBinaryAccion(int bitPosition, int size)
{
	_binaryAccion.resize(size);
	for(int i = 0; i < size; i++)
		_binaryAccion[i] = 0.00;
	_binaryAccion[bitPosition] = 1.00;
}

void ControllerKey::SetAccionRepresent(string accionRepresent)
{
	_accionRepresent = accionRepresent;
}

void ControllerKey::SetKeyRepresent(string keyRepresent)
{
	_keyRepresent = keyRepresent;
}

float ControllerKey::GetGameAccion()
{
	return _gameAccion;
}

vector<float> ControllerKey::GetBinaryAccion()
{

	return _binaryAccion;
}

string ControllerKey::GetAccionRepresent()
{
	return _accionRepresent;
}

string ControllerKey::GetKeyRepresent()
{

	return _keyRepresent;
}

int ControllerKey::GetKeyCode()
{
	return CImgDisplay::keycode(_keyRepresent.c_str());
}

int ControllerKey::GetKeyCode(string key)
{
	return CImgDisplay::keycode(key.c_str());
}