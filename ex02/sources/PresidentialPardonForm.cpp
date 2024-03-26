/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:29:48 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 16:03:52 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm():
		AForm("PresidentialPardonForm", 25, 5), _target("default_target"){
	std::cout << CYAN << "PresidentialPardonForm with default_target created" << END_STYLE << std::endl;	
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): 
		AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << CYAN << "PresidentialPardonForm with target " << target << " created" << END_STYLE << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy): 
		AForm(cpy), _target(cpy._target) {
	std::cout << CYAN << "PresidentialPardonForm with target " << this->_target << " copied" << END_STYLE << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << PURPLE << "PresidentialPardonForm with target " << this->_target << " destructed" << END_STYLE << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	(void)rhs;
	std::cout << CYAN << "PresidentialPardonForm with target " << this->_target << " copied with assignment operator" << END_STYLE << std::endl;
	return (*this);
}

std::ostream	&PresidentialPardonForm::print(std::ostream &o) const {
	if (this->getSigned())
		o << "Form " << this->getName() << ", signed: yes";
	else
		o << "Form " << this->getName() << ", signed: no";
	o << ", required for signing: " << this->getRequiredSign();
	o << ", required for executing: " << this->getRequiredExec();
	o << ", target: " << this->getTarget();
	return (o);	
}

void	PresidentialPardonForm::doExecute() const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const {
	return (this->_target);
}
