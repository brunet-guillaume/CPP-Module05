/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:39:44 by gbrunet           #+#    #+#             */
/*   Updated: 2024/02/23 18:49:26 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "style.h"
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_required_sign;
		const int			_required_exec;
	public:
		Form();
		Form(const std::string name, const int required_sign, const int required_exec);
		Form(const Form &cpy);
		~Form();

		Form &operator=(const Form &rhs);
		
		std::string	getName() const;
		bool	getSigned() const;
		int	getRequiredSign() const;
		int	getRequiredExec() const;
		void	beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException: public std::exception {
			public:
				char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Form &form);

#endif
