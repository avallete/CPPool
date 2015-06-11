#include <iostream>
#include <string>

int main(void)
{
	std::string str("This is a little cute string !");
	std::string *ptrstr = &str;
	std::string& refstr = str;
	
	std::cout << "Display " << str << std::endl;
	std::cout << "Display using ptr " << *ptrstr << std::endl;
	std::cout << "Display usign ref" << refstr << std::endl;
	return (0);
}
