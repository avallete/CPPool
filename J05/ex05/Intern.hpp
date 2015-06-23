#ifndef INTERN_HPP
#define INTERN_HPP
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern(void);
		~Intern(void);
		Form* makeForm(std::string form, std::string target);

	private:
		Intern(Intern const & src);
		Intern& operator=(Intern const & rhs);	
};
#endif