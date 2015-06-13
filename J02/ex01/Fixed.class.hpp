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
		Fixed&			operator=(Fixed const & rhs);
		void			setRawBits(int const raw);
		int				getRawBits(void) const;
		float			toFloat(void) const;
		int				toInt(void) const;
	private:
		int const		_fix;
		int				_raw;
};
		std::ostream&	operator<<(std::ostream& o, Fixed const & rhs);
#endif