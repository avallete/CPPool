#ifndef SPAN_HPP
#define SPAN_HPP
#include <list>
#include <iostream>
#include <exception>

class Span
{
	public:
		Span(Span const & src);
		Span(unsigned int N);
		~Span(void);
		void addNumber(int num);
		int shortestSpan(void);
		int longestSpan(void);
		std::list<int>& getList(void) const;

		Span& operator=(Span const & rhs);
		unsigned int	m_len;
	private:
		Span(void);
		std::list<int> 	m_list;
};
#endif