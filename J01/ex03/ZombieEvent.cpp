#include "ZombieEvent.hpp"
#include <cstdlib>

ZombieEvent::ZombieEvent()
{
	return;
}

ZombieEvent::~ZombieEvent()
{
	return;
}

void	ZombieEvent::setZombieType(Zombie *subject, std::string type)
{
	subject->type = type;
	return;
}

Zombie*	ZombieEvent::newZombie(std::string name)
{
	int genre;

	genre = rand();
	Zombie* ret = new Zombie;
	ret->name = name;
	genre % 2 ? setZombieType(ret, "Male") : setZombieType(ret, "Female");
	return (ret);
}

std::string ZombieEvent::_randName(void) const
{
	std::string names[4];
	int choose;

	names[0] = "Harry";
	names[1] = "Coco";
	names[2] = "Geralt";
	names[3] = "Brian";
	choose = rand() % 3;
	return (names[choose]);
}

void	ZombieEvent::randomChump(void)
{
	Zombie *Zom;
	Zom = newZombie(_randName());
	Zom->announce();
	delete Zom;
	Zom = NULL;
}