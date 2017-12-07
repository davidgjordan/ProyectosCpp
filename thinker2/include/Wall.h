#ifndef WALL_H_
#define WALL_H_

using namespace std;

class Wall
{
    double _positionX;
    double _positionY;
    char _charRepresentation;

    public:
        Wall();
        Wall(double& positionX, double& positionY, char& charRepresentation);
        ~Wall();
        
        void SetPositionX(double& positionX);
        void SetPositionY(double& positionY);
        void SetCharRepresentation(char& charRepresentation);

        double GetPositionX() const; 
        double GetPositionY() const;
        char GetCharRepresentation() const;
};

#endif //WALL_H_