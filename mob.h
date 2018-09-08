#pragma once
#include "librares.h"
class Mob
{
	int polozenieX, polozenieY;
	bool aktywny;
	bool wrogIstnieje;
	bool zestrzelony;
public:
	Mob()
	{
		polozenieX = polozenieY = 0;
		aktywny = true;
		zestrzelony = false;
	}
	void SetpolozenieX(int a) { polozenieX = a; }
	void SetpolozenieY(int a) { polozenieY = a; }
	void Setaktywny(bool a) { aktywny = a; }
	int GetpolozenieX() { return polozenieX; }
	int GetpolozenieY() { return polozenieY; }
	bool Getaktywny() { return aktywny; }
	bool GetwrogIstnieje() {return wrogIstnieje;}
	void SetwrogIstnieje(bool a) { wrogIstnieje = a; }
	void _SetpolozenieX() { polozenieX++; }
	bool Getzestrzelony() { return zestrzelony; }
	void Setzestrzelony(bool a) { zestrzelony=a; }
};
