#pragma once
#include "librares.h"
#include "Player.h"
#include "GameBoard.h"
#include "Missile.h"

class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	void AirPlaneControll(Player *player, GameBoard *gameBoard, Missile *missile);
};

extern int indexRestrictive;;