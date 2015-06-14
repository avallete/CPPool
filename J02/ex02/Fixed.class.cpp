#include "Fixed.class.hpp"
#include <iostream>

Fixed::Fixed(void): _fix(8), _raw(0)
{
//	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & src): _fix(8)
{
//	std::cout << "Copy constructor called" << std::endl;
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
//	std::cout << "Destructor called" << std::endl;
	return;
}

int		Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
//	std::cout << "setRawBits member function called" << std::endl;
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
	this->_raw = rhs.getRawBits();
	return (*this);
}

Fixed&					Fixed::operator++()
{
	++this->_raw;
	return (*this);
}
Fixed					Fixed::operator++(int)
{
	Fixed res;

	res.setRawBits(this->getRawBits());
	++this->_raw;
	return (res);
}
Fixed&					Fixed::operator--()
{
	--this->_raw;
	return (*this);
}
Fixed					Fixed::operator--(int)
{
	Fixed res;

	res.setRawBits(this->getRawBits());
	--this->_raw;
	return (res);
}

Fixed					Fixed::operator*(Fixed const & rhs)
{
	Fixed ret(this->toFloat() * rhs.toFloat());
//	std::cout << "Multiplication operator overload" << std::endl;
	return (ret);
}

Fixed					Fixed::operator/(Fixed const & rhs)
{
	Fixed ret(this->toFloat() / rhs.toFloat());
//	std::cout << "Divide operator overload" << std::endl;
	return (ret);
}
Fixed					Fixed::operator+(Fixed const & rhs)
{
	Fixed ret(this->toFloat() + rhs.toFloat());
//	std::cout << "Add operator overload" << std::endl;
	return (ret);
}
Fixed					Fixed::operator-(Fixed const & rhs)
{
	Fixed ret(this->toFloat() - rhs.toFloat());
//	std::cout << "Soustr operator overload" << std::endl;
	return (ret);
}

bool					Fixed::operator>(Fixed const & rhs)
{
	return (this->getRawBits() > rhs.getRawBits() ? true : false);
}

bool					Fixed::operator>=(Fixed const & rhs)
{
	return (this->getRawBits() >= rhs.getRawBits() ? true : false);
}

bool					Fixed::operator<(Fixed const & rhs)
{
	return (this->getRawBits() < rhs.getRawBits() ? true : false);
}

bool					Fixed::operator<=(Fixed const & rhs)
{
	return (this->getRawBits() <= rhs.getRawBits() ? true : false);
}

bool					Fixed::operator==(Fixed const & rhs)
{
	return (this->getRawBits() == rhs.getRawBits() ? true : false);
}

bool					Fixed::operator!=(Fixed const & rhs)
{
	return (this->getRawBits() != rhs.getRawBits() ? true : false);
}	

std::ostream&	operator<<(std::ostream& o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
