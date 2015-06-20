#ifndef MISSILES_HPP
#define MISSILES_HPP
#include "AObject.hpp"

class Missiles: public AObject
{
	public:
		Missiles(Missiles const & src);
		~Missiles(void);

		Missiles& operator=(Missiles const & rhs);

	protected:
		Missiles(void);
};
#endif