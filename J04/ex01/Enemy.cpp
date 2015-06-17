#include "Enemy.hpp"

Enemy::Enemy(void)
{
	return;
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
	return;
}

Enemy::~Enemy(void)
{
	return;
}


Enemy::Enemy(int hp, std::string const & type): _hp(hp), _type(type)
{
	return;
}

std::string&	Enemy::getType(void) const
{
	return ((std::string&)this->_type);
}

int				Enemy::getHP(void) const
{
	return (this->_hp);
}

void			Enemy::takeDamage(int dmg)
{
	this->_hp -= dmg;
	return;
}

Enemy& Enemy::operator=(Enemy const & rhs)
{
	this->_hp = rhs.getHP();
	this->_type = rhs.getType();
	return (*this);
}