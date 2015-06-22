#include "ShrubberyCreationForm.hpp"
#define L1 "       _-_\n"
#define L2 "    /~~   ~~\\\n"
#define L3 " /~~         ~~\\\n"
#define L4 "{               }\n"
#define L5 "\\\\  _-     -_  /\n"
#define L6 "   ~  \\\\ //  ~\n"
#define L7 "_- -   | | _- _\n"
#define L8 "  _ -  | |   -_\n"
#define L9 "      // \\\\\n"

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("ShrubberyCreation", 145, 137)
{
	m_target = "default_shrubbery";
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreation", 145, 137)
{
	m_target = target + "_shrubbery";
	return;	
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src): Form(src)
{
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

std::string& 	ShrubberyCreationForm::getTarget(void) const
{
	return ((std::string&)m_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::fstream file;
	if (executor.getGrade() <= getXGrade())
	{
		file.open(m_target, std::fstream::in | std::fstream::app);
		file << L1 << L2 << L3 << L4 << L5 << L6 << L7 << L8 << L9 << std::endl;
		file.close();
	}
	else
		throw Form::GradeTooLowException();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	Form::operator=(rhs);
	m_target = rhs.getTarget();
	return (*this);
}