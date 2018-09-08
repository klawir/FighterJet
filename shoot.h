#pragma once
#include "librares.h"
	class Naboj
	{
		int posX, posY;
		bool activate;
	public:
		Naboj()
		{
			posX = 0;
			posY = 0;
			activate = false;
		}
		void SetPositionX(int a) { posX = a; }
		void SetPositionY(int a) { posY = a; }
		void SetActivate(bool a) { activate = a; }
		int GetPositionX() { return posX; }
		int GetPositionY() { return posY; }
		bool GeActivate() { return activate; }
		void SetPositiionX() { posX--; }
	};
