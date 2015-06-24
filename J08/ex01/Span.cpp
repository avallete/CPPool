#include "Span.hpp"

Span::Span(void):m_list(0)
{
	return;
}

Span::Span(unsigned int N): m_list(N)
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
	try
	{
		std::cout << "size is: " << m_list.size() << std::endl;
		m_list.assign(1, num);
	}
	catch (std::exception &e)
	{
		std::cout << "Add number fail because : " << e.what() << std::endl;
	}
}

int Span::shortestSpan(void)
{
	m_list.sort();
	return (abs((m_list.front() + 1) - m_list.front()));
}

int Span::longestSpan(void)
{
	m_list.sort();
	return (abs(m_list.front() - m_list.back()));
}

std::list<int>& Span::getList(void) const
{
	return (const_cast<std::list<int>&>(m_list));
}

Span& Span::operator=(Span const & rhs)
{
	m_list = rhs.getList();
	return (*this);
}