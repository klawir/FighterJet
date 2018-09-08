#pragma once
#include "librares.h"
class Game
{
	static const int size1 = 19;
	static const int size2 = 25;
	int shootCoord, shootForward, enemyKilled;
	int fallingTime, enemyFallingTime, indexX, indexY;
	int enemyKilledFallingSpeedModulo;
	int enemyKilledIncrementLifeModulo;
	int indexRestrictiveModulo;
	
	char map[size1][size2];
	int wallLeft;
	int wallRight;
	int counter;
	int bonusLife;
	int missileNumber, mobNumber;
	int index;
	bool beginning, mobBeginning;
	int coordColisionX, coordColisionY;
public:
	Game();
	~Game();
	void PrepareMap();
	void Map();
	void Keyboard();
	int EnemyRandom();
	void Enemy();
	void Missile();
	void GameLoop();
	void Display();
	bool Check();
};