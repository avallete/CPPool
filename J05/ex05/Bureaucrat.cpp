#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void): m_name("Bureaucrat"), m_grade(150)
{
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade): m_name(name), m_grade(grade)
{
	if (m_grade > 150 || m_grade < 1)
		m_grade < 1 ? throw GradeTooHighException() : throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & src): m_name(src.getName())
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

void		Bureaucrat::signForm(Form& f) const
{
	try
	{
		f.beSigned((Bureaucrat&)*this);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << m_name << " " << " cannot sign " << f << " because " << e.what() << std::endl;
		return;
	}
	std::cout << m_name << " " << " signs " << f << std::endl;
	return;
}

void		Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute((Bureaucrat&)*this);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << m_name << " " << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
		return;	
	}
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