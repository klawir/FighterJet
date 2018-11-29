#pragma once
#include "librares.h"
#include "Player.h"
#include "FighterAirPlane.h"

class Map
{
	static const int size1 = 19;
	static const int size2 = 25;
	int wallLeft;
	int wallRight;
	bool beginning;
public:
	Map();
	~Map();
	char map[size1][size2];

	void Draw(Player *);
	void PrepareMap(FighterAirPlane*);
	
	bool GetBeginning();
	void SetBeginning(bool);

	int GetWallLeft();
	int GetWallRight();
};