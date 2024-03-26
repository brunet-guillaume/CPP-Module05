/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:45:16 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 22:29:51 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150) {
	std::cout << CYAN << "Bureaucrat named Default created with lowest grade 150" << END_STYLE << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << CYAN << "Bureaucrat named " << name << " created with grade " << grade << END_STYLE << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy): _name(cpy.getName()), _grade(cpy.getGrade()) {
	std::cout << CYAN << "Bureaucrat named " << cpy.getName() << " with grade ";
	std::cout << cpy.getGrade() << " copied" << END_STYLE << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << PURPLE << "Bureaucrat named " << this->_name << " with grade ";
	std::cout << this->_grade << " destructed" << END_STYLE << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs) {
	this->_grade = rhs._grade;
	std::cout << CYAN << "Bureaucrat named " << rhs.getName() << " with grade ";
	std::cout << rhs.getGrade() << " copied with assignment operator" << END_STYLE << std::endl;
	return (*this);
}

std::string	Bureaucrat::getName() const {
	return (this->_name);
}

int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::incrementGrade() {
	if (this->_grade > 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &bureaucrat) {
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (o);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return ((char *)"Invalid grade: grade too high. Grade must be between 1 and 150");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return ((char *)"Invalid grade: grade too low. Grade must be between 1 and 150");
}
