#pragma once
#include "Player.h"

class FighterAirPlane: public Player
{
	int cockpitY, leftWingY, rightWingY;
	int cocpitStartLocateX;
	int leftWingStartLocateX;
	int wingRightStartLocateX;
public:
	FighterAirPlane();
	~FighterAirPlane();

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
};