#pragma once

#include "Coordinates.h"

class Missile: public Coordinates
	{
		int missileNumber;
		int shootCoord;
		int shootForward;
	public:
		Missile();
		~Missile();

		void IncreaseMissileNumber();

		void DecrementPositiionX();

		int GetMissileNumber();
		void SetMissileNumber(int);
		void SetShootForward(int);
		int GetShootForward();
		void SetShootCoord(int);
		int GetShootCoord();

		void SetPosX(int);
		void SetPosY(int);
		void SetActivate(bool);

		int GetPosX();
		int GetPosY();

		bool GeActivate();
	};
