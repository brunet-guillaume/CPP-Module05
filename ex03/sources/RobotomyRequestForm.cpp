/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:56:08 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 15:30:06 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm():
		AForm("RobotomyRequestForm", 72, 45), _target("default_target"){
	std::cout << CYAN << "RobotomyRequestForm with default_target created" << END_STYLE << std::endl;	
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): 
		AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << CYAN << "RobotomyRequestForm with target " << target << " created" << END_STYLE << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy): 
		AForm(cpy), _target(cpy._target) {
	std::cout << CYAN << "RobotomyRequestForm with target " << this->_target << " copied" << END_STYLE << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << PURPLE << "RobotomyRequestForm with target " << this->_target << " destructed" << END_STYLE << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	(void)rhs;
	std::cout << CYAN << "RobotomyRequestForm with target " << this->_target << " copied with assignment operator" << END_STYLE << std::endl;
	return (*this);
}

std::ostream	&RobotomyRequestForm::print(std::ostream &o) const {
	if (this->getSigned())
		o << "Form " << this->getName() << ", signed: yes";
	else
		o << "Form " << this->getName() << ", signed: no";
	o << ", required for signing: " << this->getRequiredSign();
	o << ", required for executing: " << this->getRequiredExec();
	o << ", target: " << this->getTarget();
	return (o);	
}

void	RobotomyRequestForm::doExecute() const {
	if (std::rand() % 100 < 50) {
		std::cout << "BzzzzRzzRrrrzzZZzzzz." << std::endl;
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
	} else {
		std::cout << "Robotomy failed." << std::endl;
	}
}

std::string	RobotomyRequestForm::getTarget() const {
	return (this->_target);
}
