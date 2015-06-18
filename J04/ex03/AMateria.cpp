#include "AMateria.hpp"

AMateria::AMateria(void)
{
	return;
}

AMateria::AMateria(std::string const & type): _xp(0), _type(type)
{
	return;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
	return;
}

AMateria::~AMateria(void)
{
	return;
}

std::string const & AMateria::getType(void) const
{
	return ((std::string&)this->_type);
}

unsigned int AMateria::getXP(void) const
{
	return (this->_xp);
}

void	AMateria::use(ICharacter& target)
{
	this->_xp += 10;
	this->use(target);
	return;
}

AMateria& AMateria::operator=(AMateria const & rhs)
{
	this->_type = rhs.getType();
	this->_xp = rhs.getXP();
	return (*this);
}