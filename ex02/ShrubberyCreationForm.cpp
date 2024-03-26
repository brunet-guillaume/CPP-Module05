/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:04:14 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 12:07:59 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm():
		AForm("ShrubberyCreationForm", 145, 137), _target("default_target"){
	std::cout << CYAN << "ShrubberyCreationForm with default_target created" << END_STYLE << std::endl;	
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): 
		AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << CYAN << "ShrubberyCreationForm with target " << target << " created" << END_STYLE << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy): 
		AForm(cpy), _target(cpy._target) {
	std::cout << CYAN << "ShrubberyCreationForm with target " << this->_target << " copied" << END_STYLE << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << PURPLE << "ShrubberyCreationForm with target " << this->_target << " destructed" << END_STYLE << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	(void)rhs;
	std::cout << CYAN << "ShrubberyCreationForm with target " << this->_target << " copied with assignment operator" << END_STYLE << std::endl;
	return (*this);
}

std::ostream	&ShrubberyCreationForm::print(std::ostream &o) const {
	if (this->getSigned())
		o << "Form " << this->getName() << ", signed: yes";
	else
		o << "Form " << this->getName() << ", signed: no";
	o << ", required for signing: " << this->getRequiredSign();
	o << ", required for executing: " << this->getRequiredExec();
	o << ", target: " << this->getTarget();
	return (o);	
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	(void) executor;
	std::cout << "ok" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}
