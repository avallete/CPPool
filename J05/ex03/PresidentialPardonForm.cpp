#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("PresidentialPardon", 25, 5)
{
	m_target = "default";
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardon", 25, 5)
{
	m_target = target;
	return;	
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): Form(src)
{
	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

std::string& 	PresidentialPardonForm::getTarget(void) const
{
	return ((std::string&)m_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= getXGrade())
		std::cout << m_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
	else
		throw Form::GradeTooLowException();
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	Form::operator=(rhs);
	m_target = rhs.getTarget();
	return (*this);
}