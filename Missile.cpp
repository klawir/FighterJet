
#include "Missile.h"

Missile::Missile(): Coordinates()
{
	missileNumber = 0;
	shootCoord=14;
	shootForward=14;
}
Missile::~Missile()
{
	missileNumber = 0;
}
void Missile::IncreaseMissileNumber()
{
	missileNumber++;
}
void Missile::DecrementPositiionX() 
{
	posX--;
}
int Missile::GetMissileNumber()
{
	return missileNumber;
}
void Missile::SetMissileNumber(int set)
{
	missileNumber = set;
}
void Missile::SetShootForward(int set)
{
	shootForward = set;
}
int Missile::GetShootForward()
{
	return shootForward;
}
void Missile::SetShootCoord(int set)
{
	shootCoord = set;
}
int Missile::GetShootCoord()
{
	return shootCoord;
}
void Missile::SetPosX(int set)
{
	posX = set;
}
void Missile::SetPosY(int set)
{
	posY = set;
}
void Missile::SetActivate(bool set)
{
	activate = set;
}

int Missile::GetPosX()
{
	return posX;
}
int Missile::GetPosY()
{
	return posY;
}

bool Missile::GeActivate()
{
	return activate;
}