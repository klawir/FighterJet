#include "biblioteki.h"
class Gra
{
	static const int rozmiar1 = 19;
	static const int rozmiar2 = 25;
	int strzal, strzal_prosty, wrog_zabity;
	int czas_opadania, predkosc_opadania_wroga, a, b;
	
	char map[rozmiar1][rozmiar2];
	int lewaSciana;
	bool _gra;
	int licznik;
	int bonus;
	int ktoryPocisk, ktoryMob;
	int index;
	bool poczatek, poczatekMob;
	int wspolrzednaKolizyjnaA, wspolrzednaKolizyjnaB;
public:
	Gra();
	~Gra();
	void przygotuj_plansze();
	void plansza();
	void klawiatura();
	int wylosuj_wroga();
	void Wrog();
	void Pocisk();
	void petla_gry();
	void Ekran();
	bool Sprawdz();
};