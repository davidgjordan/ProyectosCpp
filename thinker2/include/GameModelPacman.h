#ifndef GAMEMODELPACMAN_H_
#define GAMEMODELPACMAN_H_
#include <IGameModel.h>
#include <Pacman.h>
#include <Ghost.h>

class GameModelPacman: public IGameModel
{
    Pacman _pacman;
    Ghost _ghostBlinky;
    Ghost _ghostPinky;
    Ghost _ghostInky;
    Ghost _ghostClyde;

    public:
        GameModelPacman();
        ~GameModelPacman();

        void SetPacman(Pacman& pacman);
        void SetGhostBlinky(Ghost& ghostBlinky);
        void SetGhostPinky(Ghost& ghostPinky);
        void SetGhostInky(Ghost& ghostInky);
        void SetGhostClyde(Ghost& ghostClyde);

        Pacman GetPacman() const;
        Ghost GetGhostBlinky() const;
        Ghost GetGhostPinky() const;
        Ghost GetGhostInky() const;
        Ghost GetGhostClyde() const;
};

#endif//GAMEMODELPACMAN_H_