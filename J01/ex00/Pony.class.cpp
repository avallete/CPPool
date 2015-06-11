#include "Pony.class.hpp"

Pony::Pony()
{
	std::cout << "A new pony is born" << std::endl;
}
Pony::~Pony()
{
	std::cout << "A pony is dead" << std::endl;
}
void Pony::speak(void) const
{
	std::cout << "Hi ! My name is " << this->_infos[0];
	std::cout << " My color is " << this->_infos[1];
	std::cout << " I'm on the " << this->_infos[2] << ". Glad to meet you !" << std::endl;
}

void Pony::define_it(char const *color, char const *name, char const *place)
{
	this->_infos[0] = name;
	this->_infos[1] = color;
	this->_infos[2] = place;
}
