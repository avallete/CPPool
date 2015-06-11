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

void	ZombieEvent::randomChump(void)
{
	std::string names[4];
	Zombie *Zom;
	int choose;

	names[0] = "Harry";
	names[1] = "Coco";
	names[2] = "Geralt";
	names[3] = "Brian";
	choose = rand() % 3;
	Zom = newZombie(names[choose]);
	Zom->announce();
	delete Zom;
	Zom = NULL;
}