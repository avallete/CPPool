#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
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
		std::vector<int>& getVector(void) const;
		unsigned int getSize() const;
		unsigned int getIndex() const;

		Span& operator=(Span const & rhs);
	private:
		Span(void);
		std::vector<int> 	m_vector;
		unsigned int		m_size;
		unsigned int		m_index;
};
#endif