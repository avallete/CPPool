#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);

		void			vaulthunter_dot_exe(std::string const & target);
		FragTrap& 		operator=(FragTrap const & rhs);
};
#endif