#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default contructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name):	_hitpts(100), _maxhit(100), _enepts(50), _maxene(50),
_level(1), _melatk(20), _rgsatk(15), _armor(3), _name(name)
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

ScavTrap& ScavTrap::operator=(ScavTrap const & rhs)
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

void			ScavTrap::rangedAttack(std::string const &target)
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

void			ScavTrap::meleeAttack(std::string const &target)
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

void			ScavTrap::takeDamage(unsigned int amount)
{
	if (amount)
		amount -= this->_armor;
	std::cout << this->_name << " receive " << amount << " damages." << std::endl;
	this->_hitpts >= amount ? this->_hitpts -= amount : (this->_hitpts = 0);
	return;	
}

void			ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << this->_name << " repaire " << amount << " hit points." << std::endl;
	(this->_hitpts + amount) <= this->getMaxhit() ? this->_hitpts += amount : (this->_hitpts = this->getMaxhit());
	return;
}

unsigned int ScavTrap::getHitpts(void) const
{
	return (this->_hitpts);
}

unsigned int ScavTrap::getMaxhit(void) const
{
	return (this->_maxhit);
}

unsigned int ScavTrap::getEnepts(void) const
{
	return (this->_enepts);
}

unsigned int ScavTrap::getMaxene(void) const
{
	return (this->_maxene);
}

unsigned int ScavTrap::getLevel(void) const
{
	return (this->_level);
}

unsigned int ScavTrap::getMelatk(void) const
{
	return (this->_melatk);
}

unsigned int ScavTrap::getRgsatk(void) const
{
	return (this->_rgsatk);
}

unsigned int ScavTrap::getArmor(void) const
{
	return (this->_armor);
}

std::string ScavTrap::getName(void) const
{
	return (this->_name);
}

void		ScavTrap::display_infos(void) const
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