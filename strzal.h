#include "biblioteki.h"
	class Naboj
	{
		int polozenieX, polozenieY;
		bool aktywny;
	public:
		Naboj()
		{
			polozenieX = polozenieY = 0;
			aktywny = false;
		}
		void SetpolozenieX(int a) { polozenieX = a; }
		void SetpolozenieY(int a) { polozenieY = a; }
		void Setaktywny(bool a) { aktywny = a; }
		int GetpolozenieX() { return polozenieX; }
		int GetpolozenieY() { return polozenieY; }
		bool Getaktywny() { return aktywny; }
		void _SetpolozenieX() { polozenieX--; }
	};
