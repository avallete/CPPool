#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FR4G-TP default contructor called" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name):	_hitpts(100), _maxhit(100), _enepts(100), _maxene(100),
_level(1), _melatk(30), _rgsatk(20), _armor(5), _name(name)
{
	std::string creation[6] = {"This time it'll be awesome, I promise !", "Recompiling my combat code!",
	"Let's get this party started!", "I'm a sexy dinosaur! Rawr.", "Things are about to get awesome!"};
	std::cout << creation[std::rand() % 5] << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const & src)
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

FragTrap& FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "Assignation operator overload" << std::endl;
	this->_hitpts = rhs.getHitpts();
	this->_maxhit = rhs.getMaxhit();
	this->_enepts = rhs.getEnepts();
	this->_maxene = rhs.getMaxene();
	this->_level = rhs.getLevel();
	this->_melatk = rhs.getMelatk();
	this->_rgsatk = rhs.getRgsatk();
	this->_armor = rhs.getArmor();
	this->_name = rhs.getName();
	return (*this);
}

void			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string attaks[9] = 	{"Flesh fireworks!", "Meat confetti!", "It's the only way to stop the voices!", 
								"Lasers!", "You can call me Gundalf!", "Kill! Reload! Kill! Reload! KILL! RELOAD!",
								"Get away from me!", "Hyperiooooon Punch!", "I am a tornado of death and bullets!"};
	if (this->getEnepts() >= 25)
	{
		std::cout << "FR4G-TP attacks " << target << " and 5cr34m5: " << attaks[std::rand() % 8] << "." << std::endl;								
		this->_enepts -= 25;
	}	
	else
		std::cout << this->_name << " don't have enouth energy for that." << std::endl;		
	return;	
}

void			FragTrap::rangedAttack(std::string const &target)
{
	if (this->getEnepts() >= 25)
	{
		std::cout << this->_name << " attacks " << target << " at range, causing " << getRgsatk() << " damages" << std::endl;
		this->_enepts -= 25;
	}	
	else
		std::cout << this->_name << " don't have enouth energy for that." << std::endl;
	return;
}

void			FragTrap::meleeAttack(std::string const &target)
{
	if (this->getEnepts() >= 25)
	{
		std::cout << this->_name << " attacks " << target << " at melee, causing " << getMelatk() << " damages" << std::endl;
		this->_enepts -= 25;
	}	
	else
		std::cout << this->_name << " don't have enouth energy for that." << std::endl;
	return;
}

void			FragTrap::takeDamage(unsigned int amount)
{
	if (amount)
		amount -= this->_armor;
	std::cout << this->_name << " receive " << amount << " damages." << std::endl;
	this->_hitpts >= amount ? this->_hitpts -= amount : (this->_hitpts = 0);
	return;	
}

void			FragTrap::beRepaired(unsigned int amount)
{
	std::cout << this->_name << " repaire " << amount << " hit points." << std::endl;
	(this->_hitpts + amount) <= this->getMaxhit() ? this->_hitpts += amount : (this->_hitpts = this->getMaxhit());
	return;
}

unsigned int FragTrap::getHitpts(void) const
{
	return (this->_hitpts);
}

unsigned int FragTrap::getMaxhit(void) const
{
	return (this->_maxhit);
}

unsigned int FragTrap::getEnepts(void) const
{
	return (this->_enepts);
}

unsigned int FragTrap::getMaxene(void) const
{
	return (this->_maxene);
}

unsigned int FragTrap::getLevel(void) const
{
	return (this->_level);
}

unsigned int FragTrap::getMelatk(void) const
{
	return (this->_melatk);
}

unsigned int FragTrap::getRgsatk(void) const
{
	return (this->_rgsatk);
}

unsigned int FragTrap::getArmor(void) const
{
	return (this->_armor);
}

std::string FragTrap::getName(void) const
{
	return (this->_name);
}

void		FragTrap::display_infos(void) const
{
	std::cout << "-------Infos--------" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Hitpts: " << this->getHitpts() << std::endl;
	std::cout << "Maxhit: " << this->getMaxhit() << std::endl;
	std::cout << "Enepts: " << this->getEnepts() << std::endl;
	std::cout << "Maxene: " << this->getMaxene() << std::endl;
	std::cout << "Level: " << this->getLevel() << std::endl;
	std::cout << "Melatk: " << this->getMelatk() << std::endl;
	std::cout << "Rgsatk: " << this->getRgsatk() << std::endl;
	std::cout << "Armor: " << this->getArmor() << std::endl;
	std::cout << "--------------------" << std::endl;
}