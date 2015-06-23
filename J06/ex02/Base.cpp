#include "Base.hpp"

Base::Base(void)
{
	return;
}

Base::Base(Base const & src)
{
	*this = src;
	return;
}

Base::~Base(void)
{
	return;
}

Base& Base::operator=(Base const & rhs)
{
	(void)rhs;
	return (*this);
}