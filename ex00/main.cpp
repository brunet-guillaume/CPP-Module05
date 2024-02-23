/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:20:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/02/23 17:33:51 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
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
	help_msg("Destructors");
	delete (b1);
	return (0);
}
