#ifndef BRAIN_RUN_HPP
#define BRAIN_RUN_HPP
#include <iostream>
#include <list>
#include "Operation.hpp"

class BrainRun
{
	public:
		BrainRun(void);
		BrainRun(BrainRun const & src);
		~BrainRun(void);
		void	addIns(char c);
		void	runIt(void);

		BrainRun& operator=(BrainRun const & rhs);
	protected:
		std::list<Operation> m_list;
};
#endif