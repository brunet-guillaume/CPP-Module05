/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:04:14 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 14:06:06 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

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

void	ShrubberyCreationForm::doExecute() const {
	std::ofstream	outfile((this->getTarget() + "_shrubbery").c_str(), std::ofstream::out);

	if (!outfile.is_open())
	{
		std::cerr << "Unable to create " << this->getTarget() << "_shrubbery file" << std::endl;
		return ;
	}
	outfile << "               ,@@@@@@@," << std::endl;
	outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	outfile << "       |o|        | |         | |" << std::endl;
	outfile << "       |.|        | |         | |" << std::endl;
	outfile << "/_-/\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	outfile.close();
}

std::string	ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}
