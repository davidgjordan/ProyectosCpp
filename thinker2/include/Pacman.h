#ifndef PACMAN_H_
#define PACMAN_H_

using namespace std;

class Pacman
{
	double _positionX;
	double _positionY;
	char _charRepresentation;

	public:
		Pacman();
		~Pacman();

		void SetPositionX(double& positionX);
		void SetPositionY(double& positionY);
		void SetCharRepresentation(char& charRepresentation);

		double GetPositionX() const;
		double GetPositionY() const;
		char GetCharRepresentation() const;
};

#endif //PACMAN_H_