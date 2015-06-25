#include "Operation.hpp"

Operation::Operation(void)
{
	return;
}

Operation::Operation(Operation const & src)
{
	*this = src;
	return;
}

Operation::~Operation(void)
{
	return;
}

Operation& Operation::operator=(Operation const & rhs)
{
	return (*this);
}