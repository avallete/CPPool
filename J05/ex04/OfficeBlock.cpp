#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void): m_intern(NULL), m_sign(NULL), m_exec(NULL)
{
	return;
}

OfficeBlock::OfficeBlock(Intern& intern, Bureaucrat& sign, Bureaucrat &exec): m_intern(&intern), m_sign(&sign), m_exec(&exec)
{
	return;
}

OfficeBlock::OfficeBlock(OfficeBlock const & src)
{
	*this = src;
	return;
}

void	OfficeBlock::setIntern(Intern& src)
{
	m_intern = &src;
}
void	OfficeBlock::setSigner(Bureaucrat& src)
{
	m_sign = &src;
}
void	OfficeBlock::setExecutor(Bureaucrat& src)
{
	m_exec = &src;
}

void	OfficeBlock::doBureaucracy(std::string type, std::string target)
{
	Form *f;
	
	f = m_intern->makeForm(type, target);
	m_sign->signForm(*f);
	m_exec->executeForm(*f);
}

OfficeBlock::~OfficeBlock(void)
{
	return;
}

OfficeBlock& OfficeBlock::operator=(OfficeBlock const & rhs)
{
	(void)rhs;
	return (*this);
}