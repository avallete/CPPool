#ifndef SUPER_MUTANT_HPP
#define SUPER_MUTANT_HPP
#include "SuperMutant.hpp"
#include "Enemy.hpp"

class SuperMutant: public Enemy
{
	public:
		SuperMutant(void);
		SuperMutant(SuperMutant const & src);
		~SuperMutant(void);
		void	takeDamage(int dmg);

		SuperMutant& operator=(SuperMutant const & rhs);
	
};
#endif