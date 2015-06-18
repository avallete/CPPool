#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):_hitpts(0), _maxhit(0), _enepts(0), _maxene(0),
					_level(0), _melatk(0), _rgsatk(0), _armor(0), _name("")
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Default ClapTrap destructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(unsigned int hitpts, unsigned int maxhit, unsigned int enepts,
					unsigned int maxene, unsigned int level, unsigned int melatk, unsigned int rgsatk,
					unsigned int armor, std::string name): _hitpts(hitpts), _maxhit(maxhit), _enepts(enepts), _maxene(maxene),
					_level(level), _melatk(melatk), _rgsatk(rgsatk), _armor(armor), _name(name)
{
	std::cout << "String ClapTrap constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
	return;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & rhs)
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

void			ClapTrap::rangedAttack(std::string const &target)
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

void			ClapTrap::meleeAttack(std::string const &target)
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

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (amount)
		amount -= this->_armor;
	std::cout << this->_name << " receive " << amount << " damages." << std::endl;
	this->_hitpts >= amount ? this->_hitpts -= amount : (this->_hitpts = 0);
	return;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->_name << " repaire " << amount << " hit points." << std::endl;
	(this->_hitpts + amount) <= this->getMaxhit() ? this->_hitpts += amount : (this->_hitpts = this->getMaxhit());
	return;
}

void		ClapTrap::setEnepts(unsigned int amount)
{
	if (amount <= this->getMaxene())
		this->_enepts = amount;
}

unsigned int ClapTrap::getHitpts(void) const
{
	return (this->_hitpts);
}

unsigned int ClapTrap::getMaxhit(void) const
{
	return (this->_maxhit);
}

unsigned int ClapTrap::getEnepts(void) const
{
	return (this->_enepts);
}

unsigned int ClapTrap::getMaxene(void) const
{
	return (this->_maxene);
}

unsigned int ClapTrap::getLevel(void) const
{
	return (this->_level);
}

unsigned int ClapTrap::getMelatk(void) const
{
	return (this->_melatk);
}

unsigned int ClapTrap::getRgsatk(void) const
{
	return (this->_rgsatk);
}

unsigned int ClapTrap::getArmor(void) const
{
	return (this->_armor);
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

void		ClapTrap::display_infos(void) const
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