#include "Keyboard.h"


void Keyboard::AirPlaneControll(FighterAirPlane *fighterAirPlane, GameBoard *gameBoard, Missile *missile)
{
	int key;
	if (_kbhit())
	{
		key = _getch();
		switch (key)
		{
		case keyLeft:
		{
			if (fighterAirPlane->GetCoordinateLeftWingY() > gameBoard->GetWallLeft())
			{
				gameBoard->map[fighterAirPlane->GetCocpitStartLocateX()][fighterAirPlane->GetCockpitCoordinateY()] = ' ';
				gameBoard->map[fighterAirPlane->GetLeftWingStartLocateX()][fighterAirPlane->GetCoordinateLeftWingY()] = ' ';
				gameBoard->map[fighterAirPlane->GetWingRightStartLocateX()][fighterAirPlane->GetCoordinateWingRightY()] = ' ';
				fighterAirPlane->DecrementCoordinateAirPlaneY();
				gameBoard->map[fighterAirPlane->GetCocpitStartLocateX()][fighterAirPlane->GetCockpitCoordinateY()] = '^';
				gameBoard->map[fighterAirPlane->GetLeftWingStartLocateX()][fighterAirPlane->GetCoordinateLeftWingY()] = '<';
				gameBoard->map[fighterAirPlane->GetWingRightStartLocateX()][fighterAirPlane->GetCoordinateWingRightY()] = '>';
			}
		}break;
		case keyRight:
		{
			if (fighterAirPlane->GetCoordinateWingRightY() < gameBoard->GetWallRight())
			{
				gameBoard->map[fighterAirPlane->GetCocpitStartLocateX()][fighterAirPlane->GetCockpitCoordinateY()] = ' ';
				gameBoard->map[fighterAirPlane->GetLeftWingStartLocateX()][fighterAirPlane->GetCoordinateLeftWingY()] = ' ';
				gameBoard->map[fighterAirPlane->GetWingRightStartLocateX()][fighterAirPlane->GetCoordinateWingRightY()] = ' ';
				fighterAirPlane->IncrementCoordinateAirPlaneY();
				gameBoard->map[fighterAirPlane->GetCocpitStartLocateX()][fighterAirPlane->GetCockpitCoordinateY()] = '^';
				gameBoard->map[fighterAirPlane->GetLeftWingStartLocateX()][fighterAirPlane->GetCoordinateLeftWingY()] = '<';
				gameBoard->map[fighterAirPlane->GetWingRightStartLocateX()][fighterAirPlane->GetCoordinateWingRightY()] = '>';
			}
		}break;
		case keySpace:
		{
			if (missile->GetMissileNumber() < indexRestrictive&&gameBoard->GetBeginning())
			{
				missile->SetShootForward(fighterAirPlane->GetCockpitCoordinateY());
				missile->SetShootCoord(14);
				missile[missile->GetMissileNumber()].SetPosX(missile->GetShootCoord());
				missile[missile->GetMissileNumber()].SetPosY(missile->GetShootForward());
				missile[missile->GetMissileNumber()].SetActivate(true);
				missile->IncreaseMissileNumber();
			}
			else
			{
				gameBoard->SetBeginning(false);
				for (int index = 0; index < indexRestrictive; index++)
					if (!missile[index].GeActivate())
					{
						missile->SetMissileNumber(index);
						missile->SetShootForward(fighterAirPlane->GetCockpitCoordinateY());
						missile->SetShootCoord(14);
						missile[missile->GetMissileNumber()].SetPosX(missile->GetShootCoord());
						missile[missile->GetMissileNumber()].SetPosY(missile->GetShootForward());
						missile[missile->GetMissileNumber()].SetActivate(true);
						break;
					}
			}
		}
		default: {}
		}
	}
}