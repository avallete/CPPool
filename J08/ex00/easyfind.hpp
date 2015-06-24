#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <exception>
template<typename T>
typename T::const_iterator easyfind(const T& container, const int& needle)
{
	try
	{
		for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		{
			if ((*it) == needle)
				return (it);
		}
		return (container.end());
	}
	catch (std::exception &e)
	{
		std::cout << "Error std::exception has been catched " << e.what() << std::endl;
		return (container.end());
	}
}
#endif