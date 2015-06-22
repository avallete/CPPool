#include "Intern.hpp"

Intern::Intern(void)
{
	return;
}

Intern::Intern(Intern const & src)
{
	*this = src;
	return;
}

Intern::~Intern(void)
{
	return;
}

Form*	Intern::makeForm(std::string form, std::string target)
{
	if (!form.compare("robotomy request"))
	{
		std::cout << "Intern creates RobotomyRequestForm" << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (!form.compare("pardon request"))
	{
		std::cout << "Intern creates PresidentialPardonForm" << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else if (!form.compare("shrubbery request"))
	{
		std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else
	{
		std::cout << "Could not find this form" << std::endl;
		throw std::exception();
	}
}

Intern& Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return (*this);
}