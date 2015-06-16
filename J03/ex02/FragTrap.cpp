#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap( 100, 100, 100, 100, 1, 30, 20, 5, "Frag default")
{
	std::cout << "FR4G-TP default contructor called" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name): ClapTrap( 100, 100, 100, 100, 1, 30, 20, 5, name)
{
	std::string creation[6] = {"This time it'll be awesome, I promise !", "Recompiling my combat code!",
	"Let's get this party started!", "I'm a sexy dinosaur! Rawr.", "Things are about to get awesome!"};
	std::cout << creation[std::rand() % 5] << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap(src)
{
	std::cout << "FR4G-TP copy contructor called" << std::endl;
	*this = src;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FR4G-TP " << this->getName() << " is die. RIP Bro !" << std::endl;
	return;
}

void			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string attaks[9] = 	{"Flesh fireworks!", "Meat confetti!", "It's the only way to stop the voices!",
								"Lasers!", "You can call me Gundalf!", "Kill! Reload! Kill! Reload! KILL! RELOAD!",
								"Get away from me!", "Hyperiooooon Punch!", "I am a tornado of death and bullets!"};
	if (this->getEnepts() >= 25)
	{
		std::cout << "FR4G-TP attacks " << target << " and 5cr34m5: " << attaks[std::rand() % 8] << "." << std::endl;
		this->setEnepts(this->getEnepts() - 25);
	}
	else
		std::cout << this->getName() << " don't have enouth energy for that." << std::endl;
	return;
}