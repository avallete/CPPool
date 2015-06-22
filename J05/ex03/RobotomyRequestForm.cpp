#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form("RobotomyRequest", 72, 45)
{
	m_target = "default";
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequest", 72, 45)
{
	m_target = target;
	return;	
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): Form(src)
{
	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

std::string& 	RobotomyRequestForm::getTarget(void) const
{
	return ((std::string&)m_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= getXGrade())
	{
		if (rand() % 2)
			std::cout << m_target << " has been robotomized successfully." << std::endl;
		else
			std::cout << m_target << " robotomization failure." << std::endl;
	}
	else
		throw Form::GradeTooLowException();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	Form::operator=(rhs);
	m_target = rhs.getTarget();
	return (*this);
}