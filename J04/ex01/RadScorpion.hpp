#ifndef RAD_SCORPION_HPP
#define RAD_SCORPION_HPP
#include "RadScorpion.hpp"
#include "Enemy.hpp"

class RadScorpion: public Enemy
{
	public:
		RadScorpion(void);
		RadScorpion(RadScorpion const & src);
		~RadScorpion(void);
		void	takeDamage(int dmg);

		RadScorpion& operator=(RadScorpion const & rhs);
};
#endif