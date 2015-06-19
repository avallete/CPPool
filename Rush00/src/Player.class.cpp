#include "Player.class.hpp"

Player::Player(void)
{
	return;
}

Player::Player(Player const & src)
{
	*this = src;
	return;
}

Player::~Player(void)
{
	return;
}

Player& Player::operator=(Player const & rhs)
{
	return (*this);
}