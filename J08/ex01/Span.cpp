#include "Span.hpp"

Span::Span(void)
{
	return;
}

Span::Span(Span const & src)
{
	*this = src;
	return;
}

Span::~Span(void)
{
	return;
}

void Span::addNumber(int num)
{

}

int Span::shortestSpan(void)
{

}

int Span::longestSpan(void)
{

}

std::list& Span::getList(void)
{
	return (m_list);
}

Span& Span::operator=(Span const & rhs)
{
	m_list = rhs.getList();
	return (*this);
}