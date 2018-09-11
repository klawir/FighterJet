#pragma once
#include "librares.h"
class Menu
{
	int key, choice;
	bool exit;
public:
	Menu();
	void ClearScreen();
	void WhiteColor();
	void ColorRed();
	void MenuNavigation(int, int);
	void Display();
	bool GetExit();
	void SetExit(bool);
	int GetChoice();
};
