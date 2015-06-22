/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 13:13:18 by marene            #+#    #+#             */
/*   Updated: 2015/04/12 15:08:47 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int		main(void)
{
	try
	{
		Bureaucrat	bob("bob", 151);
	}
	catch (std::exception const& e)
	{
		std::cout << "bob: " << e.what() << std::endl;
	}
	Bureaucrat	michel_base;
	Bureaucrat	michel_grade("michel", 1);
	Bureaucrat	bob_base("bob", 150);
	Bureaucrat	bob_grade("bob_grade", 42);

	std::cout
		<< michel_base
		<< std::endl
		<< michel_grade
		<< std::endl
		<< bob_base
		<< std::endl
		<< bob_grade
		<< std::endl;
	try
	{
		michel_grade.incGrade();
	}
	catch (std::exception const& e)
	{
		std::cout << michel_grade << ": "<< e.what() << std::endl;
	}
	michel_base.incGrade();
	std::cout << michel_base << std::endl;
	michel_base.decGrade();
	std::cout << michel_base << std::endl;
	try
	{
		michel_grade.incGrade();
	}
	catch (std::exception const& e)
	{
		std::cout << michel_grade << ": " << e.what() << std::endl;
	}
	std::cout << bob_grade << std::endl;
	bob_grade.decGrade();
	std::cout << bob_grade << std::endl;
	bob_grade.decGrade();
	std::cout << bob_grade << std::endl;
}
