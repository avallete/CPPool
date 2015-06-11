#ifndef PONY_CLASS_HPP
#define PONY_CLASS_HPP
#include <iostream>
#include <string>
class Pony
{
public:
			Pony();
			~Pony();
	void	speak(void)	const;
	void	define_it(char const *color, char const *name, char const *place);
private:
	std::string _infos[3];
};
#endif