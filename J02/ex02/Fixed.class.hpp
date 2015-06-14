#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP
#include <string>
#include <cmath>
class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(int const nb);
		Fixed(float const nb);
		~Fixed(void);
		Fixed&					operator=(Fixed const & rhs);
		Fixed&					operator++();
		Fixed					operator++(int);
		Fixed&					operator--();
		Fixed					operator--(int);
		Fixed					operator*(Fixed const & rhs);
		Fixed					operator/(Fixed const & rhs);
		Fixed					operator+(Fixed const & rhs);
		Fixed					operator-(Fixed const & rhs);
		bool					operator>(Fixed const & rhs);
		bool					operator>=(Fixed const & rhs);
		bool					operator<(Fixed const & rhs);
		bool					operator<=(Fixed const & rhs);
		bool					operator==(Fixed const & rhs);
		bool					operator!=(Fixed const & rhs);		
		static Fixed&			min(Fixed const & f1, Fixed const & f2);
		static Fixed&			min(Fixed & f1, Fixed & f2);
		static Fixed&			max(Fixed const & f1, Fixed const & f2);
		static Fixed&			max(Fixed & f1, Fixed & f2);
		void					setRawBits(int const raw);
		int						getRawBits(void) const;
		float					toFloat(void) const;
		int						toInt(void) const;
	private:
		int const				_fix;
		int						_raw;
};
		std::ostream&			operator<<(std::ostream& o, Fixed const & rhs);
#endif