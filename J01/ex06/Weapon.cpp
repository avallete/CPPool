#include "Weapon.hpp"

    Weapon::Weapon(std::string type): _type(type)
    {
        return;
    }
    Weapon::~Weapon()
    {
        return;
    }
    std::string&    Weapon::getType() const
    {
        return ((std::string&)this->_type);
    }
    void            Weapon::setType(std::string str)
    {
        this->_type = str;
        return;
    }