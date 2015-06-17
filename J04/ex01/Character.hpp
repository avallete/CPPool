#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string>
#include "Enemy.hpp"
#include "AWeapon.hpp"

class Character
{
	public:
		Character(std::string const & name);
		Character(Character const & src);
		~Character(void);
		std::string&	getName(void) const;
		int				getAP(void)	const;
		AWeapon*		getWeapon(void) const;
		void 			recoverAP(void);
		void			equip(AWeapon*);
		void			attack(Enemy*);

		Character& operator=(Character const & rhs);
	private:
		Character(void);
		std::string		_name;
		int				_ap;
		AWeapon*		_weapon;
};
std::ostream& operator<<(std::ostream & o, const Character& rhs);
#endif