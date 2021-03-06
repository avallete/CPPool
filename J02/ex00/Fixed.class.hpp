#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP
#include <iostream>
#include <string>
class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);
		Fixed&	operator=(Fixed const & rhs);
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
	private:
		int			_raw;
		static const int	_fix;
};
#endif
