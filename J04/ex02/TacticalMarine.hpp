#ifndef TACTICAL_MARINE_HPP
#define TACTICAL_MARINE_HPP
#include "ISpaceMarine.hpp"
#include <iostream>
#include <string>

class TacticalMarine: public ISpaceMarine
{
	public:
		TacticalMarine(void);
		TacticalMarine(TacticalMarine const & src);
		~TacticalMarine(void);
		ISpaceMarine* clone(void) const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;

		TacticalMarine& operator=(TacticalMarine const & rhs);	
};
#endif