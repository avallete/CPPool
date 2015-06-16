#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP
#include <iostream>
#include <string>
#include <cstdlib>

class ClapTrap
{
	public:
		ClapTrap(unsigned int hitpts, unsigned int maxhit, unsigned int enepts,
					unsigned int maxene, unsigned int level, unsigned int melatk, unsigned int rgsatk,
					unsigned int armor, std::string name);
		ClapTrap(ClapTrap const & src);
		ClapTrap(void);
		~ClapTrap(void);
		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			setEnepts(unsigned int amount);
		ClapTrap& 		operator=(ClapTrap const & rhs);
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
