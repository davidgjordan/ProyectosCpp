#include <GameModelPacman.h>
#include <Pacman.h>
#include <Ghost.h>

GameModelPacman::GameModelPacman()
{

}

GameModelPacman::~GameModelPacman()
{

}

void GameModelPacman::SetPacman(Pacman& pacman)
{
    _pacman = pacman;
}

void GameModelPacman::SetGhostBlinky(Ghost& ghostBlinky)
{
    _ghostBlinky = ghostBlinky;
}

void GameModelPacman::SetGhostPinky(Ghost& ghostPinky)
{
    _ghostPinky = ghostPinky;
}

void GameModelPacman::SetGhostInky(Ghost& ghostInky)
{
    _ghostInky = ghostInky;
}

void GameModelPacman::SetGhostClyde(Ghost& ghostClyde)
{
    _ghostClyde = ghostClyde;
}

Pacman GameModelPacman::GetPacman() const
{
    return _pacman;
}

Ghost GameModelPacman::GetGhostBlinky() const
{
    return _ghostBlinky;
}

Ghost GameModelPacman::GetGhostPinky() const
{
    return _ghostPinky;
}

Ghost GameModelPacman::GetGhostInky() const
{
    return _ghostInky;
}

Ghost GameModelPacman::GetGhostClyde() const
{
    return _ghostClyde;
}