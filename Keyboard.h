#pragma once
#include "librares.h"
#include "FighterAirPlane.h"
#include "Map.h"
#include "Missile.h"

class Keyboard
{
public:
	void AirPlaneControll(FighterAirPlane*, Map *, Missile *);
};

extern int indexRestrictive;;