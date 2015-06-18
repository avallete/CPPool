#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void): ClapTrap( 100, 100, 120, 120, 1, 60, 20, 5, "SuperTrap default")
{
	std::cout << "SUPERTRAP DEFAULT CONSTRUCTOR" << std::endl;
	return;
}

SuperTrap::SuperTrap(std::string name): ClapTrap( 100, 100, 120, 120, 1, 60, 20, 5, name)
{
	std::cout << "SUPERTRAP STRING CONSTRUCTOR" << std::endl;
	return;
}

SuperTrap::SuperTrap(SuperTrap const & src): ClapTrap( src )
{
	std::cout << "SUPERTRAP COPY CONSTRUCTOR" << std::endl;
	*this = src;
	return;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SUPERTRAP DESTRUCTOR" << std::endl;
	return;
}

SuperTrap& SuperTrap::operator=(SuperTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}