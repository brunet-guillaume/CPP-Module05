/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:10:21 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 16:49:56 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "style.h"
# include "AForm.hpp"

class	Intern {
	private:

	public:
		Intern();
		Intern(const Intern &cpy);
		~Intern();

		Intern &operator=(const Intern &rhs);

		AForm	*makeForm(const std::string form_name, const std::string form_target);
};

enum e_form_name {
	SHRUBBERY_CREATION = 0,
	ROBOTOMY_REQUEST = 1,
	PRESIDENTIAL_PARDON = 2,
	NONE = 3
};

enum e_form_name	form_type(const std::string str);

#endif
