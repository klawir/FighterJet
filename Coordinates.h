#pragma once
#include "librares.h"

class Coordinates
{
protected:
	int posX, posY;
	bool activate;
public:
	Coordinates();

	virtual void SetPosX(int);
	virtual void SetPosY(int);
	virtual void SetActivate(bool);

	virtual int GetPosX();
	virtual int GetPosY();

	virtual bool GeActivate();
};