#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap( 100, 100, 50, 50, 1, 20, 15, 3, "Scav default")
{
	std::cout << "ScavTrap default contructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name): ClapTrap( 100, 100, 50, 50, 1, 20, 15, 3, name)
{
	std::cout << "ScavTrap " << name << " has been created." << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "ScavTrap copy contructor called" << std::endl;
	*this = src;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->getName() << " is die. RIP Bro !" << std::endl;
	return;
}

void			ScavTrap::challengeNewcomer(void) const
{
	std::string challenge[9] = 	{"Kill a Badass", "Freeze an enemy", "Take a chill pill", 
								"Kill multiple enemies", "Find rare loot", "Level up",
								"Repulse an enemy", "Ride a sauvage unicorn", "Use the force to get a lolipop"};
	std::string result[9] = 	{"I can't feel my fingers! Gah! I don't have any fingers!" , "Why do I even feel pain?!", 
								"I LIVE!", "Wow, that actually worked?", "I did something right for once!",
								"I feel like an idiot now.", "Do I smell funny?", "Why do I feel radioactive!?", "That is so hot!"};
		std::cout << "ScavTrap try to " << challenge[std::rand() % 8] << ". And after that he said: " << result[std::rand() % 8] << '.' << std::endl;								
	return;	
}