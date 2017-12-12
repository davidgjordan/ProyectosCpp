#include <Wall.h>

Wall::Wall()
{

}

Wall::Wall(double& positionX, double& positionY, char& charRepresentation)
{
	this->_positionX = positionX;
	this->_positionY = positionY;
	this->_charRepresentation = charRepresentation;
}

Wall::~Wall()
{
    
}

void Wall::SetPositionX(double& positionX)
{
    _positionX = positionX;
}

void Wall::SetPositionY(double& positionY)
{
    _positionY = positionY;
}

void Wall::SetCharRepresentation(char& charRepresentation)
{
    _charRepresentation = charRepresentation;
}

double Wall::GetPositionX() const
{
    return _positionX;
}

double Wall::GetPositionY() const
{
    return _positionY;
}

char Wall::GetCharRepresentation() const
{
    return _charRepresentation;
}