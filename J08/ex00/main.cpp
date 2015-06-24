#include <iostream>
#include <list>
#include <vector>
#include <array>
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
	it = std::find(test.begin(), test.end(), 42);
	if (it != test.end())
		std::cout << "Search 42 (is in): " << *it << std::endl;
	else
		std::cout << "42 not found" << std::endl;
	it = std::find(test.begin(), test.end(), 9);
	if (it != test.end())
		std::cout << "Search 9 (is in): " << *it << std::endl;
	else
		std::cout << "9 not found it is: "<< *it << std::endl;

	std::cout << "\n\n Test with Array container" << std::endl;	
	std::array<int, 20> arr;
	arr.fill(42);
	std::array<int, 20>::const_iterator at;
	at = easyfind< std::array<int, 20> >(arr, 42);
	if (at != arr.end())
		std::cout << "My func Search 42 (is in): " << *at << std::endl;
	else
		std::cout << "42 not found" << std::endl;
	at = easyfind< std::array<int, 20> >(arr, 9);
	if (at != arr.end())
		std::cout << "My func Search 9 (is in): " << *at << std::endl;
	else
		std::cout << "9 not found at is : "<< *at << std::endl;
	std::cout << "\n\nSames arr with algorithm find\n\n" << std::endl;
	at = std::find(arr.begin(), arr.end(), 42);
	if (at != arr.end())
		std::cout << "Search 42 (is in): " << *at << std::endl;
	else
		std::cout << "42 not found" << std::endl;
	at = std::find(arr.begin(), arr.end(), 9);
	if (at != arr.end())
		std::cout << "Search 9 (is in): " << *at << std::endl;
	else
		std::cout << "9 not found at is: "<< *at << std::endl;

	std::cout << "\n\n Test with Vector container" << std::endl;	
	std::vector<int> vector;

	vector.push_back(1);
	vector.push_back(17);
	vector.push_back(21);
	vector.push_back(42);
	vector.push_back(36);
	vector.push_back(47);	
	std::vector<int>::const_iterator vt;
	vt = easyfind< std::vector<int> >(vector, 42);
	if (vt != vector.end())
		std::cout << "My func Search 42 (is in): " << *vt << std::endl;
	else
		std::cout << "42 not found" << std::endl;
	vt = easyfind< std::vector<int> >(vector, 9);
	if (vt != vector.end())
		std::cout << "My func Search 9 (is in): " << *vt << std::endl;
	else
		std::cout << "9 not found vt is : "<< *vt << std::endl;
	std::cout << "\n\nSames vector with algorithm find\n\n" << std::endl;
	vt = std::find(vector.begin(), vector.end(), 42);
	if (vt != vector.end())
		std::cout << "Search 42 (is in): " << *vt << std::endl;
	else
		std::cout << "42 not found" << std::endl;
	vt = std::find(vector.begin(), vector.end(), 9);
	if (vt != vector.end())
		std::cout << "Search 9 (is in): " << *vt << std::endl;
	else
		std::cout << "9 not found vt is: "<< *vt << std::endl;
}