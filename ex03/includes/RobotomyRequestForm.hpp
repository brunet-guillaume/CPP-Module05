/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:54:02 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 22:32:12 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		const std::string _target;
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);

		~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);

		void			doExecute() const;
		std::string		getTarget() const;
		std::ostream	&print(std::ostream &o) const;
};

#endif
