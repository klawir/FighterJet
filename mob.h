#pragma once
#include "Coordinates.h"

class Mob: public Coordinates
{
	bool exist;
	bool shootDown;
	char body;
public:
	Mob();

	char GetBody();
	
	bool GetEnemyExist();
	void SetEnemyExist(bool);

	void IncremeniPosX();

	bool GetShootDown();
	void SetShootDown(bool);

	bool GeActivate();
	void SetPosX(int);
	void SetPosY(int);
	void SetActivate(bool);

	int GetPosX();
	int GetPosY();
};