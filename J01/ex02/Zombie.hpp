#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie
{
public:
	std::string name;
	std::string type;
	
	Zombie();
	~Zombie();
	void	announce(void) const;
};
#endif