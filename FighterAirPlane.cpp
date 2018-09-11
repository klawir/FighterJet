#include "FighterAirPlane.h"


FighterAirPlane::FighterAirPlane():Player()
{
	StartLocateAirPlaneInit();
}

FighterAirPlane::~FighterAirPlane()
{
	StartLocateAirPlaneInit();
}
int FighterAirPlane::GetCockpitCoordinateY()
{
	return cockpitY;
}
int FighterAirPlane::GetCoordinateLeftWingY()
{
	return leftWingY;
}
int FighterAirPlane::GetCoordinateWingRightY()
{
	return rightWingY;
}
void FighterAirPlane::SetCockpitCoordinateY(int value)
{
	cockpitY = value;
}
void FighterAirPlane::SetCoordinateLeftWingY(int value)
{
	leftWingY = value;
}
void FighterAirPlane::SetCoordinateWingRightY(int value)
{
	rightWingY = value;
}

int FighterAirPlane::GetCocpitStartLocateX()
{
	return cocpitStartLocateX;
}
int FighterAirPlane::GetLeftWingStartLocateX()
{
	return leftWingStartLocateX;
}
int FighterAirPlane::GetWingRightStartLocateX()
{
	return wingRightStartLocateX;
}

void FighterAirPlane::SetCocpitStartLocateX(int value)
{
	value = cocpitStartLocateX;
}
void FighterAirPlane::SetLeftWingStartLocateX(int value)
{
	value = leftWingStartLocateX;
}
void FighterAirPlane::SetWingRightStartLocateX(int value)
{
	value = wingRightStartLocateX;
}

void FighterAirPlane::IncrementCoordinateAirPlaneY()
{
	cockpitY++;
	leftWingY++;
	rightWingY++;
}
void FighterAirPlane::DecrementCoordinateAirPlaneY()
{
	cockpitY--;
	leftWingY--;
	rightWingY--;
}
void FighterAirPlane::StartLocateAirPlaneInit()
{
	cockpitY = 15;
	leftWingY = 14;
	rightWingY = 16;
	cocpitStartLocateX = 16;
	leftWingStartLocateX = 17;
	wingRightStartLocateX = 17;
}