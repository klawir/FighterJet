#pragma once
#include "GameCreator.h"

int indexRestrictive;
bool IndexRestrictive;
int indexX, indexY;

GameCreator::GameCreator()
{
	mobNumber = 0;
	enemyFallingTime = 40;
	bonusLife = 1;
	index = 0;
	mobBeginning = true;
	coordColisionX = 0;
	coordColisionY = 0;
	indexRestrictive = 1;
	IndexRestrictive = false;	
	
	enemyKilledFallingSpeedModulo = 7;
	enemyKilledIncrementLifeModulo = 10;
	indexRestrictiveModulo = 5;
}
void GameCreator::Display()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
GameCreator::~GameCreator()
{
	mobNumber = 0;
	enemyFallingTime = 40;
	bonusLife = 1;
	index = 0;
	mobBeginning = true;
	coordColisionX = 0;
	coordColisionY = 0;
	indexRestrictive = 1;
	IndexRestrictive = false;
	player->~Player();
}
void GameCreator::CreateMenu()
{
	menu = new Menu();
}
void GameCreator::CreateMob()
{
	mob = new Mob[size];
}
void GameCreator::CreatePlayer()
{
	player = new Player();	
}
void GameCreator::CreateGameBoard()
{
	gameBoard = new Map();
}
void GameCreator::CreateMissile()
{
	missile = new Missile[size];
}
void GameCreator::CreateKeyboard()
{
	keyboard = new Keyboard();
}
void GameCreator::CreateFighterAirPlane()
{
	fighterAirPlane = new FighterAirPlane();
}
Menu *GameCreator::GetMenu()
{
	return menu;
}
Mob *GameCreator::GetMob()
{
	return mob;
}
Player *GameCreator::GetPlayer()
{
	return player;
}
Map *GameCreator::GetGameBoard()
{
	return gameBoard;
}
Missile *GameCreator::GetMissile()
{
	return missile;
}
Keyboard *GameCreator::GetKeyboard()
{
	return keyboard;
}
FighterAirPlane *GameCreator::GetFighterAirPlane()
{
	return fighterAirPlane;
}
bool GameCreator::CheckHit()
{
	for (indexX = 0; indexX < indexRestrictive; indexX++)
	{
		for (indexY = 0; indexY <indexRestrictive; indexY++)
		{
			if (missile[indexX].GetPosX() == mob[indexY].GetPosX()&&
				missile[indexX].GetPosY() == mob[indexY].GetPosY())
			{
				gameBoard->map[missile[indexX].GetPosX()][missile[indexX].GetPosY()] = 'X';
				coordColisionX = missile[indexX].GetPosX();
				coordColisionY= missile[indexX].GetPosY();
				gameBoard->map[missile[indexX].GetPosX()+1][missile[indexX].GetPosY()] = ' ';
				missile[indexX].SetActivate(false);
				missile[indexX].SetPosX(0);
				missile[indexX].SetPosY(0);
				mob[indexY].SetShootDown(true);
				mob[indexY].SetPosX(0);
				return true;
			}
		}
	}
	return false;
}
bool GameCreator::DetectGameOver()
{
	return player->GetLife()==0;
}
void GameCreator::GameOver()
{
	cout << "you lose!" << endl;
	Sleep(1500);
	system("cls");
	ofstream plik;
	plik.open("score.txt");
	plik << "points " << player->getMoney() << endl;
	plik.close();
}
void GameCreator::Missiles()
{
	if (missile[index].GeActivate())
	{
		gameBoard->map[missile[index].GetPosX() + 1][missile[index].GetPosY()] = ' ';
		gameBoard->map[missile[index].GetPosX()][missile[index].GetPosY()] = '!';
		missile[index].DecrementPositiionX();
		if (CheckHit()) {}
		if (missile[index].GetPosX() < 0)
		{
			gameBoard->map[0][missile[index].GetPosY()] = ' ';
			missile[index].SetActivate(false);
			missile->SetShootCoord(14);
		}
	}
}
int GameCreator::EnemyRandom()
{
	return (rand() % 19) + 4;
}
void GameCreator::Enemy()
{
	if (mob[index].GeActivate())
	{
		if (mobNumber < indexRestrictive&&counter%50==0)
		{
			mob[mobNumber].SetPosY(EnemyRandom());
			mob[mobNumber].SetActivate(true);
			gameBoard->map[mob[mobNumber].GetPosX()][mob[mobNumber].GetPosY()] = mob->GetBody();
			mob[mobNumber].SetEnemyExist(true);
			mobNumber++;
		}
		else if (mobNumber > indexRestrictive) mobNumber = indexRestrictive;
		else if (mob[index].GetPosX() > 17||
			(mob[index].GetPosX()== 16&&
				mob[index].GetPosY() == fighterAirPlane->GetCockpitCoordinateY())||
				(mob[index].GetPosX() == 17 &&
					mob[index].GetPosY() == fighterAirPlane->GetCoordinateLeftWingY())||
					(mob[index].GetPosX() == 17 &&
						mob[index].GetPosY() == fighterAirPlane->GetCoordinateWingRightY()))
		{
			player->DecrementLife();
			gameBoard->map[mob[index].GetPosX()][mob[index].GetPosY()] = ' ';
			mob[index].SetPosX(0);
			mob[index].SetPosY(EnemyRandom());
			gameBoard->map[mob[index].GetPosX()][mob[index].GetPosY()] = mob->GetBody();
		}
		else if (mob[index].GetShootDown())
		{
			mob[index].SetShootDown(false);
			//Sleep(40);
			gameBoard->map[coordColisionX][coordColisionY] = ' ';
			mob[index].SetPosX(0);
			mob[index].SetPosY(0);
			++enemyKilled;
			if (enemyKilled % enemyKilledFallingSpeedModulo == 0)
			{
				if (enemyFallingTime < 0)
					enemyFallingTime = 0;
				else
				{
					--enemyFallingTime;
					bonusLife++;
				}
			}
			else if (enemyKilled % enemyKilledIncrementLifeModulo == 0)
				player->IncrementLife();
			else if (enemyKilled % indexRestrictiveModulo == 0)
				indexRestrictive++;
			player->AddMoney(bonusLife*2);
			mob[index].SetPosY(EnemyRandom());
		}
		else if (indexRestrictive > size) 
			indexRestrictive = size;
	}
}
void GameCreator::GameLoop()
{
	//mob = new Mob[size];
	counter = 0;
	player->SetMoney(0);
	fallingTime = 1;
	enemyKilled = 0;
	for (;;)
	{
		if (index >= indexRestrictive - 1) 
			index = 0;
		else index++;
		counter++;
		if (counter > 999) counter = 0;
		else if (fallingTime > 99) fallingTime=0;
		else if (mob[index].GetEnemyExist())
		{
			if (fallingTime%enemyFallingTime == 0)
			{
				gameBoard->map[mob[index].GetPosX()][mob[index].GetPosY()] = ' ';
				mob[index].IncremeniPosX();
				gameBoard->map[mob[index].GetPosX()][mob[index].GetPosY()] = mob->GetBody();
			}
			++fallingTime;
		}
		Missiles();
		gameBoard->Draw(player);
		keyboard->AirPlaneControll(fighterAirPlane, gameBoard, missile);
		Display();
		Enemy();
		if (DetectGameOver())
		{
			GameOver();
			break;
		}
	}
}