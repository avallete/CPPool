#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
    this->_weapon = NULL;
    return;
}

HumanB::~HumanB()
{
    return;
}

void    HumanB::attack(void) const
{
    std::cout << this->_name << " attacks with his" << this->_weapon->getType() << std::endl;
    return;
}

void    HumanB::setWeapon(Weapon arm)
{
    this->_weapon = &arm;
    return;
}
