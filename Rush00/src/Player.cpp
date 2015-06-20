#include "Player.hpp"
#include <iostream>
Player::Player(void): AObject()
{
	return;
}

Player::Player(Window& win): AObject((win.getX() / 2), (win.getY() - 5), 0, 0, 1, 3, "/Y\\")
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

void Player::inputDirection(int ch)
{
	if (ch == 259)
		m_diry = -1;
	else if (ch == 258)
		m_diry = 1;
	else if (ch == 260)
		m_dirx = -1;
	else if (ch == 261)
		m_dirx = 1;
}

void Player::move(Window& win)
{
	m_posy += (m_diry * m_speed);
	m_posx += (m_dirx * m_speed);
	if (m_posy < 0)
		m_posy = 1;
	if (m_posy >= win.getY())
		m_posy = win.getY() - 1;
	if (m_posx < 0)
		m_posx = 1;
	if (m_posx >= win.getX())
		m_posx = win.getX() - 1;
	this->setDir(0, 0);
}

Player& Player::operator=(Player const & rhs)
{
	AObject::operator=(rhs);
	return (*this);
}