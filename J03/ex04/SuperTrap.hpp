#ifndef SUPER_TRAP_HPP
#define SUPER_TRAP_HPP
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

class SuperTrap: public NinjaTrap, public FragTrap
{
	public:
		SuperTrap(std::string name);
		SuperTrap(SuperTrap const & src);
		~SuperTrap(void);

		SuperTrap& operator=(SuperTrap const & rhs);
	private:
		SuperTrap(void);
};
#endif