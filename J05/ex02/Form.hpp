#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(Form const & src);
		Form(std::string name, int sgrade, int xgrade);
		~Form(void);
		std::string&	getName(void) const;
		int				getSGrade(void) const;
		int				getXGrade(void) const;
		bool			getSign(void) const;
		void			beSigned(Bureaucrat& b);
		virtual	void	execute(Bureaucrat const & executor) const {(void)executor;return;};

		Form& operator=(Form const & rhs);
		class GradeTooHighException: public std::exception
		{
			private:
				GradeTooHighException& operator=(GradeTooHighException const & rhs);

			public:
				GradeTooHighException(GradeTooHighException const & src): std::exception(src)
				{return;};
				GradeTooHighException(void){return;};
				~GradeTooHighException(void) throw(){return;};
				virtual const char* what() const throw(){
					return ("Grade Too Hight");
				};
		};
		class GradeTooLowException: public std::exception
		{
			private:
				GradeTooLowException& operator=(GradeTooLowException const & rhs);

			public:
				GradeTooLowException(GradeTooLowException const & src): std::exception(src)
				{return;};
				GradeTooLowException(void)
				{return;};
				~GradeTooLowException(void) throw(){return;};
				virtual const char* what() const throw(){
					return ("Grade Too Low");
				};
		};	
	private:
		std::string const	m_name;	
		int	const			m_sgrade;
		int	const			m_xgrade;
		bool				m_sign;
};
std::ostream& operator<<(std::ostream&, Form&);
#include "Bureaucrat.hpp"
#endif