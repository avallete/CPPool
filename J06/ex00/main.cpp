#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctgmath>
#include <cfloat>

int 	main(int argc, char const *argv[])
{
	double	d;
	int 	i;
	float	fl;
	char	c;
	if (argc == 2)
	{
		std::string buf;
		argv++;
		buf = *argv;
		d = static_cast<double>(strtold(buf.data(), NULL));
		fl = static_cast<float>(d);
		i = static_cast<int>(d);
		c = static_cast<char>(d);
		if (d >= 0 && d <= 255)
		{
			if (isprint(c))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: " << "Non displayable" << std::endl;			
		}
		else
			std::cout << "char: " << "impossible" << std::endl;			
		if (d <= INT_MAX && d >= INT_MIN)
		{
			std::cout <<
			"int: " << i << std::endl;
		}
		else
		{
			std::cout <<
			"int: " << "impossible" << std::endl;
		}
		std::cout.precision(1);
		std::cout << std::setiosflags(std::ios::fixed);
		std::cout <<
		"float: " << fl << 'f' << std::endl <<
		"double: " << d << std::endl;
	}
	return 0;
}