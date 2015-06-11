#include <iostream>
#include <string>

int main(void)
{
	std::string str("HI THIS IS BRAIN");
	std::string *ptrstr = &str;
	std::string& refstr = str;
	
	std::cout << str << std::endl;
	std::cout << *ptrstr << std::endl;
	std::cout << refstr << std::endl;
	return (0);
}
