#pragma once
#include "librares.h"
#include "Player.h"
class GameBoard
{
	static const int size1 = 19;
	static const int size2 = 25;
	int wallLeft;
	int wallRight;
	bool beginning;
public:
	GameBoard();
	~GameBoard();
	char map[size1][size2];

	void Map(Player *player);
	void PrepareMap(Player *player);
	
	bool GetBeginning();
	void SetBeginning(bool);

	int GetWallLeft();
	int GetWallRight();
};