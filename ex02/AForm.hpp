/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:39:44 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 13:50:12 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "style.h"
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_required_sign;
		const int			_required_exec;
	public:
		AForm();
		AForm(const std::string name, const int required_sign, const int required_exec);
		AForm(const AForm &cpy);
		virtual	~AForm();

		AForm &operator=(const AForm &rhs);
		
		std::string				getName() const;
		bool					getSigned() const;
		int						getRequiredSign() const;
		int						getRequiredExec() const;
		void					beSigned(const Bureaucrat &bureaucrat);
		void					execute(const Bureaucrat &executor) const;
		virtual std::ostream	&print(std::ostream &o) const;
		virtual void			doExecute() const = 0;

		class GradeTooHighException: public std::exception {
			public:
				char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				char* what() const throw();
		};
		class NotSignedException: public std::exception {
			public:
				char* what() const throw();
		};
		class AlreadySignedException: public std::exception {
			public:
				char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const AForm &form);

#endif
