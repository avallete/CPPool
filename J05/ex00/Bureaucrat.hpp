#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(std::string, int);
	Bureaucrat(Bureaucrat const &);
	~Bureaucrat(void);
	std::string&	getName(void) const;
	int				getGrade(void) const;
	void			incGrade(void);
	void			decGrade(void);

	Bureaucrat& operator=(Bureaucrat const &);	
private:
	std::string const	m_name;
	int					m_grade;
	std::exception		to_low;
	std::exception 		to_hight;
protected:
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
};
std::ostream& operator<<(std::ostream&, Bureaucrat&);
#endif