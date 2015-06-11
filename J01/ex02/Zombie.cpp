#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A new Zombie is dead !" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie going to hell" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << "<"+this->name+" ("+this->type;
	std::cout << ") > " << "Braiiiiiiinnnssss..." << std::endl;
}