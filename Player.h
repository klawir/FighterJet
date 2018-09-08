#pragma once
class Player
{
	int kasa, zycie;
	int wspolrzednaGracza1, wspolrzednaGracza2, wspolrzednaGracza3;
public:
	Player();
	~Player();

	int GetCoordinateAirPlaneUp();
	int GetCoordinateAirPlaneLeft();
	int GetCoordinateAirPlaneRight();

	void SetCoordinateAirPlaneUp(int);
	void SetCoordinateAirPlaneLeft(int);
	void SetCoordinateAirPlaneRight(int);

	void IncrementCoordinateAirPlane();
	void DecrementCoordinateAirPlane();

	int getMoney();
	void AddMoney(int);
	void SetMoney(int);
	int getLife();
	void IncrementLife();
	void DecrementLife();

	bool Gameover();
};