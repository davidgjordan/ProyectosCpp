#include <Way.h>

Way::Way()
{

}

Way::Way(double& positionX, double& positionY, char& charRepresentation)
{
	this->_positionX = positionX;
	this->_positionY = positionY;
	this->_charRepresentation = charRepresentation;
}

Way::~Way()
{
    
}

void Way::SetPositionX(double& positionX)
{
    _positionX = positionX;
}

void Way::SetPositionY(double& positionY)
{
    _positionY = positionY;
}

void Way::SetCharRepresentation(char& charRepresentation)
{
    _charRepresentation = charRepresentation;
}

double Way::GetPositionX() const
{
    return _positionX;
}

double Way::GetPositionY() const
{
    return _positionY;
}

char Way::GetCharRepresentation() const
{
    return _charRepresentation;
}