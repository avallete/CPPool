#include "Fixed.class.hpp"

Fixed::Fixed(void): _raw(0), _fix(8)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & src): _fix(8)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed& Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator overload" << std::endl;
	this->_raw = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	if (this->_fix > 0)
		this->_raw = raw;
	return;
}
