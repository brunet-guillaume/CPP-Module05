/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:13:36 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 17:04:33 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include <cstring>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << CYAN << "Intern created" << END_STYLE << std::endl;
}

Intern::Intern(const Intern &cpy) {
	(void) &cpy;
	std::cout << CYAN << "Intern copied" << std::endl;
}

Intern::~Intern() {
	std::cout << PURPLE << "Intern destructed" << END_STYLE << std::endl;
}

Intern	&Intern::operator=(const Intern &rhs) {
	(void) rhs;
	std::cout << CYAN << "Intern copied with assignment operator" << END_STYLE << std::endl;
	return (*this);
}

AForm	*Intern::makeForm(const std::string form_name, const std::string form_target) {
	AForm	*new_form;

	switch (form_type(form_name)) {
		case SHRUBBERY_CREATION:
			new_form = new ShrubberyCreationForm(form_target);
			break;
		case ROBOTOMY_REQUEST:
			new_form = new RobotomyRequestForm(form_target);
			break;
		case PRESIDENTIAL_PARDON:
			new_form = new PresidentialPardonForm(form_target);
			break;
		default:
			std::cerr << "Error : The form " << form_name << " doesn't exist" << std::endl;
			return (NULL);
	}
	std::cout << "Intern creates " << new_form->getName() << std::endl;
	return (new_form);
}

std::string	lower(const std::string str) {
	std::string	lower_str;

	lower_str = str;
	for (size_t i = 0; i < strlen(str.c_str()); i++) {
		lower_str[i] = tolower(str[i]);
	}
	return (lower_str);
}

enum e_form_name	form_type(const std::string str) {
	const std::string	forms_names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++) {
		if (lower(str) == forms_names[i])
			return (static_cast<e_form_name>(i));
	}
	return (NONE);
}
