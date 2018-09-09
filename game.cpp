#pragma once
#include "game.h"

int indexRestrictive;
bool IndexRestrictive;
int indexX, indexY;

Game::Game()
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
	player = new Player();
	gameBoard = new GameBoard();	
	
	enemyKilledFallingSpeedModulo = 7;
	enemyKilledIncrementLifeModulo = 10;
	indexRestrictiveModulo = 5;
}
void Game::Display()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
Game::~Game()
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
void Game::CreateMenu()
{
	menu = new Menu();
}
void Game::CreateMob()
{
	mob = new Mob();
}
void Game::CreatePlayer()
{
	player = new Player();	
}
void Game::CreateGameBoard()
{
	gameBoard = new GameBoard();
}
void Game::CreateMissile()
{
	missile = new Missile[size];
}
void Game::CreateKeyboard()
{
	keyboard = new Keyboard();
}

Menu *Game::GetMenu()
{
	return menu;
}
Mob *Game::GetMob()
{
	return mob;
}
Player *Game::GetPlayer()
{
	return player;
}
GameBoard *Game::GetGameBoard()
{
	return gameBoard;
}
Missile *Game::GetMissile()
{
	return missile;
}
Keyboard *Game::GetKeyboard()
{
	return keyboard;
}

bool Game::CheckHit()
{
	for (indexX = 0; indexX < indexRestrictive; indexX++)
	{
		for (indexY = 0; indexY <indexRestrictive; indexY++)
		{
			if (missile[indexX].GetPositionX() == mob[indexY].GetPosX()&&
				missile[indexX].GetPositionY() == mob[indexY].GetPosY())
			{
				gameBoard->map[missile[indexX].GetPositionX()][missile[indexX].GetPositionY()] = 'X';
				coordColisionX = missile[indexX].GetPositionX();
				coordColisionY= missile[indexX].GetPositionY();
				gameBoard->map[missile[indexX].GetPositionX()+1][missile[indexX].GetPositionY()] = ' ';
				missile[indexX].SetActivate(false);
				missile[indexX].SetPositionX(0);
				missile[indexX].SetPositionY(0);
				mob[indexY].SetShootDown(true);
				mob[indexY].SetPosX(0);
				return true;
			}
		}
	}
	return false;
}
void Game::_missile()
{
	if (missile[index].GeActivate())
	{
		gameBoard->map[missile[index].GetPositionX() + 1][missile[index].GetPositionY()] = ' ';
		gameBoard->map[missile[index].GetPositionX()][missile[index].GetPositionY()] = '!';
		missile[index].SetPositiionX();
		if (CheckHit()) {}
		if (missile[index].GetPositionX() < 0)
		{
			gameBoard->map[0][missile[index].GetPositionY()] = ' ';
			missile[index].SetActivate(false);
			missile->SetShootCoord(14);
		}
	}
}
int Game::EnemyRandom()
{
	return (rand() % 19) + 4;
}
void Game::Enemy()
{
	if (mob[index].GetActivate())
	{
		if (mobNumber < indexRestrictive&&counter%50==0)
		{
			mob[mobNumber].SetPosY(EnemyRandom());
			mob[mobNumber].SetActivate(true);
			gameBoard->map[mob[mobNumber].GetPosX()][mob[mobNumber].GetPosY()] = 'Q';
			mob[mobNumber].SetEnemyExist(true);
			mobNumber++;
		}
		else if (mobNumber > indexRestrictive) mobNumber = indexRestrictive;
		else if (mob[index].GetPosX() > 17||
			(mob[index].GetPosX()== 16&&
				mob[index].GetPosY() == player->GetCockpitCoordinateY())||
				(mob[index].GetPosX() == 17 &&
					mob[index].GetPosY() == player->GetCoordinateLeftWingY())||
					(mob[index].GetPosX() == 17 &&
						mob[index].GetPosY() == player->GetCoordinateWingRightY()))
		{
			player->DecrementLife();
			gameBoard->map[mob[index].GetPosX()][mob[index].GetPosY()] = ' ';
			mob[index].SetPosX(0);
			mob[index].SetPosY(EnemyRandom());
			gameBoard->map[mob[index].GetPosX()][mob[index].GetPosY()] = 'Q';
		}
		else if (mob[index].GetShootDown())
		{
			mob[index].SetShootDown(false);
			Sleep(40);
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
void Game::GameLoop()
{
	mob = new Mob[size];
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
				mob[index].SetPosX();
				gameBoard->map[mob[index].GetPosX()][mob[index].GetPosY()] = 'Q';
			}
			++fallingTime;
		}
		_missile();
		gameBoard->Map(player);
		keyboard->AirPlaneControll(player, gameBoard, missile);//Keyboard();
		Display();
		Enemy();
		if (player->Gameover())
		{
			cout << "you lose!" << endl;
			Sleep(1500);
			system("cls");
			ofstream plik;
			plik.open("score.txt");
			plik << "points " << player->getMoney() << endl;
			plik.close();
			break;
		}
	}
}