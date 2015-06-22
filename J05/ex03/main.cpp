/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 13:13:18 by marene            #+#    #+#             */
/*   Updated: 2015/04/12 16:08:18 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int		main(void)
{
	Bureaucrat	bob("bob", 45);
	Bureaucrat	jim("jim", 150);
	Bureaucrat	zac("zac", 2);
	Form		A4("A4", 45, 45);
	Form		A5("A5", 150, 21);
	ShrubberyCreationForm Creation("home");
	PresidentialPardonForm Pardon("Amedy Coulibaly");
	RobotomyRequestForm Robot("Zaz");

	try
	{
		Form a("fifi", 0, 2);
	}
	catch (std::exception const& e)
	{
		std::cout << "Form a: " << e.what() << std::endl;
	}
	try
	{
		Form b("fifi", 42, 151);
	}
	catch (std::exception const& e)
	{
		std::cout << "Form b: " << e.what() << std::endl;
	}
	std::cout << A4 << std::endl << A5 << std::endl << std::endl;
	std::cout << bob << std::endl << jim << std::endl << std::endl;
	try
	{
		A4.beSigned(jim);
	}
	catch (std::exception const& e)
	{
		std::cout << "Form A4: " << e.what() << std::endl;
	}
	std::cout << A4 << std::endl << std::endl;
	try
	{
		A4.beSigned(bob);
	}
	catch (std::exception const& e)
	{
		std::cout << "Form A4: " << e.what() << std::endl;
	}
	std::cout << A4 << std::endl << std::endl;
	bob.signForm(A4);
	bob.signForm(A5);
	jim.signForm(A4);
	jim.executeForm(Creation);
	bob.executeForm(Creation);
	zac.signForm(Pardon);
	zac.executeForm(Pardon);
	jim.executeForm(Pardon);
	zac.signForm(Robot);
	zac.executeForm(Robot);
	zac.executeForm(Robot);
	zac.executeForm(Robot);
	zac.executeForm(Robot);
	jim.executeForm(Robot);
}
