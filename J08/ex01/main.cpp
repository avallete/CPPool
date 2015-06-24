#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(5);

	sp.addNumber(3);

	sp.addNumber(17);

	sp.addNumber(9);

	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;

	std::cout << sp.longestSpan() << std::endl;
//	for (int i = 0; i < INT_MAX; i++)
//		sp.addNumber(rand());
	return (0);
}