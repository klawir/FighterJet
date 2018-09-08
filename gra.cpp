#include "gra.h"
#include "rlutil.h"
#include "strzal.h"
#include "mob.h"
#include "Player.h"

const int sizeOfArray = 3;
int indexOgraniczajacy;
bool _indexOgraniczajacy;
Naboj *naboj;
Mob *mob;
Player *player;
Gra::Gra()
{
	ktoryMob = 0;
	this->predkosc_opadania_wroga = 40;
	this->lewaSciana = 2;
	_gra = true;
	bonus = 1;
	ktoryPocisk = 0;
	index = 0;
	poczatek = poczatekMob=true;
	wspolrzednaKolizyjnaA = 0;
	wspolrzednaKolizyjnaB = 0;
	indexOgraniczajacy = 1;
	_indexOgraniczajacy = false;
	player = new Player();
}
void Gra::Ekran()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
Gra::~Gra()
{
	ktoryMob = 0;
	this->predkosc_opadania_wroga = 40;
	this->lewaSciana = 2;
	_gra = true;
	bonus = 1;
	ktoryPocisk = 0;
	index = 0;
	poczatek = poczatekMob = true;
	wspolrzednaKolizyjnaA = 0;
	wspolrzednaKolizyjnaB = 0;
	indexOgraniczajacy = 1;
	_indexOgraniczajacy = false;
	player->~Player();
}
void Gra::przygotuj_plansze()
{
	player->SetCoordinateAirPlaneUp(15);
	player->SetCoordinateAirPlaneLeft(14);
	player->SetCoordinateAirPlaneRight(16);
	for (a = 0; a<rozmiar1; a++)
	{
		for (b = 0; b<rozmiar2; b++)
		{
			map[a][b] = ' ';
			if (b == rozmiar2<1)
				cout << endl;
			cout << map[a][b];
		}
	}
	for (a = 0; a<rozmiar1; a++)
		map[a][1] = '|';
	for (a = 0; a<rozmiar1; a++)
		map[a][0] = ' ';
	map[0][0] = map[0][rozmiar2 - 1] = ' ';
	map[16][player->GetCoordinateAirPlaneUp()] = '^';
	map[17][player->GetCoordinateAirPlaneLeft()] = '<';
	map[17][player->GetCoordinateAirPlaneRight()] = '>';
} 
void Gra::plansza()
{
	rlutil::setBackgroundColor(7);
	for (a = 0; a<rozmiar1; a++)
	{
		for (b = 0; b<rozmiar2; b++)
		{
			
			map[a][rozmiar2 - 1] = '|';
			if (b == rozmiar2 < 1)
				cout << endl;
			else if(map[a][b]=='|')
				rlutil::setColor(3);
			else if (map[a][b] == 'X')
				rlutil::setColor(8);
			else if (map[a][b] == '^')
				rlutil::setColor(5);
			else if (map[a][b] == '<')
				rlutil::setColor(5);
			else if (map[a][b] == '>')
				rlutil::setColor(5);
			else if (map[a][b] == 'Q')
				rlutil::setColor(2);
			else if (map[a][b] == '!')
				rlutil::setColor(4);
			cout << map[a][b];
		}
	}
	cout << "$ " << player->getMoney() << " " << endl;
	cout << "lifes " << player->getLife() << endl;
}
void Gra::klawiatura()
{
	int klawisz;
	if (_kbhit())
	{
		klawisz = _getch();
		switch (klawisz)
		{
		case 75:
		{
			if (player->GetCoordinateAirPlaneUp()>lewaSciana && player->GetCoordinateAirPlaneLeft()>lewaSciana && player->GetCoordinateAirPlaneRight()>lewaSciana)
			{
				map[16][player->GetCoordinateAirPlaneUp()] = ' ';
				map[17][player->GetCoordinateAirPlaneLeft()] = ' ';
				map[17][player->GetCoordinateAirPlaneRight()] = ' ';
				player->DecrementCoordinateAirPlane();
				map[16][player->GetCoordinateAirPlaneUp()] = '^';
				map[17][player->GetCoordinateAirPlaneLeft()] = '<';
				map[17][player->GetCoordinateAirPlaneRight()] = '>';
			}
		}break;
		case 77:
		{
			if (player->GetCoordinateAirPlaneUp()<22 && player->GetCoordinateAirPlaneLeft()<21 && player->GetCoordinateAirPlaneRight()<23)
			{
				map[16][player->GetCoordinateAirPlaneUp()] = ' ';
				map[17][player->GetCoordinateAirPlaneLeft()] = ' ';
				map[17][player->GetCoordinateAirPlaneRight()] = ' ';
				player->IncrementCoordinateAirPlane();
				map[16][player->GetCoordinateAirPlaneUp()] = '^';
				map[17][player->GetCoordinateAirPlaneLeft()] = '<';
				map[17][player->GetCoordinateAirPlaneRight()] = '>';
			}
		}break;
		case 32:
		{
			if (ktoryPocisk < indexOgraniczajacy&&poczatek)
			{
				strzal_prosty = player->GetCoordinateAirPlaneUp();
				strzal = 14;
				naboj[ktoryPocisk].SetpolozenieX(strzal);
				naboj[ktoryPocisk].SetpolozenieY(strzal_prosty);
				naboj[ktoryPocisk].Setaktywny(true); 
				ktoryPocisk++;
			}
			else
			{
				poczatek = false;
				for (int a = 0; a < indexOgraniczajacy; a++)
					if (!naboj[a].Getaktywny())
					{
						ktoryPocisk = a;
						strzal_prosty = player->GetCoordinateAirPlaneUp();
						strzal = 14;
						naboj[ktoryPocisk].SetpolozenieX(strzal);
						naboj[ktoryPocisk].SetpolozenieY(strzal_prosty);
						naboj[ktoryPocisk].Setaktywny(true);
						break;
					}
			}
		}
		default: {}
		}
	}
}
bool Gra::Sprawdz()
{
	for (int a = 0; a < indexOgraniczajacy; a++)
	{
		for (int b = 0; b <indexOgraniczajacy; b++)
		{
			if (naboj[a].GetpolozenieX() == mob[b].GetpolozenieX()&&
				naboj[a].GetpolozenieY() == mob[b].GetpolozenieY())
			{
				map[naboj[a].GetpolozenieX()][naboj[a].GetpolozenieY()] = 'X';
				wspolrzednaKolizyjnaA = naboj[a].GetpolozenieX();
				wspolrzednaKolizyjnaB= naboj[a].GetpolozenieY();
				map[naboj[a].GetpolozenieX()+1][naboj[a].GetpolozenieY()] = ' ';
				naboj[a].Setaktywny(false);
				naboj[a].SetpolozenieX(0);
				naboj[a].SetpolozenieY(0);
				mob[b].Setzestrzelony(true);
				mob[b].SetpolozenieX(0);
				return true;
			}
		}
	}
	return false;
}
void Gra::Pocisk()
{
	if (naboj[index].Getaktywny())
	{
		map[naboj[index].GetpolozenieX() + 1][naboj[index].GetpolozenieY()] = ' ';
		map[naboj[index].GetpolozenieX()][naboj[index].GetpolozenieY()] = '!';
		naboj[index]._SetpolozenieX();
		if (Sprawdz()) {}
		if (naboj[index].GetpolozenieX() < 0)
		{
			map[0][naboj[index].GetpolozenieY()] = ' ';
			naboj[index].Setaktywny(false);
			strzal = 14;
		}
	}
}
int Gra::wylosuj_wroga()
{
	return (rand() % 19) + 4;
}
void Gra::Wrog()
{
	if (mob[index].Getaktywny())
	{
		if (ktoryMob < indexOgraniczajacy&&licznik%50==0)
		{
			mob[ktoryMob].SetpolozenieY(wylosuj_wroga());
			mob[ktoryMob].Setaktywny(true);
			map[mob[ktoryMob].GetpolozenieX()][mob[ktoryMob].GetpolozenieY()] = 'Q';
			mob[ktoryMob].SetwrogIstnieje(true);
			ktoryMob++;
		}
		else if (ktoryMob > indexOgraniczajacy) ktoryMob = indexOgraniczajacy;
		else if (mob[index].GetpolozenieX() > 17||
			(mob[index].GetpolozenieX()== 16&&
				mob[index].GetpolozenieY() == player->GetCoordinateAirPlaneUp())||
				(mob[index].GetpolozenieX() == 17 &&
					mob[index].GetpolozenieY() == player->GetCoordinateAirPlaneLeft())||
					(mob[index].GetpolozenieX() == 17 &&
						mob[index].GetpolozenieY() == player->GetCoordinateAirPlaneRight()))
		{
			player->DecrementLife();
			map[mob[index].GetpolozenieX()][mob[index].GetpolozenieY()] = ' ';
			mob[index].SetpolozenieX(0);
			mob[index].SetpolozenieY(wylosuj_wroga());
			map[mob[index].GetpolozenieX()][mob[index].GetpolozenieY()] = 'Q';
		}
		else if (mob[index].Getzestrzelony())
		{
			mob[index].Setzestrzelony(false);
			Sleep(40);
			map[wspolrzednaKolizyjnaA][wspolrzednaKolizyjnaB] = ' ';
			mob[index].SetpolozenieX(0);
			mob[index].SetpolozenieY(0);
			++wrog_zabity;
			if (wrog_zabity % 7 == 0)
			{
				if (predkosc_opadania_wroga < 0) { predkosc_opadania_wroga = 0; }
				else
				{
					--predkosc_opadania_wroga;
					bonus++;
				}
			}
			else if (wrog_zabity % 10 == 0) player->IncrementLife();
			else if (wrog_zabity % 5 == 0) indexOgraniczajacy++;
			player->AddMoney(bonus*2);
			mob[index].SetpolozenieY(wylosuj_wroga());
		}
		else if (indexOgraniczajacy > sizeOfArray) indexOgraniczajacy = sizeOfArray;
	}
}
void Gra::petla_gry()
{
	naboj = new Naboj[sizeOfArray];
	mob = new Mob[sizeOfArray];
	licznik = 0;
	player->SetMoney(0);
	czas_opadania = 1;
	wrog_zabity = 0;
	for (;;)
	{
		if (index >= indexOgraniczajacy - 1) index = 0;
		else index++;
		licznik++;
		if (licznik > 999) licznik = 0;
		else if (czas_opadania > 99) czas_opadania=0;
		else if (mob[index].GetwrogIstnieje())
		{
			if (czas_opadania%predkosc_opadania_wroga == 0)
			{
				map[mob[index].GetpolozenieX()][mob[index].GetpolozenieY()] = ' ';
				mob[index]._SetpolozenieX();
				map[mob[index].GetpolozenieX()][mob[index].GetpolozenieY()] = 'Q';
			}
			++czas_opadania;
		}
		Pocisk();
		plansza();
		klawiatura();
		Ekran();
		Wrog();
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