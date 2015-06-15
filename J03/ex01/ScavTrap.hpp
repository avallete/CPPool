#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
#include <iostream>
#include <string>

class ScavTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		ScavTrap& operator=(ScavTrap const & rhs);
		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			challengeNewcomer(void) const;
		unsigned int 	getHitpts(void) const;
		unsigned int 	getMaxhit(void) const;
		unsigned int 	getEnepts(void) const;
		unsigned int 	getMaxene(void) const;
		unsigned int 	getLevel(void) const;
		unsigned int 	getMelatk(void) const;
		unsigned int 	getRgsatk(void) const;
		unsigned int	getArmor(void) const;
		std::string		getName(void) const;
		void			display_infos(void) const;
	private:
		ScavTrap(void);
		unsigned int _hitpts;
		unsigned int _maxhit;
		unsigned int _enepts;
		unsigned int _maxene;
		unsigned int _level;
		unsigned int _melatk;
		unsigned int _rgsatk;
		unsigned int _armor;
		std::string _name;
};
#endif