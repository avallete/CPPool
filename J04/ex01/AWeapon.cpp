#include "AWeapon.hpp"

AWeapon::AWeapon(void)
{
	return;
}

AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
	return;
}

AWeapon::~AWeapon(void)
{
	std::cout << "AWeapon destructor called" << std::endl;
	return;
}

AWeapon& AWeapon::operator=(AWeapon const & rhs)
{
	this->_name = rhs.getName();
	this->_apcost = rhs.getAPCost();
	this->_damage = rhs.getDamage();
	return (*this);
}


AWeapon::AWeapon(std::string const & name, int apcost, int damage): _name(name), _apcost(apcost), _damage(damage)
{
	return;
}


std::string&	AWeapon::getName(void) const
{
	return ((std::string&)this->_name);
}

int				AWeapon::getAPCost(void) const
{
	return (this->_apcost);
}

int				AWeapon::getDamage(void) const
{
	return (this->_damage);
}