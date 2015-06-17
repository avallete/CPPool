#ifndef ASSAULT_TERMINATOR_HPP
#define ASSAULT_TERMINATOR_HPP
#include "ISpaceMarine.hpp"
#include <iostream>
#include <string>

class AssaultTerminator: public ISpaceMarine
{
	public:
		AssaultTerminator(void);
		AssaultTerminator(AssaultTerminator const & src);
		~AssaultTerminator(void);
		ISpaceMarine* clone(void) const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;

		AssaultTerminator& operator=(AssaultTerminator const & rhs);	
};
#endif