#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain is born !!" << std::endl;
	return;
}
Brain::~Brain()
{
	std::cout << "Encephalograme flat...." << std::endl;
	return;
}

std::string Brain::identify(void) const
{
	std::ostringstream os;
	std::string addr;

	os << std::hex << this;
	return (os.str());
}