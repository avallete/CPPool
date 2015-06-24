#include <iostream>
#include <list>
#include <algorithm>
#include "easyfind.hpp"

int main(void)
{
	std::list<int> test;
	std::list<int>::const_iterator it;

	test.push_back(1);
	test.push_back(17);
	test.push_back(21);
	test.push_back(42);
	test.push_back(36);
	test.push_back(47);
	it = easyfind< std::list<int> >(test, 42);
	if (it != test.end())
		std::cout << "My func Search 42 (is in): " << *it << std::endl;
	else
		std::cout << "42 not found" << std::endl;
	it = easyfind< std::list<int> >(test, 9);
	if (it != test.end())
		std::cout << "My func Search 9 (is in): " << *it << std::endl;
	else
		std::cout << "9 not found it is : "<< *it << std::endl;
	std::cout << "\n\nSames test with algorithm find\n\n" << std::endl;
	it = find(test.begin(), test.end(), 42);
	if (it != test.end())
		std::cout << "Search 42 (is in): " << *it << std::endl;
	else
		std::cout << "42 not found" << std::endl;
	it = find(test.begin(), test.end(), 9);
	if (it != test.end())
		std::cout << "Search 9 (is in): " << *it << std::endl;
	else
		std::cout << "9 not found it is: "<< *it << std::endl;
}