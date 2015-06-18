#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	return;
}

Ice::Ice(Ice const & src): AMateria(src)
{
	return;
}

Ice::~Ice(void)
{
	return;
}


AMateria* Ice::clone(void) const
{
	AMateria* ret = new Ice;
	*ret = *this;
	return (ret);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return;	
}

Ice& Ice::operator=(Ice const & rhs)
{
	AMateria::operator=(rhs);
	return (*this);
}