#include "game.h"
#include "menu.h"
#include "shoot.h"
#include <ctime>
#include "rlutil.h"
int main()
{
	HWND console = GetConsoleWindow();
	RECT consoleResolution;
	GetWindowRect(console, &consoleResolution);
	MoveWindow(console, (GetSystemMetrics(SM_CXSCREEN)/2)-(consoleResolution.right /2),
		(GetSystemMetrics(SM_CYSCREEN)/2)-(consoleResolution.bottom /2),
		consoleResolution.right, 
		consoleResolution.bottom, TRUE);
	srand(time(0));
	Game game;
	Menu menu;
	while (!menu.GetExit())
	{
		//system("cls");
		
		menu.Display();
		switch (menu.GetChoice())
		{
			case 1: break;
			case 2: return 0;
		}
		game.PrepareMap();
		system("cls");
		game.GameLoop();
		game.~Game();
		rlutil::setBackgroundColor(0);
	}
}