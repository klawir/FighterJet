#include "Player.h"


Player::Player()
{
	zycie = 5;
	kasa = 0;
}
Player::~Player()
{
	zycie = 5;
	kasa = 0;
}
int Player::GetCoordinateAirPlaneUp()
{
	return wspolrzednaGracza1;
}
int Player::GetCoordinateAirPlaneLeft()
{
	return wspolrzednaGracza2;
}
int Player::GetCoordinateAirPlaneRight()
{
	return wspolrzednaGracza3;
}
void Player::SetCoordinateAirPlaneUp(int value)
{
	wspolrzednaGracza1 = value;
}
void Player::SetCoordinateAirPlaneLeft(int value)
{
	wspolrzednaGracza2 = value;
}
void Player::SetCoordinateAirPlaneRight(int value)
{
	wspolrzednaGracza3 = value;
}
void Player::IncrementCoordinateAirPlane()
{
	wspolrzednaGracza1++;
	wspolrzednaGracza2++;
	wspolrzednaGracza3++;
}
void Player::DecrementCoordinateAirPlane()
{
	wspolrzednaGracza1--;
	wspolrzednaGracza2--;
	wspolrzednaGracza3--;
}

int Player::getMoney()
{
	return kasa;
}
void Player::AddMoney(int value)
{
	kasa += value;
}
void Player::SetMoney(int value)
{
	kasa = value;
}
int Player::getLife()
{
	return zycie;
}
void Player::IncrementLife()
{
	zycie++;
}
void Player::DecrementLife()
{
	zycie--;
}
bool Player::Gameover()
{
	return zycie < 1;
}