#pragma once
#include "librares.h"
#include "FighterAirPlane.h"
#include "GameBoard.h"
#include "Missile.h"

class Keyboard
{
public:
	void AirPlaneControll(FighterAirPlane*, GameBoard *, Missile *);
};

extern int indexRestrictive;;