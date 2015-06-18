#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include <iostream>
#include <string>

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(Ice const & src);
		~Ice(void);
		AMateria* clone() const;
		void use(ICharacter& target);

		Ice& operator=(Ice const & rhs);
};
#endif