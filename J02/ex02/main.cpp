#include <iostream>
#include "Fixed.class.hpp"

int main( void ) 
{
	Fixed a;
	Fixed z(0);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	Fixed c(21.0f);
	Fixed d( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << c << std::endl;
	std::cout << ++c << std::endl;
	std::cout << c << std::endl;
	std::cout << c++ << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << d + c << std::endl;
	std::cout << d - c << std::endl;
	std::cout << d / c << std::endl;
	std::cout << d * c << std::endl;
	std::cout << (d < c) << std::endl;
	std::cout << (d > c) << std::endl;
	std::cout << (d <= c) << std::endl;
	std::cout << (d >= c) << std::endl;
	std::cout << (d != c) << std::endl;
	std::cout << (d == c) << std::endl;
	std::cout << "zero test" << std::endl;
	std::cout << (d / z) << std::endl;
	std::cout << (d * z) << std::endl;
	std::cout << Fixed::max( c, d ) << std::endl;
	std::cout << Fixed::min( c, d ) << std::endl;
	return 0;
}
