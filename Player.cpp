#pragma once
#include "Player.h"


Player::Player()
{
	life = 5;
	money = 0;
	StartLocateAirPlaneInit();

}
Player::~Player()
{
	life = 5;
	money = 0;
}
int Player::GetCockpitCoordinateY()
{
	return cockpitY;
}
int Player::GetCoordinateLeftWingY()
{
	return leftWingY;
}
int Player::GetCoordinateWingRightY()
{
	return rightWingY;
}
void Player::SetCockpitCoordinateY(int value)
{
	cockpitY = value;
}
void Player::SetCoordinateLeftWingY(int value)
{
	leftWingY = value;
}
void Player::SetCoordinateWingRightY(int value)
{
	rightWingY = value;
}

int Player::GetCocpitStartLocateX()
{
	return cocpitStartLocateX;
}
int Player::GetLeftWingStartLocateX()
{
	return leftWingStartLocateX;
}
int Player::GetWingRightStartLocateX()
{
	return wingRightStartLocateX;
}

void Player::SetCocpitStartLocateX(int value)
{
	value = cocpitStartLocateX;
}
void Player::SetLeftWingStartLocateX(int value)
{
	value = leftWingStartLocateX;
}
void Player::SetWingRightStartLocateX(int value)
{
	value = wingRightStartLocateX;
}

void Player::IncrementCoordinateAirPlaneY()
{
	cockpitY++;
	leftWingY++;
	rightWingY++;
}
void Player::DecrementCoordinateAirPlaneY()
{
	cockpitY--;
	leftWingY--;
	rightWingY--;
}
void Player::StartLocateAirPlaneInit()
{
	cockpitY = 15;
	leftWingY = 14;
	rightWingY = 16;
	cocpitStartLocateX = 16;
	leftWingStartLocateX = 17;
	wingRightStartLocateX = 17;
}
int Player::getMoney()
{
	return money;
}
void Player::AddMoney(int value)
{
	money += value;
}
void Player::SetMoney(int value)
{
	money = value;
}
int Player::getLife()
{
	return life;
}
void Player::IncrementLife()
{
	life++;
}
void Player::DecrementLife()
{
	life--;
}
bool Player::Gameover()
{
	return life < 1;
}