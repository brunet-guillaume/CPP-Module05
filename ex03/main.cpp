/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:20:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 17:10:31 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
	help_msg("Testing RobotomyRequestForm constructors");
	AForm	*r1 = new RobotomyRequestForm();
	std::cout << *r1 << std::endl;
	RobotomyRequestForm	r2("home");
	std::cout << r2 << std::endl;
	RobotomyRequestForm	r3("garden");
	std::cout << r3 << std::endl;
	RobotomyRequestForm	r5("kitchen");
	std::cout << r5 << std::endl;

	std::cout << std::endl;
	try {
		help_msg("Trying to sign RobotomyRequestForn with target home without the required grade");
		r2.beSigned(b3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Signing RobotomyRequestForm with target home with the required grade");
		r2.beSigned(b2);
		std::cout << r2 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Trying to sign already signed RobotomyRequestForm with target home with the required grade");
		r2.beSigned(b2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	try {
		help_msg("Trying to sign RobotomyRequestForm with target garden without the required grade");
		b3.signForm(r3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Signing RobotomyRequestForm with target garden with the required grade");
		b2.signForm(r3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	help_msg("Testing RobotomyRequestForm copy constructors");
	*r1 = r2;
	warning_msg("Copied RobotomyRequestForm  can't change is _target, because it's a const std::string");
	std::cout << *r1 << std::endl;
	RobotomyRequestForm	r4(r2);
	std::cout << r4 << std::endl;

	std::cout << std::endl;
	try {
		help_msg("Trying to execute RobotomyRequestForm with target garden without the required grade");
		r3.execute(b3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Trying to execute RobotomyRequestForm with target kitchen which is not signed");
		r5.execute(*b1);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	try {
		help_msg("Executing RobotomyRequestForm with target garden with the required grade (x10)");
		for (int i = 0; i < 10; i++) {
			r3.execute(*b1);
			std::cout << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Bureaucrat with grade too low tries to execute RobotomyRequestForm with target home");
		b3.executeForm(r2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Bureaucrat with grade 0k tries to execute RobotomyRequestForm with target kitchen which is not signed");
		b2.executeForm(r5);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Bureaucrat with grade 0k execute RobotomyRequestForm with target home which is signed");
		b2.executeForm(r2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	help_msg("Testing PresidentialPardonForm constructors");
	AForm	*p1 = new PresidentialPardonForm();
	std::cout << *p1 << std::endl;
	PresidentialPardonForm	p2("home");
	std::cout << p2 << std::endl;
	PresidentialPardonForm	p3("garden");
	std::cout << p3 << std::endl;
	PresidentialPardonForm	p5("kitchen");
	std::cout << p5 << std::endl;

	std::cout << std::endl;
	try {
		help_msg("Trying to sign PresidentialPardonForn with target home without the required grade");
		p2.beSigned(b3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Signing PresidentialPardonForm with target home with the required grade");
		p2.beSigned(b2);
		std::cout << p2 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Trying to sign already signed PresidentialPardonForm with target home with the required grade");
		p2.beSigned(b2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	try {
		help_msg("Trying to sign PresidentialPardonForm with target garden without the required grade");
		b3.signForm(p3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Signing PresidentialPardonForm with target garden with the required grade");
		b2.signForm(p3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	help_msg("Testing PresidentialPardonForm copy constructors");
	*p1 = p2;
	warning_msg("Copied PresidentialPardonForm  can't change is _target, because it's a const std::string");
	std::cout << *p1 << std::endl;
	PresidentialPardonForm	p4(p2);
	std::cout << p4 << std::endl;

	std::cout << std::endl;
	try {
		help_msg("Trying to execute PresidentialPardonForm with target garden without the required grade");
		p3.execute(b3);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Trying to execute PresidentialPardonForm with target kitchen which is not signed");
		p5.execute(*b1);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	std::cout << std::endl;
	try {
		help_msg("Executing PresidentialPardonForm with target garden with the required grade");
		p3.execute(*b1);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Bureaucrat with grade too low tries to execute PresidentialPardonForm with target home");
		b3.executeForm(p2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Bureaucrat with grade 0k tries to execute PresidentialPardonForm with target kitchen which is not signed");
		b2.executeForm(p5);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	try {
		help_msg("Bureaucrat with grade 0k execute PresidentialPardonForm with target home which is signed");
		b2.executeForm(p2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	help_msg("Testing Intern constructors");
	Intern	*i1 = new Intern();
	Intern	i2;
	Intern	i3;

	std::cout << std::endl;
	help_msg("Testing copy constructors");
	*i1 = i2;
	Intern	i4(i2);

	AForm	*fi1;
	AForm	*fi2;
	AForm	*fi3;

	std::cout << std::endl;
	help_msg("Creating ShrubberyCreationForm with target garden with the help of an intern");
	fi1 = i1->makeForm("SHRUBBERY creation", "garden");
	std::cout << *fi1 << std::endl;

	std::cout << std::endl;
	help_msg("Creating RobotomyRequestForm with target sky with the help of an intern");
	fi2 = i1->makeForm("robotomy request", "sky");
	std::cout << *fi2 << std::endl;

	std::cout << std::endl;
	help_msg("Creating PresidentialPardonForm with target home with the help of an intern");
	fi3 = i1->makeForm("presidential PARdon", "home");
	std::cout << *fi3 << std::endl;

	std::cout << std::endl;
	help_msg("Trying to create a form that doesn't exists with the help of an intern");
	i1->makeForm("do_not_exist", "yup");

	std::cout << std::endl;
	help_msg("Destructors");
	delete (b1);
	delete (s1);
	delete (r1);
	delete (p1);
	delete (i1);
	delete (fi1);
	delete (fi2);
	delete (fi3);
	return (0);
}
