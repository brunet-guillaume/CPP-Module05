/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:35:47 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/26 22:26:53 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string _target;
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &cpy);

		~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &rhs);

		void			doExecute() const;
		std::string		getTarget() const;
		std::ostream	&print(std::ostream &o) const;
};

#endif
