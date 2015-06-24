#ifndef SPAN_HPP
#define SPAN_HPP
#include <list>

class Span
{
	public:
		Span(void);
		Span(Span const & src);
		~Span(void);
		void addNumber(int num);
		int shortestSpan(void);
		int longestSpan(void);
		Span& getList(void);

		Span& operator=(Span const & rhs);
		std::list<int> m_list();	
};
#endif