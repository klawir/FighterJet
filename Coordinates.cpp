#include "Coordinates.h"


Coordinates::Coordinates()
{
	posX = 0;
	posY = 0;
	activate = false;
}

void Coordinates::SetPosX(int set)
{
	posX = set;
}
void Coordinates::SetPosY(int set)
{
	posY = set;
}
void Coordinates::SetActivate(bool set)
{
	activate = set;
}

int Coordinates::GetPosX()
{
	return posX;
}
int Coordinates::GetPosY()
{
	return posY;
}

bool Coordinates::GeActivate()
{
	return activate;
}