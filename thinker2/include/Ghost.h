#ifndef GHOST_H_
#define GHOST_H_

using namespace std;

class Ghost
{
        double _positionX;
        double _positionY;
        bool _vulnerable;
        char _charRepresentation;

    public:

        Ghost();
        ~Ghost();

        void SetPositionX(double& positionX);
        void SetPositionY(double& positionY);
        void SetVulnerable(bool& vulverable);
        void SetCharRepresentation(char& charRepresentation);
        
        double GetPositionX() const;
        double GetPositionY() const;
        bool GetVulnerable() const;
        char GetCharRepresentation() const;
};

#endif //GHOST_H_