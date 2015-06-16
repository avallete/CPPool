#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void): ClapTrap( 60, 60, 120, 120, 1, 60, 5, 0, "Ninja default")
{
    std::cout << "Ninja default contructor called" << std::endl;
    return;
}

NinjaTrap::NinjaTrap(std::string name): ClapTrap( 60, 60, 120, 120, 1, 60, 5, 0, name)
{
    std::string creation[6] = {"This time it'll be awesome, I promise !", "Recompiling my combat code!",
    "Let's get this party started!", "I'm a sexy dinosaur! Rawr.", "Things are about to get awesome!"};
    std::cout << "Ninja Creation : "  << creation[std::rand() % 5] << std::endl;
    return;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src): ClapTrap(src)
{
    std::cout << "Ninja copy contructor called" << std::endl;
    *this = src;
    return;
}

NinjaTrap::~NinjaTrap(void)
{
    std::cout << "FR4G-TP " << this->getName() << " is die. RIP Bro !" << std::endl;
    return;
}

void            NinjaTrap::ninjaShoebox(ClapTrap & clap)
{
    (void)clap;
    std::cout << "NinjaTrap " << this->getName() << " ask: You are my father ?!" << std::endl;
    return;
}

void            NinjaTrap::ninjaShoebox(FragTrap & frag)
{
    (void)frag;
    std::cout << "NinjaTrap " << this->getName() << " ask: Seriously ? You have \"Frag\" in your name ? How old are you Kevin ?!" << std::endl;
    return;
}

void            NinjaTrap::ninjaShoebox(ScavTrap & scav)
{
    (void)scav;
    std::cout << "NinjaTrap " << this->getName() << " say: Attaque de l'orbe tourbillonnate !!! Fucking french, that doesn't work !  ***RASENGAN***" << std::endl;
    return;
}

void            NinjaTrap::ninjaShoebox(NinjaTrap & ninja)
{
    (void)ninja;
    std::cout << "NinjaTrap " << this->getName() << " and NinjaTrap " << ninja.getName() << " look at each other. Shake their heads and look up to you. You feel the need to go ... NOW !!!" << std::endl;
    return;
}