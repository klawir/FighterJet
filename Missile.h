
#pragma once
class Missile
	{
		int posX, posY;
		bool activate;
		int missileNumber;
		int shootCoord;
		int shootForward;
	public:
		Missile();
		~Missile();
		void IncreaseMissileNumber();
		void SetPositionX(int a) { posX = a; }
		void SetPositionY(int a) { posY = a; }
		void SetActivate(bool a) { activate = a; }

		int GetPositionX() { return posX; }
		int GetPositionY() { return posY; }

		bool GeActivate() { return activate; }

		void SetPositiionX() { posX--; }

		int GetMissileNumber()
		{
			return missileNumber;
		}
		void SetMissileNumber(int set)
		{
			missileNumber = set;
		}
		void SetShootForward(int set)
		{
			shootForward = set;
		}
		int GetShootForward()
		{
			return shootForward;
		}
		void SetShootCoord(int set)
		{
			shootCoord = set;
		}
		int GetShootCoord()
		{
			return shootCoord;
		}
	};
