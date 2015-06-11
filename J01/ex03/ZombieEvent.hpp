#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP
#include "Zombie.hpp"
class ZombieEvent
{
public:
	ZombieEvent();
	~ZombieEvent();
	void		setZombieType(Zombie *subject, std::string type);
	Zombie*		newZombie(std::string name);
	void		randomChump(void);
private:
	std::string _randName(void) const;
};
#endif