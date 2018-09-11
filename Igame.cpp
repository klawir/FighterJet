#pragma once
#include "Igame.h"

int indexRestrictive;
bool IndexRestrictive;
int indexX, indexY;

IGame::IGame()
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
void IGame::Display()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
IGame::~IGame()
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
void IGame::CreateMenu()
{
	menu = new Menu();
}
void IGame::CreateMob()
{
	mob = new Mob[size];
}
void IGame::CreatePlayer()
{
	player = new Player();	
}
void IGame::CreateGameBoard()
{
	gameBoard = new GameBoard();
}
void IGame::CreateMissile()
{
	missile = new Missile[size];
}
void IGame::CreateKeyboard()
{
	keyboard = new Keyboard();
}
void IGame::CreateFighterAirPlane()
{
	fighterAirPlane = new FighterAirPlane();
}
Menu *IGame::GetMenu()
{
	return menu;
}
Mob *IGame::GetMob()
{
	return mob;
}
Player *IGame::GetPlayer()
{
	return player;
}
GameBoard *IGame::GetGameBoard()
{
	return gameBoard;
}
Missile *IGame::GetMissile()
{
	return missile;
}
Keyboard *IGame::GetKeyboard()
{
	return keyboard;
}
FighterAirPlane *IGame::GetFighterAirPlane()
{
	return fighterAirPlane;
}
bool IGame::CheckHit()
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
bool IGame::DetectGameOver()
{
	return player->GetLife()==0;
}
void IGame::GameOver()
{
	cout << "you lose!" << endl;
	Sleep(1500);
	system("cls");
	ofstream plik;
	plik.open("score.txt");
	plik << "points " << player->getMoney() << endl;
	plik.close();
}
void IGame::Missiles()
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
int IGame::EnemyRandom()
{
	return (rand() % 19) + 4;
}
void IGame::Enemy()
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
void IGame::GameLoop()
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
		gameBoard->Map(player);
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