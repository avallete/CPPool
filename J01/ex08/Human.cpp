#include "Human.hpp"

typedef void(Human::*PTR)(std::string const &);

void Human::meleeAttack(std::string const & target)
{
	std::cout << this->get_name() << " melee attack to " << target << std::endl;
}

void Human::rangedAttack(std::string const & target)
{
	std::cout << this->get_name() << " ranged attack to " << target << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
	std::cout << this->get_name() << " intimidating shout to " << target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
	PTR array[4] = {&Human::intimidatingShout, &Human::rangedAttack, &Human::meleeAttack, NULL};
	
}

std::string Human::get_name() const
{
	return (this->_name);
}

Human::Human(std::string name):_name(name)
{
	return;
}

Human::~Human()
{
	return;
}