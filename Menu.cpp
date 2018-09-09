#pragma once
#include "menu.h"

Menu::Menu()
{
	exit = false;
	choice = 1;
}
void Menu::ClearScreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void Menu::WhiteColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void Menu::ColorRed()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED) | FOREGROUND_INTENSITY;
}
void Menu::MenuNavigation(int min, int max)
{
	key = _getch();
	if (key == keyUp)
		if (choice > min) choice--;
		else if (key == keyDown)
			if (choice < max) choice++;
}
void Menu::Display()
{
	while (true)
	{
		WhiteColor();
		if (choice == 1) { ColorRed(); }cout << "\t\t\t\tplay" << endl; WhiteColor();
		if (choice == 2) { ColorRed(); }cout << "\t\t\t\tquit" << endl << endl << endl; WhiteColor();
		cout << "\tMenu navigation up down, and accept enter" << endl;
		cout << "\tin game navigation lef right " << endl;
		cout << "\tshoot space" << endl;
		MenuNavigation(1, 2);
		if (key == keyEnter) break;
		ClearScreen();
	}
}