#include "Fixed.class.hpp"
#include <iostream>

Fixed::Fixed(void): _fix(8), _raw(0)
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
Fixed::Fixed(int const nb): _fix(8), _raw(roundf((pow(2, _fix) * nb)))
{
	return;
}
Fixed::Fixed(float const nb): _fix(8), _raw(roundf(((pow(2, _fix) * nb))))
{
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed&	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator overload" << std::endl;
	this->_raw = rhs.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	if (this->_fix > 0)
		this->_raw = raw;
	return;
}

float	Fixed::toFloat(void) const
{
	return (1 / pow(2, this->_fix) * this->_raw);
}

int		Fixed::toInt(void) const
{
	return (1 / pow(2, this->_fix) * this->_raw);
}