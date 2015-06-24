#include "Array.hpp"
#include <iostream>

int main(void)
{	
	Array<int> test;
	Array<double> coco(42);
	Array<double> cococ(coco);
	std::cout << cococ[1] << std::endl;
	Array<double> cocoe = coco;
	std::cout << "size test: " << test.size() << std::endl;
	std::cout << "size coco: " << coco.size() << std::endl;
	std::cout << "size cococ: " << cococ.size() << std::endl;
	std::cout << "size cocoe: " << cocoe.size() << std::endl;
	std::cout << "Array content :" << coco[4] << 
	" | " << cococ[5] << " | " << cocoe[6] << std::endl;
	cococ[5] = static_cast<double>(42);
	coco[4] = 3242342342;
	cocoe[6] = 21;
	std::cout << "Array content :" << coco[4] << 
	" | " << cococ[5] << " | " << cocoe[6] << std::endl;
	Array<std::string> string_panthere(21);
	string_panthere[5] = "boulgi boulga c'est moi le string";
	std::cout << string_panthere[5] << std::endl;
	try
	{
		std::cout << string_panthere[22] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "exception found : " << e.what() << std::endl;
	}
	try
	{
		std::cout << string_panthere[-21] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "exception found : " << e.what() << std::endl;
	}
	try
	{
		std::cout << string_panthere[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "exception found : " << e.what() << std::endl;
	}
	return 0;
}