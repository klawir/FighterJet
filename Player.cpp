#pragma once
#include "Player.h"

Player::Player()
{
	life = 5;
	money = 0;
}
Player::~Player()
{
	life = 5;
	money = 0;
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
int Player::GetLife()
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
