#ifndef OFFICE_BLOCK_HPP
#define OFFICE_BLOCK_HPP
#include "Intern.hpp"

class OfficeBlock
{
	public:
		OfficeBlock(void);
		OfficeBlock(Intern& intern, Bureaucrat& sign, Bureaucrat &exec);
		void	setIntern(Intern&);
		void	setSigner(Bureaucrat&);
		void	setExecutor(Bureaucrat&);
		void	doBureaucracy(std::string type, std::string target);
		~OfficeBlock(void);

	private:
		OfficeBlock(OfficeBlock const & src);
		OfficeBlock& operator=(OfficeBlock const & rhs);	
		Intern*		m_intern;
		Bureaucrat*	m_sign;
		Bureaucrat*	m_exec;		
};
#endif