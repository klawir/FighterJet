#include "gra.h"
#include "menu.h"
#include "strzal.h"
#include <ctime>
#include "rlutil.h"
int main()
{
	
	HWND konsola = GetConsoleWindow();
	RECT rozdzielczoscKonsoli;
	GetWindowRect(konsola, &rozdzielczoscKonsoli);
	MoveWindow(konsola, (GetSystemMetrics(SM_CXSCREEN)/2)-(rozdzielczoscKonsoli.right /2),
		(GetSystemMetrics(SM_CYSCREEN)/2)-(rozdzielczoscKonsoli.bottom /2),
		rozdzielczoscKonsoli.right, 
		rozdzielczoscKonsoli.bottom, TRUE);
	srand(time(0));
	Gra gra;
	Menu menu;
	while (!menu.GetWyjscie())
	{
		system("cls");
		
		menu.Pokaz();
		switch (menu.GetWybor())
		{
			case 1:
			{
				
			}break;
			case 2:
			{
				return 0;
			}
		}
		gra.przygotuj_plansze();
		system("cls");
		gra.petla_gry();
		gra.~Gra();
		rlutil::setBackgroundColor(0);
	}
}