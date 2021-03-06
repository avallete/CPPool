#include "Span.hpp"

int main()
{
	Span sp = Span(5);
    Span ft = Span(100000);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

    ft.addNumber(5);
    try
    {
        std::cout << ft.shortestSpan() << std::endl;
        std::cout << ft.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "No span to find here !" << std::endl;
    }
    try
    {
        for (int i = 0; i < 100000000; i++)
            ft.addNumber(rand());
    }
    catch (std::exception &e)
    {
        std::cout << "Sososos, nop ! You can't addNumber anymore" << std::endl;
    }
	std::cout << "Find shortest and longest Span in list size: " << ft.getSize() << std::endl;
    std::cout << ft.shortestSpan() << std::endl;
    std::cout << ft.longestSpan() << std::endl;
	return (0);
}
