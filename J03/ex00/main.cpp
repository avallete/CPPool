#include "FragTrap.hpp"

int main(void)
{
	FragTrap clap("Clap");
	FragTrap clap2(clap);
	FragTrap trap("Trap");

	clap.display_infos();
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
	clap.vaulthunter_dot_exe("some badass");
	clap.vaulthunter_dot_exe("some badass");
	clap.vaulthunter_dot_exe("some badass");
	clap.vaulthunter_dot_exe("some badass");
	trap.vaulthunter_dot_exe("a little pony");
	trap.vaulthunter_dot_exe("a little pony");
	trap.vaulthunter_dot_exe("a little pony");
	trap.vaulthunter_dot_exe("a little pony");
	trap.vaulthunter_dot_exe("a little pony");
	trap.vaulthunter_dot_exe("a little pony");
}