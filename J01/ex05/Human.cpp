#include "Human.hpp"

Human::Human()
{
	std::cout << "Human is born" << std::endl;
	return;
}
Human::~Human()
{
	std::cout << "Human is dead" << std::endl;
	return;
}
std::string	Human::identify(void) const
{
	return(this->_brain.identify());
}
Brain&	Human::getBrain(void) const
{
	return ((Brain&)this->_brain);
}