#pragma once
#include "mob.h"

Mob::Mob():Coordinates()
{
	//posX = 0;
	//posY = 0;
	activate = true;
	shootDown = false;
	body = 'Q';
}
char Mob::GetBody()
{
	return body;
}
bool Mob::GetEnemyExist() 
{
	return exist;
}
void Mob::SetEnemyExist(bool set) 
{
	exist = set; 
}
void Mob::IncremeniPosX() 
{
	posX++; 
}
bool Mob::GetShootDown()
{
	return shootDown;
}
void Mob::SetShootDown(bool set) 
{
	shootDown = set;
}

void Mob::SetPosX(int set)
{
	posX = set;
}
void Mob::SetPosY(int set)
{
	posY = set;
}
void Mob::SetActivate(bool set)
{
	activate = set;
}

int Mob::GetPosX()
{
	return posX;
}
int Mob::GetPosY()
{
	return posY;
}

bool Mob::GeActivate()
{
	return activate;
}