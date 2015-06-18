#include "Fixed.class.hpp"
#include <iostream>

int const Fixed::_fix = 8;

Fixed::Fixed(void):_raw(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}
Fixed::Fixed(int const nb):_raw(roundf((1 << _fix) * nb))
{
	return;
}
Fixed::Fixed(float const nb):_raw(roundf(((1 << _fix) * nb)))
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
	_raw = rhs.getRawBits();
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
	return (_raw);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	if (_fix > 0)
		_raw = raw;
	return;
}

float	Fixed::toFloat(void) const
{
	return (_raw / (double)(1 << _fix));
}

int		Fixed::toInt(void) const
{
	return (_raw / (1 << _fix));
}