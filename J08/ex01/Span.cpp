#include "Span.hpp"

Span::Span(void): m_vector(), m_size(0), m_index(0)
{
	return;
}

Span::Span(unsigned int N): m_vector(), m_size(N), m_index(0)
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
	if (m_index < m_size)
	{
		m_vector.push_back(num);
		m_index++;
	}
	else
		throw std::exception();
}

int Span::shortestSpan(void)
{
	if (m_index <= 1)
		throw std::exception();
	std::sort(m_vector.begin(), m_vector.end());
	int span = abs(m_vector[0]- m_vector[1]);
	int sptw;
	for (unsigned int i = 0; i < m_index; i++)
	{
		if ((sptw = abs(m_vector[i] - m_vector[i + 1])) < span)
			span = sptw;
	}
	return (span);
}

int Span::longestSpan(void)
{
	if (m_index <= 1)
		throw std::exception();
	return (abs(*std::min_element(m_vector.begin(), m_vector.end()) -
			*std::max_element(m_vector.begin(), m_vector.end())));
}

std::vector<int>& Span::getVector(void) const
{
	return (const_cast<std::vector<int>&>(m_vector));
}

unsigned int Span::getSize() const
{
	return (m_size);
}

unsigned int Span::getIndex() const
{
	return (m_index);
}

Span& Span::operator=(Span const & rhs)
{
	m_vector = rhs.getVector();
	m_size = getSize();
	m_index = rhs.m_index;
	return (*this);
}