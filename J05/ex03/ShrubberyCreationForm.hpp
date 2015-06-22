#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm: public Form
{
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);
		std::string&	getTarget(void) const;
		void	execute(Bureaucrat const & executor) const;

		ShrubberyCreationForm& operator=(ShrubberyCreationForm const & rhs);
	private:
		std::string	m_target;
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
};
#endif