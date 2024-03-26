/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:20:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 14:22:06 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void	help_msg(std::string msg) {
	std::cout << GREEN << TITLE << " 💬 " << msg << " " << END_STYLE << std::endl;
}

void	warning_msg(std::string msg) {
	std::cout << " ⚠️  " << GREEN << BOLD << UNDERLINE << msg << END_STYLE << std::endl;
}

int	main() {
	help_msg("Testing base constructors");
	Bureaucrat	*b1 = new Bureaucrat();
	std::cout << *b1 << std::endl;
	Bureaucrat	b2("Isabelle", 5);
	std::cout << b2 << std::endl;
	Bureaucrat	b3("Michel", 145);
	std::cout << b3 << std::endl;

	std::cout << std::endl;
	help_msg("Testing copy constructors");
	*b1 = b2;
	warning_msg("Copied Bureaucrat can't change is _name, because it's a const std::string");
	std::cout << *b1 << std::endl;
	Bureaucrat	b4(b2);
	std::cout << b4 << std::endl;

	std::cout << std::endl;
	try {
		help_msg("Trying to create bureaucrate with grade 160");
		Bureaucrat b5("Mathieu", 160);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	try {
		help_msg("Trying to create bureaucrate with grade 0");
		Bureaucrat b5("Mathieu", 0);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	try {
		help_msg("Trying to increment Isabelle grade 10 times");
		for (int i = 0; i < 10; i++)
		{
			b2.incrementGrade();
			std::cout << b2 << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	try {
		help_msg("Trying to decrement Michel grade 10 times");
		for (int i = 0; i < 10; i++)
		{
			b3.decrementGrade();
			std::cout << b3 << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	help_msg("Testing ShrubberyCreationForm constructors");
	AForm	*s1 = new ShrubberyCreationForm();
	std::cout << *s1 << std::endl;
	ShrubberyCreationForm	s2("home");
	std::cout << s2 << std::endl;
	ShrubberyCreationForm	s3("garden");
	std::cout << s3 << std::endl;
	ShrubberyCreationForm	s5("kitchen");
	std::cout << s5 << std::endl;

	std::cout << std::endl;
	try {
		help_msg("Trying to sign ShrubberyCreationForn with target home without the required grade");
		s2.beSigned(b3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Signing ShrubberyCreationForm with target home with the required grade");
		s2.beSigned(b2);
		std::cout << s2 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Trying to sign already signed ShrubberyCreationForm with target home with the required grade");
		s2.beSigned(b2);
		std::cout << s2 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	try {
		help_msg("Trying to sign ShrubberyCreationForm with target garden without the required grade");
		b3.signForm(s3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Signing ShrubberyCreationForm with target garden with the required grade");
		b2.signForm(s3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	help_msg("Testing ShrubberyCreationForm copy constructors");
	*s1 = s2;
	warning_msg("Copied ShrubberyCreationForm  can't change is _target, because it's a const std::string");
	std::cout << *s1 << std::endl;
	ShrubberyCreationForm	s4(s2);
	std::cout << s4 << std::endl;

	std::cout << std::endl;
	try {
		help_msg("Trying to execute ShrubberyCreationForm with target garden without the required grade");
		s3.execute(b3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Trying to execute ShrubberyCreationForm with target kitchen which is not signed");
		s5.execute(*b1);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	try {
		help_msg("Executing ShrubberyCreationForm with target garden with the required grade");
		s3.execute(*b1);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Bureaucrat with grade too low tries to execute ShrubberyCreationForm with target home");
		b3.executeForm(s2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Bureaucrat with grade 0k tries to execute ShrubberyCreationForm with target kitchen which is not signed");
		b2.executeForm(s5);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Bureaucrat with grade 0k execute ShrubberyCreationForm with target home which is signed");
		b2.executeForm(s2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	help_msg("Destructors");
	delete (b1);
	delete (s1);
	return (0);
}
