#include "Human.hpp"

int main(void)
{
	Human Kenny("Kenny");
	Human Stan("Stan");
	Human Cartman("Cartman");

	Cartman.action("intimidatingShout", Kenny.get_name());
	Cartman.action("intimidatingShout", Stan.get_name());
	Stan.ation("meleeAttack", Cartman.get_name());
	Kenny.action("rangedAttack", Cartman.get_name());
}
