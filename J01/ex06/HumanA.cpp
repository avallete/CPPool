#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon arm): _name(name), _weapon((Weapon&)arm)
{
    return;
}

HumanA::~HumanA()
{
    return;
}

void    HumanA::attack(void) const
{
    std::cout << this->_name << " attacks with his" << this->_weapon.getType() << std::endl;
    return;
}