#pragma once
#include "GameCreator.h"
#include "GameManager.h"

int main()
{
	GameCreator *game = new GameCreator();
	game->CreateMenu();
	game->CreateMob();
	game->CreatePlayer();
	game->CreateGameBoard();
	game->CreateMissile();
	game->CreateKeyboard();
	game->CreateFighterAirPlane();
	//link 20001 - ref err?
	HWND console = GetConsoleWindow();
	RECT consoleResolution;
	GetWindowRect(console, &consoleResolution);
	MoveWindow(console, (GetSystemMetrics(SM_CXSCREEN)/2)-(consoleResolution.right /2),
		(GetSystemMetrics(SM_CYSCREEN)/2)-(consoleResolution.bottom /2),
		consoleResolution.right, 
		consoleResolution.bottom, TRUE);
	srand(time(0));
	
	while (!game->GetMenu()->GetExit())
	{
		game->GetMenu()->Display();
		switch (game->GetMenu()->GetChoice())
		{
			case 1: break;
			case 2: return 0;
		}
		game->GetGameBoard()->PrepareMap(game->GetFighterAirPlane());
		system("cls");
		game->GameLoop();
		game->~GameCreator();
		rlutil::setBackgroundColor(0);
	}
}