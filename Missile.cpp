
#include "Missile.h"

Missile::Missile()
{
	posX = 0;
	posY = 0;
	activate = false;
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