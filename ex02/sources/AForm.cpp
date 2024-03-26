/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:42:22 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 22:25:53 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm(): _name("default"), _signed(false), _required_sign(150), _required_exec(150) {
	std::cout << CYAN << "AForm default created with lowest required grades ";
	std::cout << "(150) for signing and executing" << END_STYLE << std::endl;
}

AForm::AForm(const std::string name, const int required_sign, const int required_exec):
	_name(name), _signed(false), _required_sign(required_sign), _required_exec(required_exec) {
	if (required_sign < 1 || required_exec < 1)
		throw AForm::GradeTooHighException();
	else if (required_sign > 150 || required_exec > 150)
		throw AForm::GradeTooLowException();
	std::cout << CYAN << "AForm " << name << " created with required grade for signing: " << required_sign;
	std::cout << " and for executing: " << required_exec << END_STYLE << std::endl;
}

AForm::AForm(const AForm &cpy): _name(cpy.getName()), _signed(cpy.getSigned()),
		_required_sign(cpy.getRequiredSign()), _required_exec(cpy.getRequiredExec()) {
	std::cout << CYAN << "AForm " << cpy.getName();
	if (cpy.getSigned())
		std::cout << " (signed) with required grade ";
	else
		std::cout << " (not signed) with required grade ";
	std::cout << "for signing: " << cpy.getRequiredSign() << " and for executing: " << cpy.getRequiredExec();
	std::cout << " copied"<< END_STYLE << std::endl;	
}

AForm::~AForm() {
	std::cout << PURPLE << "AForm " << this->_name;
	if (this->_signed)
		std::cout << " (signed) with required grade ";
	else
		std::cout << " (not signed) with required grade ";
	std::cout << "for signing: " << this->_required_sign << " and for executing: " << this->_required_exec;
	std::cout << " destructed"<< END_STYLE << std::endl;	
}

AForm	&AForm::operator=(const AForm &rhs) {
	this->_signed = rhs._signed;
	std::cout << CYAN << "AForm " << rhs.getName();
	if (rhs.getSigned())
		std::cout << " (signed) with required grade ";
	else
		std::cout << " (not signed) with required grade ";
	std::cout << "for signing: " << rhs.getRequiredSign() << " and for executing: " << rhs.getRequiredExec();
	std::cout << " copied with assignment operator"<< END_STYLE << std::endl;	
	return (*this);
}

std::string	AForm::getName() const {
	return (this->_name);
}

bool	AForm::getSigned() const {
	return (this->_signed);
}

int	AForm::getRequiredSign() const {
	return (this->_required_sign);
}

int	AForm::getRequiredExec() const {
	return (this->_required_exec);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_required_sign)
		throw AForm::GradeTooLowException();
	if (this->getSigned())
		throw AForm::AlreadySignedException();
	this->_signed = true;
}

void	AForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->_required_exec)
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::NotSignedException();
	this->doExecute();
}

std::ostream	&AForm::print(std::ostream &o) const {
	if (this->getSigned())
		o << "AForm " << this->getName() << ", signed: yes";
	else
		o << "AForm " << this->getName() << ", signed: no";
	o << ", required for signing: " << this->getRequiredSign();
	o << ", required for executing: " << this->getRequiredExec();
	return (o);	
}

std::ostream	&operator<<(std::ostream &o, const AForm &form) {
	return (form.print(o));
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return ((char *)"Invalid grade: grade too high.");
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return ((char *)"Invalid grade: grade too low.");
}

const char	*AForm::NotSignedException::what() const throw() {
	return ((char *)"Unable to execute: form not signed.");
}

const char	*AForm::AlreadySignedException::what() const throw() {
	return ((char *)"Unable to sign form: form is already signed.");
}
