#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
		std::string&	getTarget(void) const;
		void	execute(Bureaucrat const & executor) const;

		RobotomyRequestForm& operator=(RobotomyRequestForm const & rhs);
	private:
		std::string	m_target;
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const & src);
};
#endif