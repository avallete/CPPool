#ifndef WEAPON_HPP
#define WEAPON_HPP
#include "AObject.hpp"
#include "Player.hpp"

class Weapon
{
	public:
		Weapon(AObject& src);
		Weapon(Weapon const & src);
		~Weapon(void);
		int			getDamage(void);

		Weapon& operator=(Weapon const & rhs);
	protected:
		int			m_damage;

	private:
		Weapon(void);
		Weapon* m_launched;		
};
#endif