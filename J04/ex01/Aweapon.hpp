#ifndef AWEAPON_HPP
#define AWEAPON_HPP
#include <iostream>
#include <string>

class AWeapon
{
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		virtual	~AWeapon(void);
		AWeapon(AWeapon const & src);
		std::string&	getName(void) const;
		int				getAPCost(void) const;
		int				getDamage(void) const;

		virtual			void attack(void) const = 0;
		AWeapon&		operator=(AWeapon const & rhs);

	private:
		AWeapon(void);
		std::string _name;
		int			_apcost;
		int			_damage;
	
};
#endif