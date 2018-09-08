#pragma once
class Player
{
	int money, life;
	int cockpitY, leftWingY, rightWingY;
	int cocpitStartLocateX;
	int leftWingStartLocateX;
	int wingRightStartLocateX;
public:
	Player();
	~Player();

	int GetCockpitCoordinateY();
	int GetCoordinateLeftWingY();
	int GetCoordinateWingRightY();

	void SetCockpitCoordinateY(int);
	void SetCoordinateLeftWingY(int);
	void SetCoordinateWingRightY(int);

	int GetCocpitStartLocateX();
	int GetLeftWingStartLocateX();
	int GetWingRightStartLocateX();

	void SetCocpitStartLocateX(int);
	void SetLeftWingStartLocateX(int);
	void SetWingRightStartLocateX(int);

	void IncrementCoordinateAirPlaneY();
	void DecrementCoordinateAirPlaneY();

	void StartLocateAirPlaneInit();

	int getMoney();
	void AddMoney(int);
	void SetMoney(int);
	int getLife();
	void IncrementLife();
	void DecrementLife();

	bool Gameover();
};