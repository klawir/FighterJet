#pragma once
#include "game.h"
#include "rlutil.h"
#include "shoot.h"
#include "mob.h"
#include "Player.h"

const int sizeOfArray = 3;
int indexRestrictive;
bool IndexRestrictive;
Naboj *missile;
Mob *mob;
Player *player;
Game::Game()
{
	mobNumber = 0;
	enemyFallingTime = 40;
	wallLeft = 2;
	wallRight = size2-2;
	bonusLife = 1;
	missileNumber = 0;
	index = 0;
	beginning = true;
	mobBeginning = true;
	coordColisionX = 0;
	coordColisionY = 0;
	indexRestrictive = 1;
	IndexRestrictive = false;
	player = new Player();
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
	wallLeft = 2;
	bonusLife = 1;
	missileNumber = 0;
	index = 0;
	beginning = true;
	mobBeginning = true;
	coordColisionX = 0;
	coordColisionY = 0;
	indexRestrictive = 1;
	IndexRestrictive = false;
	player->~Player();
}
void Game::PrepareMap()
{
	for (indexX = 0; indexX<size1; indexX++)
	{
		for (indexY = 0; indexY<size2; indexY++)
		{
			map[indexX][indexY] = ' ';
			if (indexY == size2<1)
				cout << endl;
			cout << map[indexX][indexY];
		}
	}
	for (indexX = 0; indexX<size1; indexX++)
		map[indexX][1] = '|';
	for (indexX = 0; indexX<size1; indexX++)
		map[indexX][0] = ' ';
	map[0][0] = map[0][size2 - 1] = ' ';
	map[player->GetCocpitStartLocateX()][player->GetCockpitCoordinateY()] = '^';
	map[player->GetLeftWingStartLocateX()][player->GetCoordinateLeftWingY()] = '<';
	map[player->GetWingRightStartLocateX()][player->GetCoordinateWingRightY()] = '>';
} 
void Game::Map()
{
	rlutil::setBackgroundColor(7);
	for (indexX = 0; indexX<size1; indexX++)
	{
		for (indexY = 0; indexY<size2; indexY++)
		{
			map[indexX][size2 - 1] = '|';
			if (indexY == size2 < 1)
				cout << endl;
			else if(map[indexX][indexY]=='|')
				rlutil::setColor(red);
			else if (map[indexX][indexY] == 'X')
				rlutil::setColor(2);
			else if (map[indexX][indexY] == '^' || map[indexX][indexY] == '<' || map[indexX][indexY] == '>')
				rlutil::setColor(bronze);
			else if (map[indexX][indexY] == 'Q')
				rlutil::setColor(2);
			else if (map[indexX][indexY] == '!')
				rlutil::setColor(4);
			cout << map[indexX][indexY];
		}
	}
	cout << "$ " << player->getMoney() << " " << endl;
	cout << "lifes " << player->getLife() << endl;
}
void Game::Keyboard()
{
	int key;
	if (_kbhit())
	{
		key = _getch();
		switch (key)
		{
		case keyLeft:
		{
			if (player->GetCoordinateLeftWingY()>wallLeft)
			{
				map[player->GetCocpitStartLocateX()][player->GetCockpitCoordinateY()] = ' ';
				map[player->GetLeftWingStartLocateX()][player->GetCoordinateLeftWingY()] = ' ';
				map[player->GetWingRightStartLocateX()][player->GetCoordinateWingRightY()] = ' ';
				player->DecrementCoordinateAirPlaneY();
				map[player->GetCocpitStartLocateX()][player->GetCockpitCoordinateY()] = '^';
				map[player->GetLeftWingStartLocateX()][player->GetCoordinateLeftWingY()] = '<';
				map[player->GetWingRightStartLocateX()][player->GetCoordinateWingRightY()] = '>';
			}
		}break;
		case keyRight:
		{
			if (player->GetCoordinateWingRightY()< wallRight)
			{
				map[player->GetCocpitStartLocateX()][player->GetCockpitCoordinateY()] = ' ';
				map[player->GetLeftWingStartLocateX()][player->GetCoordinateLeftWingY()] = ' ';
				map[player->GetWingRightStartLocateX()][player->GetCoordinateWingRightY()] = ' ';
				player->IncrementCoordinateAirPlaneY();
				map[player->GetCocpitStartLocateX()][player->GetCockpitCoordinateY()] = '^';
				map[player->GetLeftWingStartLocateX()][player->GetCoordinateLeftWingY()] = '<';
				map[player->GetWingRightStartLocateX()][player->GetCoordinateWingRightY()] = '>';
			}
		}break;
		case keySpace:
		{
			if (missileNumber < indexRestrictive&&beginning)
			{
				shootForward = player->GetCockpitCoordinateY();
				shootCoord = 14;
				missile[missileNumber].SetPositionX(shootCoord);
				missile[missileNumber].SetPositionY(shootForward);
				missile[missileNumber].SetActivate(true); 
				missileNumber++;
			}
			else
			{
				beginning = false;
				for (int a = 0; a < indexRestrictive; a++)
					if (!missile[a].GeActivate())
					{
						missileNumber = a;
						shootForward = player->GetCockpitCoordinateY();
						shootCoord = 14;
						missile[missileNumber].SetPositionX(shootCoord);
						missile[missileNumber].SetPositionY(shootForward);
						missile[missileNumber].SetActivate(true);
						break;
					}
			}
		}
		default: {}
		}
	}
}
bool Game::Check()
{
	for (int a = 0; a < indexRestrictive; a++)
	{
		for (int b = 0; b <indexRestrictive; b++)
		{
			if (missile[a].GetPositionX() == mob[b].GetpolozenieX()&&
				missile[a].GetPositionY() == mob[b].GetpolozenieY())
			{
				map[missile[a].GetPositionX()][missile[a].GetPositionY()] = 'X';
				coordColisionX = missile[a].GetPositionX();
				coordColisionY= missile[a].GetPositionY();
				map[missile[a].GetPositionX()+1][missile[a].GetPositionY()] = ' ';
				missile[a].SetActivate(false);
				missile[a].SetPositionX(0);
				missile[a].SetPositionY(0);
				mob[b].Setzestrzelony(true);
				mob[b].SetpolozenieX(0);
				return true;
			}
		}
	}
	return false;
}
void Game::Missile()
{
	if (missile[index].GeActivate())
	{
		map[missile[index].GetPositionX() + 1][missile[index].GetPositionY()] = ' ';
		map[missile[index].GetPositionX()][missile[index].GetPositionY()] = '!';
		missile[index].SetPositiionX();
		if (Check()) {}
		if (missile[index].GetPositionX() < 0)
		{
			map[0][missile[index].GetPositionY()] = ' ';
			missile[index].SetActivate(false);
			shootCoord = 14;
		}
	}
}
int Game::EnemyRandom()
{
	return (rand() % 19) + 4;
}
void Game::Enemy()
{
	if (mob[index].Getaktywny())
	{
		if (mobNumber < indexRestrictive&&counter%50==0)
		{
			mob[mobNumber].SetpolozenieY(EnemyRandom());
			mob[mobNumber].Setaktywny(true);
			map[mob[mobNumber].GetpolozenieX()][mob[mobNumber].GetpolozenieY()] = 'Q';
			mob[mobNumber].SetwrogIstnieje(true);
			mobNumber++;
		}
		else if (mobNumber > indexRestrictive) mobNumber = indexRestrictive;
		else if (mob[index].GetpolozenieX() > 17||
			(mob[index].GetpolozenieX()== 16&&
				mob[index].GetpolozenieY() == player->GetCockpitCoordinateY())||
				(mob[index].GetpolozenieX() == 17 &&
					mob[index].GetpolozenieY() == player->GetCoordinateLeftWingY())||
					(mob[index].GetpolozenieX() == 17 &&
						mob[index].GetpolozenieY() == player->GetCoordinateWingRightY()))
		{
			player->DecrementLife();
			map[mob[index].GetpolozenieX()][mob[index].GetpolozenieY()] = ' ';
			mob[index].SetpolozenieX(0);
			mob[index].SetpolozenieY(EnemyRandom());
			map[mob[index].GetpolozenieX()][mob[index].GetpolozenieY()] = 'Q';
		}
		else if (mob[index].Getzestrzelony())
		{
			mob[index].Setzestrzelony(false);
			Sleep(40);
			map[coordColisionX][coordColisionY] = ' ';
			mob[index].SetpolozenieX(0);
			mob[index].SetpolozenieY(0);
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
			mob[index].SetpolozenieY(EnemyRandom());
		}
		else if (indexRestrictive > sizeOfArray) indexRestrictive = sizeOfArray;
	}
}
void Game::GameLoop()
{
	missile = new Naboj[sizeOfArray];
	mob = new Mob[sizeOfArray];
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
		else if (mob[index].GetwrogIstnieje())
		{
			if (fallingTime%enemyFallingTime == 0)
			{
				map[mob[index].GetpolozenieX()][mob[index].GetpolozenieY()] = ' ';
				mob[index]._SetpolozenieX();
				map[mob[index].GetpolozenieX()][mob[index].GetpolozenieY()] = 'Q';
			}
			++fallingTime;
		}
		Missile();
		Map();
		Keyboard();
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