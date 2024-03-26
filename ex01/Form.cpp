/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:42:22 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 17:14:46 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form(): _name("default"), _signed(false), _required_sign(150), _required_exec(150) {
	std::cout << CYAN << "Form default created with lowest required grades ";
	std::cout << "(150) for signing and executing" << END_STYLE << std::endl;
}

Form::Form(const std::string name, const int required_sign, const int required_exec):
	_name(name), _signed(false), _required_sign(required_sign), _required_exec(required_exec) {
	if (required_sign < 1 || required_exec < 1)
		throw Form::GradeTooHighException();
	else if (required_sign > 150 || required_exec > 150)
		throw Form::GradeTooLowException();
	std::cout << CYAN << "Form " << name << " created with required grade for signing: " << required_sign;
	std::cout << " and for executing: " << required_exec << END_STYLE << std::endl;
}

Form::Form(const Form &cpy): _name(cpy.getName()), _signed(cpy.getSigned()),
		_required_sign(cpy.getRequiredSign()), _required_exec(cpy.getRequiredExec()) {
	std::cout << CYAN << "Form " << cpy.getName();
	if (cpy.getSigned())
		std::cout << " (signed) with required grade ";
	else
		std::cout << " (not signed) with required grade ";
	std::cout << "for signing: " << cpy.getRequiredSign() << " and for executing: " << cpy.getRequiredExec();
	std::cout << " copied"<< END_STYLE << std::endl;	
}

Form::~Form() {
	std::cout << PURPLE << "Form " << this->_name;
	if (this->_signed)
		std::cout << " (signed) with required grade ";
	else
		std::cout << " (not signed) with required grade ";
	std::cout << "for signing: " << this->_required_sign << " and for executing: " << this->_required_exec;
	std::cout << " destructed"<< END_STYLE << std::endl;	
}

Form	&Form::operator=(const Form &rhs) {
	this->_signed = rhs._signed;
	std::cout << CYAN << "Form " << rhs.getName();
	if (rhs.getSigned())
		std::cout << " (signed) with required grade ";
	else
		std::cout << " (not signed) with required grade ";
	std::cout << "for signing: " << rhs.getRequiredSign() << " and for executing: " << rhs.getRequiredExec();
	std::cout << " copied with assignment operator"<< END_STYLE << std::endl;	
	return (*this);
}

std::string	Form::getName() const {
	return (this->_name);
}

bool	Form::getSigned() const {
	return (this->_signed);
}

int	Form::getRequiredSign() const {
	return (this->_required_sign);
}

int	Form::getRequiredExec() const {
	return (this->_required_exec);
}

void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_required_sign)
		throw Form::GradeTooLowException();
	if (this->getSigned())
		throw Form::AlreadySignedException();
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &o, const Form &form) {
	if (form.getSigned())
		o << "Form " << form.getName() << ", signed: yes";
	else
		o << "Form " << form.getName() << ", signed: no";
	o << ", required for signing: " << form.getRequiredSign();
	o << ", required for executing: " << form.getRequiredExec();
	return (o);
}

char	*Form::GradeTooHighException::what() const throw() {
	return ((char *)"Invalid grade: grade too high.");
}

char	*Form::GradeTooLowException::what() const throw() {
	return ((char *)"Invalid grade: grade too low.");
}

char	*Form::AlreadySignedException::what() const throw() {
	return ((char *)"Unable to sign form: form is already signed.");
}
