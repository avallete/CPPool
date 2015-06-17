#ifndef POWER_FIST_HPP
#define POWER_FIST_HPP
#include "AWeapon.hpp"

class PowerFist: public AWeapon
{
	public:
		PowerFist(void);
		PowerFist(PowerFist const & src);
		~PowerFist(void);

		void attack(void) const;
		PowerFist& operator=(PowerFist const & rhs);
	
};
#endif