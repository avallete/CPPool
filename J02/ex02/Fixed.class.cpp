#include "Fixed.class.hpp"
#include <iostream>

const int Fixed::_fix = 8;

Fixed::Fixed(void):_raw(0)
{
//	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & src)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}
Fixed::Fixed(int const nb):_raw(roundf(((1 << _fix) * nb)))
{
	return;
}
Fixed::Fixed(float const nb):_raw(roundf(((1 << _fix) * nb)))
{
	return;
}

Fixed::~Fixed(void)
{
//	std::cout << "Destructor called" << std::endl;
	return;
}

int		Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return (_raw);
}

void	Fixed::setRawBits(int const raw)
{
//	std::cout << "setRawBits member function called" << std::endl;
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

Fixed&			Fixed::min(Fixed const & f1, Fixed const & f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return ((Fixed&)f1);
	return ((Fixed&)f2);
}

Fixed&			Fixed::min(Fixed & f1, Fixed & f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed&			Fixed::max(Fixed const & f1, Fixed const & f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return ((Fixed&)f1);
	return ((Fixed&)f2);
}

Fixed&			Fixed::max(Fixed & f1, Fixed & f2)
{	
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed&	Fixed::operator=(Fixed const & rhs)
{
//	std::cout << "Assignation operator overload" << std::endl;
	_raw = rhs.getRawBits();
	return (*this);
}

Fixed&					Fixed::operator++()
{
	++_raw;
	return (*this);
}
Fixed					Fixed::operator++(int)
{
	Fixed res;

	res.setRawBits(getRawBits());
	++_raw;
	return (res);
}
Fixed&					Fixed::operator--()
{
	--_raw;
	return (*this);
}
Fixed					Fixed::operator--(int)
{
	Fixed res;

	res.setRawBits(getRawBits());
	--_raw;
	return (res);
}

Fixed					Fixed::operator*(Fixed const & rhs)
{
	if (rhs.getRawBits() == 0)
		return (Fixed(0));
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed					Fixed::operator/(Fixed const & rhs)
{
	if (rhs.getRawBits() == 0)
		return (Fixed(0));
	return(Fixed(toFloat() / rhs.toFloat()));
}
Fixed					Fixed::operator+(Fixed const & rhs)
{
	return(Fixed(toFloat() + rhs.toFloat()));
}
Fixed					Fixed::operator-(Fixed const & rhs)
{
	return(Fixed(toFloat() - rhs.toFloat()));
}

bool					Fixed::operator>(Fixed const & rhs)
{
	return (getRawBits() > rhs.getRawBits() ? true : false);
}

bool					Fixed::operator>=(Fixed const & rhs)
{
	return (getRawBits() >= rhs.getRawBits() ? true : false);
}

bool					Fixed::operator<(Fixed const & rhs)
{
	return (getRawBits() < rhs.getRawBits() ? true : false);
}

bool					Fixed::operator<=(Fixed const & rhs)
{
	return (getRawBits() <= rhs.getRawBits() ? true : false);
}

bool					Fixed::operator==(Fixed const & rhs)
{
	return (getRawBits() == rhs.getRawBits() ? true : false);
}

bool					Fixed::operator!=(Fixed const & rhs)
{
	return (getRawBits() != rhs.getRawBits() ? true : false);
}	

std::ostream&	operator<<(std::ostream& o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
