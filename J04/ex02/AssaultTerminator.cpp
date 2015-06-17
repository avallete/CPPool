#include "AssaultTerminator.hpp"


AssaultTerminator::AssaultTerminator(void)
{
	std::cout << "* teleports from space *" << std::endl;
	return;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src)
{
	(void)src;
	return;
}

AssaultTerminator::~AssaultTerminator(void)
{
	std::cout << "I'll be back ..." << std::endl;
	return;
}

AssaultTerminator& AssaultTerminator::operator=(AssaultTerminator const & rhs)
{
	(void)rhs;
	return (*this);
}

ISpaceMarine* AssaultTerminator::clone(void) const
{
	return (new AssaultTerminator);
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
	return;
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
	return;
}

void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
	return;
}