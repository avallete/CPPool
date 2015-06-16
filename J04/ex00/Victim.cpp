#include "Victim.hpp"


Victim::Victim(std::string name): _name(name)
{
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
	return;
}

Victim::Victim(void)
{
	return;
}

Victim::Victim(Victim const & src)
{
	*this = src;
	return;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->getName() << " just died for no apparent reason !" << std::endl;
	return;
}

Victim& Victim::operator=(Victim const & rhs)
{
	this->_name = rhs.getName();
	return (*this);
}

std::string const &	Victim::getName(void) const
{
	return (this->_name);
}

std::ostream& operator<<(std::ostream& o, Victim& rhs)
{
	o << "I'm " << rhs.getName() << " and i like otters !" << std::endl;
	return(o);	
}

void	Victim::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;
	return;
}
