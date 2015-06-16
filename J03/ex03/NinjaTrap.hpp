#ifndef NINJA_TRAP_HPP
#define NINJA_TRAP_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include "ClapTrap.hpp"

class NinjaTrap : public ClapTrap
{
    public:
        NinjaTrap(std::string name);
        NinjaTrap(NinjaTrap const & src);
        ~NinjaTrap(void);

        void            vaulthunter_dot_exe(std::string const & target);
    private:
        NinjaTrap(void);

};
#endif