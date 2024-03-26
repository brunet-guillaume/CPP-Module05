/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:20:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 12:04:42 by gbrunet          ###   ########.fr       */
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
/*	Form	*f1 = new Form();
	std::cout << *f1 << std::endl;
	Form	f2("Contract 1", 5, 55);
	std::cout << f2 << std::endl;
	Form	f3("Contract 2", 70, 80);
	std::cout << f3 << std::endl;

	std::cout << std::endl;
	try {
		help_msg("Trying to sign form Contract 1 without the required grade");
		f2.beSigned(b3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Signing form Contract 1 with the required grade");
		f2.beSigned(b2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	try {
		help_msg("Trying to sign form Contract 2 without the required grade");
		b3.signForm(f3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Signing form Contract 2 with the required grade");
		b2.signForm(f3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	help_msg("Testing Form copy constructors");
	*f1 = f2;
	warning_msg("Copied Form can't change is _name, _required_sign and _required_exec (const)");
	std::cout << *f1 << std::endl;
	Form	f4(f2);
	std::cout << f4 << std::endl;

*/
	std::cout << std::endl;
	help_msg("Destructors");
	delete (b1);
//	delete (f1);
	return (0);
}
