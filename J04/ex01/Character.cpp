#include "Character.hpp"

Character::Character(void)
{
	return;
}

Character::Character(Character const & src)
{
	*this = src;
	return;
}

Character::~Character(void)
{
	return;
}

Character::Character(std::string const & name): _name(name), _ap(40), _weapon(NULL)
{
	return;
}

std::string&	Character::getName(void) const
{
	return ((std::string&)this->_name);
}

int				Character::getAP(void) const
{
	return (this->_ap);
}

AWeapon*		Character::getWeapon(void) const
{
	return (this->_weapon);
}

void			Character::equip(AWeapon* arm)
{
	this->_weapon = arm;
}

void			Character::attack(Enemy* target)
{
	if (this->_weapon != NULL)
	{
		if (this->_ap > this->_weapon->getAPCost())
		{
			std::cout << this->_name << " attacks " << target->getType() << " with a " << this->_weapon->getName() << std::endl;
			this->_weapon->attack();
			this->_ap -= this->_weapon->getAPCost();
			target->takeDamage(this->_weapon->getDamage());
			if (target->getHP() <= 0)
				delete target;
		}
	}
}

void		Character::recoverAP(void)
{
	if (this->_ap <= 30)
		this->_ap += 10;
	return;
}

Character& Character::operator=(Character const & rhs)
{
	this->_name = rhs.getName();
	this->_ap = rhs.getAP();
	this->_weapon = rhs.getWeapon();
	return (*this);
}

std::ostream& operator<<(std::ostream & o, const Character& rhs)
{
	o << rhs.getName() << " has " << rhs.getAP() << " AP ";
	rhs.getWeapon() != NULL ? o << "and wields as " << rhs.getWeapon()->getName() : o << "and is unarmed";
	o << std::endl;
	return (o);
}