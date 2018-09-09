#include "Keyboard.h"



Keyboard::Keyboard()
{
}


Keyboard::~Keyboard()
{
}
void Keyboard::AirPlaneControll(Player *player, GameBoard *gameBoard, Missile *missile)
{
	int key;
	if (_kbhit())
	{
		key = _getch();
		switch (key)
		{
		case keyLeft:
		{
			if (player->GetCoordinateLeftWingY() > gameBoard->GetWallLeft())
			{
				gameBoard->map[player->GetCocpitStartLocateX()][player->GetCockpitCoordinateY()] = ' ';
				gameBoard->map[player->GetLeftWingStartLocateX()][player->GetCoordinateLeftWingY()] = ' ';
				gameBoard->map[player->GetWingRightStartLocateX()][player->GetCoordinateWingRightY()] = ' ';
				player->DecrementCoordinateAirPlaneY();
				gameBoard->map[player->GetCocpitStartLocateX()][player->GetCockpitCoordinateY()] = '^';
				gameBoard->map[player->GetLeftWingStartLocateX()][player->GetCoordinateLeftWingY()] = '<';
				gameBoard->map[player->GetWingRightStartLocateX()][player->GetCoordinateWingRightY()] = '>';
			}
		}break;
		case keyRight:
		{
			if (player->GetCoordinateWingRightY() < gameBoard->GetWallRight())
			{
				gameBoard->map[player->GetCocpitStartLocateX()][player->GetCockpitCoordinateY()] = ' ';
				gameBoard->map[player->GetLeftWingStartLocateX()][player->GetCoordinateLeftWingY()] = ' ';
				gameBoard->map[player->GetWingRightStartLocateX()][player->GetCoordinateWingRightY()] = ' ';
				player->IncrementCoordinateAirPlaneY();
				gameBoard->map[player->GetCocpitStartLocateX()][player->GetCockpitCoordinateY()] = '^';
				gameBoard->map[player->GetLeftWingStartLocateX()][player->GetCoordinateLeftWingY()] = '<';
				gameBoard->map[player->GetWingRightStartLocateX()][player->GetCoordinateWingRightY()] = '>';
			}
		}break;
		case keySpace:
		{
			if (missile->GetMissileNumber() < indexRestrictive&&gameBoard->GetBeginning())
			{
				missile->SetShootForward(player->GetCockpitCoordinateY());
				missile->SetShootCoord(14);
				missile[missile->GetMissileNumber()].SetPositionX(missile->GetShootCoord());
				missile[missile->GetMissileNumber()].SetPositionY(missile->GetShootForward());
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
						missile->SetShootForward(player->GetCockpitCoordinateY());
						missile->SetShootCoord(14);
						missile[missile->GetMissileNumber()].SetPositionX(missile->GetShootCoord());
						missile[missile->GetMissileNumber()].SetPositionY(missile->GetShootForward());
						missile[missile->GetMissileNumber()].SetActivate(true);
						break;
					}
			}
		}
		default: {}
		}
	}
}