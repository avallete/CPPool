#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP
#include "ZombieEvent.hpp"
class ZombieHorde
{
public:
	ZombieHorde(int N);
	~ZombieHorde();
	void	announce() const;
private:
	Zombie* _horde;
	std::string _ChooseName(void) const;
	int		_size;
};
#endif