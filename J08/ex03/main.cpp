#include <iostream>
#include <fstream>
#include "BrainRun.hpp"

void	doIt(std::string Filename)
{
	BrainRun		run;
	char			c;
	std::fstream	file;
	file.open(Filename);
	if (file.is_open())
	{
		while (file.read(&c, 1))
			run.addIns(c);
		run.runIt();
	}
	else
		std::cout << "File not found" << std::endl;
}

int main(int argc, char const *argv[])
{
	if (argc > 1)
		doIt(argv[1]);
	return 0;
}