#pragma once
#include "librares.h"
#include "rlutil.h"
#include "Missile.h"
#include "mob.h"
#include "Player.h"
#include "GameBoard.h"
#include "Keyboard.h"
#include "menu.h"

class Game
{
	int enemyKilled;
	int fallingTime, enemyFallingTime, indexX, indexY;
	int enemyKilledFallingSpeedModulo;
	int enemyKilledIncrementLifeModulo;
	int indexRestrictiveModulo;

	int counter;
	int bonusLife;
	int mobNumber;
	int index;
	bool mobBeginning;
	int coordColisionX, coordColisionY;
	Menu *menu;
	Mob *mob;
	Player *player;
	GameBoard *gameBoard;
	Missile *missile;
	Keyboard *keyboard;
public:
	Game();
	~Game();
	void CreateMenu();
	void CreateMob();
	void CreatePlayer();
	void CreateGameBoard();
	void CreateMissile();
	void CreateKeyboard();

	Menu *GetMenu();
	Mob *GetMob();
	Player *GetPlayer();
	GameBoard *GetGameBoard();
	Missile *GetMissile();
	Keyboard *GetKeyboard();

	int EnemyRandom();
	void Enemy();
	void _missile();
	void GameLoop();
	void Display();
	bool CheckHit();
};