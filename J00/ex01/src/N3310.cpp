#include "N3310.h"

int main(void)
{
    Book test;
    std::string cmd;
    int next;

    next = 1;
    while (next)
    {
    	std::cout << "Enter Your Command (ADD | SEARCH | EXIT) : ";
    	next = getline(std::cin, cmd);
    	if (cmd == "SEARCH")
    		test.search();
    	else if (cmd == "ADD")
    		test.add();
    	else if (cmd == "EXIT")
    		next = 0;
    	else if (next)
    		std::cout << "Sorry bad input, try again :)" << std::endl;
    }
    return (0);
}