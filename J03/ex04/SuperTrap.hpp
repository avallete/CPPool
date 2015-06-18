#ifndef SUPER_TRAP_HPP
#define SUPER_TRAP_HPP

class SuperTrap
{
	public:
		SuperTrap(void);
		SuperTrap(SuperTrap const & src);
		~SuperTrap(void);

		SuperTrap& operator=(SuperTrap const & rhs);
	
};
#endif