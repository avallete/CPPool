#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "Brain.hpp"
class Human
{
public:
	Human();
	~Human();
	std::string identify(void) const;
	Brain& getBrain(void) const;
private:
	Brain const _brain;
};
#endif