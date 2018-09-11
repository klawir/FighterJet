#pragma once
class Player
{
protected:
	int money;
	int life;
public:
	Player();
	~Player();

	int getMoney();
	void AddMoney(int);
	void SetMoney(int);
	int GetLife();
	void IncrementLife();
	void DecrementLife();
};