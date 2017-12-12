#include <Pacman.h>

Pacman::Pacman()
{

}

Pacman::~Pacman()
{
    
}

void Pacman::SetPositionX(double& positionX)
{
    _positionX = positionX;
}

void Pacman::SetPositionY(double& positionY)
{
    _positionY = positionY;
}

void Pacman::SetCharRepresentation(char& charRepresentation)
{
    _charRepresentation = charRepresentation;
}

double Pacman::GetPositionX() const
{
    return _positionX;
}

double Pacman::GetPositionY() const
{
    return _positionY;
}

char Pacman::GetCharRepresentation() const
{
    return _charRepresentation;
}