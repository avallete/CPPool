#include "BrainRun.hpp"

BrainRun::BrainRun(void)
{
	return;
}

BrainRun::BrainRun(BrainRun const & src)
{
	*this = src;
	return;
}

BrainRun::~BrainRun(void)
{
	return;
}

BrainRun& BrainRun::operator=(BrainRun const & rhs)
{
	return (*this);
}