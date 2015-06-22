#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): m_name("Bureaucrat"), m_grade(150)
{
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade): m_name(name), m_grade(grade)
{
	if (m_grade > 150 || m_grade < 1)
		m_grade < 1 ? throw GradeTooHighException() : throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	return;
}

std::string&	Bureaucrat::getName(void) const
{
	return ((std::string&)m_name);
}

int				Bureaucrat::getGrade(void) const
{
	return (m_grade);
}

void		Bureaucrat::incGrade(void)
{
	if (m_grade - 1 < 1)
		throw GradeTooHighException();
	else
		m_grade -= 1;
}

void		Bureaucrat::decGrade(void)
{
	if (m_grade + 1 > 150)
		throw GradeTooLowException();
	else
		m_grade += 1;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & rhs)
{
	m_grade = rhs.getGrade();
	return (*this);
}

std::ostream& operator<<(std::ostream& o, Bureaucrat& b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade(); 
	return (o);
}