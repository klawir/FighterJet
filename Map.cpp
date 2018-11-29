#include "Map.h"
#include "FighterAirPlane.h"


Map::Map()
{
	wallLeft = 2;
	wallRight = size2 - 2;
	beginning = true;
}


Map::~Map()
{
	beginning = true;
}

void Map::Draw(Player *player)
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
	cout << "lifes " << player->GetLife() << endl;
}
void Map::PrepareMap(FighterAirPlane *fighterAirPlane)
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
	map[fighterAirPlane->GetCocpitStartLocateX()][fighterAirPlane->GetCockpitCoordinateY()] = '^';
	map[fighterAirPlane->GetLeftWingStartLocateX()][fighterAirPlane->GetCoordinateLeftWingY()] = '<';
	map[fighterAirPlane->GetWingRightStartLocateX()][fighterAirPlane->GetCoordinateWingRightY()] = '>';
}
bool Map::GetBeginning()
{
	return beginning;
}
void Map::SetBeginning(bool set)
{
	beginning = set;
}
int Map::GetWallLeft()
{
	return wallLeft;
}
int Map::GetWallRight()
{
	return wallRight;
}