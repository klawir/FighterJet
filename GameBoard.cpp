#include "GameBoard.h"



GameBoard::GameBoard()
{
	wallLeft = 2;
	wallRight = size2 - 2;
	beginning = true;
}


GameBoard::~GameBoard()
{
	beginning = true;
}

void GameBoard::Map(Player *player)
{
	rlutil::setBackgroundColor(7);
	for (int indexX = 0; indexX < size1; indexX++)
	{
		for (int indexY = 0; indexY < size2; indexY++)
		{
			map[indexX][size2 - 1] = '|';
			if (indexY == size2 < 1)
				cout << endl;
			else if (map[indexX][indexY] == '|')
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
void GameBoard::PrepareMap(Player *player)
{
	int indexX;
	int indexY;
	for (indexX = 0; indexX < size1; indexX++)
	{
		for (indexY = 0; indexY < size2; indexY++)
		{
			map[indexX][indexY] = ' ';
			if (indexY == size2 < 1)
				cout << endl;
			cout << map[indexX][indexY];
		}
	}
	for (indexX = 0; indexX < size1; indexX++)
		map[indexX][1] = '|';
	for (indexX = 0; indexX < size1; indexX++)
		map[indexX][0] = ' ';
	map[0][0] = map[0][size2 - 1] = ' ';
	map[player->GetCocpitStartLocateX()][player->GetCockpitCoordinateY()] = '^';
	map[player->GetLeftWingStartLocateX()][player->GetCoordinateLeftWingY()] = '<';
	map[player->GetWingRightStartLocateX()][player->GetCoordinateWingRightY()] = '>';
}
bool GameBoard::GetBeginning()
{
	return beginning;
}
void GameBoard::SetBeginning(bool set)
{
	beginning = set;
}
int GameBoard::GetWallLeft()
{
	return wallLeft;
}
int GameBoard::GetWallRight()
{
	return wallRight;
}