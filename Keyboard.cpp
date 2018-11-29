#include "Keyboard.h"

void Keyboard::AirPlaneControll(FighterAirPlane *fighterAirPlane, Map *map, Missile *missile)
{
	int key;
	if (_kbhit())
	{
		key = _getch();
		switch (key)
		{
		case keyLeft:
		{
			if (fighterAirPlane->GetCoordinateLeftWingY() > map->GetWallLeft())
			{
				map->map[fighterAirPlane->GetCocpitStartLocateX()][fighterAirPlane->GetCockpitCoordinateY()] = ' ';
				map->map[fighterAirPlane->GetLeftWingStartLocateX()][fighterAirPlane->GetCoordinateLeftWingY()] = ' ';
				map->map[fighterAirPlane->GetWingRightStartLocateX()][fighterAirPlane->GetCoordinateWingRightY()] = ' ';
				fighterAirPlane->DecrementCoordinateAirPlaneY();
				map->map[fighterAirPlane->GetCocpitStartLocateX()][fighterAirPlane->GetCockpitCoordinateY()] = '^';
				map->map[fighterAirPlane->GetLeftWingStartLocateX()][fighterAirPlane->GetCoordinateLeftWingY()] = '<';
				map->map[fighterAirPlane->GetWingRightStartLocateX()][fighterAirPlane->GetCoordinateWingRightY()] = '>';
			}
		}break;
		case keyRight:
		{
			if (fighterAirPlane->GetCoordinateWingRightY() < map->GetWallRight())
			{
				map->map[fighterAirPlane->GetCocpitStartLocateX()][fighterAirPlane->GetCockpitCoordinateY()] = ' ';
				map->map[fighterAirPlane->GetLeftWingStartLocateX()][fighterAirPlane->GetCoordinateLeftWingY()] = ' ';
				map->map[fighterAirPlane->GetWingRightStartLocateX()][fighterAirPlane->GetCoordinateWingRightY()] = ' ';
				fighterAirPlane->IncrementCoordinateAirPlaneY();
				map->map[fighterAirPlane->GetCocpitStartLocateX()][fighterAirPlane->GetCockpitCoordinateY()] = '^';
				map->map[fighterAirPlane->GetLeftWingStartLocateX()][fighterAirPlane->GetCoordinateLeftWingY()] = '<';
				map->map[fighterAirPlane->GetWingRightStartLocateX()][fighterAirPlane->GetCoordinateWingRightY()] = '>';
			}
		}break;
		case keySpace:
		{
			if (missile->GetMissileNumber() < indexRestrictive&&map->GetBeginning())
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
				map->SetBeginning(false);
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