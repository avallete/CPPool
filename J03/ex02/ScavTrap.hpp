#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		void			challengeNewcomer(void) const;
	private:
		ScavTrap(void);
};
#endif