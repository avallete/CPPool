#include <iostream>
#include <fstream>

void	doIt(std::string Filename)
{
	char			c;
	std::fstream	file;
	file.open(Filename);
	if (file.is_open())
	{
		while (file.read(&c, 1))
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