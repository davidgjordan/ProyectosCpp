#include <Ghost.h>

Ghost::Ghost()
{

}

Ghost::~Ghost()
{}

void Ghost::SetPositionX(double& positionX)
{
    _positionX = positionX;
}

void Ghost::SetPositionY(double& positionY)
{
    _positionY = positionY;
}

void Ghost::SetVulnerable(bool& vulverable)
{
    _vulnerable = vulverable;
}

void Ghost::SetCharRepresentation(char& charRepresentation)
{
    _charRepresentation = charRepresentation;
}

double Ghost::GetPositionX() const
{
    return _positionX;
}

double Ghost::GetPositionY() const
{
    return _positionY;
}

bool Ghost::GetVulnerable() const
{
    return _vulnerable;
}

char Ghost::GetCharRepresentation() const
{
    return _charRepresentation;
}