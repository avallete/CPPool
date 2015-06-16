#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title): _name(name), _title(title)
{
	std::cout << name << ", " << title << ", is born" << std::endl;
	return;
}

Sorcerer::Sorcerer(void)
{
	return;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
	return;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->getName() << ", " << this->getTitle() << ", is dead. Consequences will never be the same !" << std::endl;
	return;
}

Sorcerer& Sorcerer::operator=(Sorcerer const & rhs)
{
	this->_name = rhs.getName();
	this->_title = rhs.getTitle();
	return (*this);
}

std::string const & Sorcerer::getName(void) const
{
	return (this->_name);
}
std::string const & Sorcerer::getTitle(void) const
{
	return (this->_title);
}

std::ostream& operator<<(std::ostream& o, Sorcerer & rhs)
{
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
	return (o);
}

void		Sorcerer::polymorph(Victim const & vict) const
{
	vict.getPolymorphed();
	return;
}