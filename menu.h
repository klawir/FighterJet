#include "biblioteki.h"
class Menu
{
	int klawisz, wybor;
	bool Wyjscie;
public:
	Menu();
	void cls();
	void kolor_bialy();
	void kolor_czerwony();
	void strzalki(int min, int max);
	void Pokaz();
	bool GetWyjscie() { return Wyjscie; }
	void SetWyjscie(bool zmien) { Wyjscie = zmien; }
	int GetWybor() { return wybor; }
};
Menu::Menu()
{
	Wyjscie = false;
	wybor = 1;
}
void Menu::cls()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void Menu::kolor_bialy()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void Menu::kolor_czerwony()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED) | FOREGROUND_INTENSITY;
}
void Menu::strzalki(int min, int max)
{
	klawisz = _getch();
	if (klawisz == 72)
	{
		if (wybor>min) --wybor;
	}
	else if (klawisz == 80)
	{
		if (wybor<max) ++wybor;
	}
}
void Menu::Pokaz()
{
	while (true)
	{
		kolor_bialy();
		if (wybor == 1) { kolor_czerwony(); }cout << "\t\t\t\tplay" << endl; kolor_bialy();
		if (wybor == 2) { kolor_czerwony(); }cout << "\t\t\t\tquit" << endl << endl << endl; kolor_bialy();
		cout << "\tMenu navigation up down, and accept enter" << endl;
		cout << "\tin game navigation lef right " << endl;
		cout << "\tshoot space" << endl;
		strzalki(1, 2);
		if (klawisz == 13) break;
		cls();
	}
}