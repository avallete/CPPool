#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): m_name("Default"), m_sgrade(1), m_xgrade(1), m_sign(0)
{
	return;
}

Form::Form(std::string name, int sgrade, int xgrade): m_name(name), m_sgrade(sgrade), m_xgrade(xgrade), m_sign(0)
{
	if (m_sgrade > 150 || m_sgrade < 1)
		m_sgrade < 1 ? throw GradeTooHighException() : throw GradeTooLowException();
	if (m_xgrade > 150 || m_xgrade < 1)
		m_xgrade < 1 ? throw GradeTooHighException() : throw GradeTooLowException();	
	return;
}

Form::Form(Form const & src): m_name(src.getName()), m_sgrade(src.getSGrade()), m_xgrade(src.getXGrade())
{
	*this = src;
	return;
}

Form::~Form(void)
{
	return;
}


std::string&	Form::getName(void) const
{
	return ((std::string&)m_name);
}

int				Form::getSGrade(void) const
{
	return (m_sgrade);
}

int				Form::getXGrade(void) const
{
	return (m_xgrade);
}

bool			Form::getSign(void) const
{
	return (m_sign);
}

void			Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= m_sgrade)
		m_sign = 1;
	else
		throw GradeTooLowException();
	return;
}

Form& Form::operator=(Form const & rhs)
{
	m_sign = rhs.getSign();
	return (*this);
}

std::ostream& operator<<(std::ostream& o, Form& b)
{
	o << b.getName() << ", form require grade for sign: " << b.getSGrade() << " for execute: " << b.getXGrade() << " sign: " << b.getSign(); 
	return (o);
}