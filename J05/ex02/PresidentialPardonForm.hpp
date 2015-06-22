#ifndef PRESIDENTIAL_PARDO_FORM_HPP
#define PRESIDENTIAL_PARDO_FORM_HPP
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);
		std::string&	getTarget(void) const;
		void	execute(Bureaucrat const & executor) const;

		PresidentialPardonForm& operator=(PresidentialPardonForm const & rhs);
	private:
		std::string	m_target;
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const & src);
};
#endif