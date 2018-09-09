#pragma once
#include "librares.h"
class Mob
{
	int posX, posY;
	bool activate;
	bool exist;
	bool shootDown;
public:
	Mob()
	{
		posX = posY = 0;
		activate = true;
		shootDown = false;
	}
	void SetPosX(int a) { posX = a; }
	void SetPosY(int a) { posY = a; }
	void SetActivate(bool a) { activate = a; }
	int GetPosX() { return posX; }
	int GetPosY() { return posY; }
	bool GetActivate() { return activate; }
	bool GetEnemyExist() {return exist;}
	void SetEnemyExist(bool a) { exist = a; }
	void SetPosX() { posX++; }
	bool GetShootDown() { return shootDown; }
	void SetShootDown(bool a) { shootDown=a; }
};
