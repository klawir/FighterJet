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
	void MenuNavigation(int min, int max);
	void Display();
	bool GetExit() { return exit; }
	void SetExit(bool zmien) { exit = zmien; }
	int GetChoice() { return choice; }
};
