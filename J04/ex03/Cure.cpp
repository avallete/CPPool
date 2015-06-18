#include "Cure.hpp"

Cure::Cure(void): AMateria("ice")
{
	return;
}

Cure::Cure(Cure const & src): AMateria(src)
{
	return;
}

Cure::~Cure(void)
{
	return;
}


AMateria* Cure::clone(void) const
{
	AMateria* ret = new Cure;
	*ret = *this;
	return (ret);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return;	
}

Cure& Cure::operator=(Cure const & rhs)
{
	AMateria::operator=(rhs);
	return (*this);
}