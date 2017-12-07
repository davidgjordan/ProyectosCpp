#ifndef WAY_H_
#define WAY_H_

using namespace std;

class Way
{
    double _positionX;
    double _positionY;
    char _charRepresentation;

    public:
        Way();
        Way(double& positionX, double& positionY, char& charRepresentation);
        ~Way();
        
        void SetPositionX(double& positionX);
        void SetPositionY(double& positionY);
        void SetCharRepresentation(char& charRepresentation);

        double GetPositionX() const;
        double GetPositionY() const;
        char GetCharRepresentation() const;
};

#endif //WAY_H_