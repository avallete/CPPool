#ifndef NINJA_TRAP_HPP
#define NINJA_TRAP_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap
{
    public:
        NinjaTrap(void);
        NinjaTrap(std::string name);
        NinjaTrap(NinjaTrap const & src);
        ~NinjaTrap(void);
        void            ninjaShoebox(ClapTrap & clap);
        void            ninjaShoebox(FragTrap & frag);
        void            ninjaShoebox(ScavTrap & scav);
        void            ninjaShoebox(NinjaTrap & scav);

        NinjaTrap&       operator=(NinjaTrap const & rhs);
};
#endif