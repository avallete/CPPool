#include "ZombieHorde.hpp"

std::string ZombieHorde::_ChooseName(void) const
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

ZombieHorde::ZombieHorde(int N)
{
	this->_horde = new Zombie[N];
	this->_size = N;
	for (int i = 0; i < N; i++)
	{
		this->_horde[i].name = _ChooseName();
		i % 2 ? this->_horde[i].type = "Male" : this->_horde[i].type = "Female";
	}
}

ZombieHorde::~ZombieHorde()
{
	delete [] this->_horde;
	this->_horde = NULL;
}

void ZombieHorde::announce(void) const
{
	int i;

	i = 0;
	while (i < this->_size)
		this->_horde[i++].announce();
}
