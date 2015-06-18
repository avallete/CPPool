#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main(void)
{
	FragTrap clap("Clap");
/*	FragTrap clap2(clap);
	FragTrap trap("Trap");
	ScavTrap scav("Scav");
	NinjaTrap naruto("Naruto");
	NinjaTrap sasuke("Sasuke");*/
	SuperTrap Super("Power");

/*	clap.display_infos();
	clap2.display_infos();
	trap.display_infos();
	clap2 = trap;
	clap2.display_infos();
	clap.rangedAttack("Some badass");
	clap.meleeAttack("Some badass");
	std::cout << "Hit pts : " << clap.getHitpts() << std::endl;
	clap.takeDamage(50);
	std::cout << "Hit pts : " << clap.getHitpts() << std::endl;
	clap.takeDamage(50);
	clap.takeDamage(50);
	std::cout << "Hit pts : " << clap.getHitpts() << std::endl;
	clap.beRepaired(50);
	clap.beRepaired(50);
	clap.beRepaired(50);
	std::cout << "Hit pts : " << clap.getHitpts() << std::endl;
	std::cout << "Enegie pts : " << clap.getEnepts() << std::endl;
	clap.vaulthunter_dot_exe("some badass");
	std::cout << "Energie pts : " << clap.getEnepts() << std::endl;
	clap.vaulthunter_dot_exe("some badass");
	clap.vaulthunter_dot_exe("some badass");
	trap.vaulthunter_dot_exe("a little pony");
	trap.vaulthunter_dot_exe("a little pony");
	scav.display_infos();
	scav.challengeNewcomer();
	scav.challengeNewcomer();
	scav.challengeNewcomer();
	FragTrap clp("test");
	ScavTrap scv("test");
	naruto.ninjaShoebox(clap);
	naruto.ninjaShoebox(scav);
	naruto.ninjaShoebox(sasuke);*/
	std::cout << "\n\nTest for SUPERCLAP\n\n" << std::endl;
	Super.display_infos();
	Super.ninjaShoebox(clap);
	Super.vaulthunter_dot_exe(" a cute baby cat.");
	Super.rangedAttack("Somone");
	Super.meleeAttack("Someone close");
}