#include "Missile.hpp"

Missile::Missile(void): AObject()
{
	return;
}

Missile::Missile(Missile const & src)
{
	*this = src;
	return;
}

Missile::~Missile(void)
{
	return;
}

Missile& Missile::operator=(Missile const & rhs)
{
	return (*this);
}