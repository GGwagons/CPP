/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:09:54 by miturk            #+#    #+#             */
/*   Updated: 2024/11/11 12:08:25 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

struct FormType {
	std::string formName;
	AForm* (*create)(std::string const &target);
};

class Intern {
	private:
		static AForm *robotomyForm(std::string const &target);
		static AForm *presidentialForm(std::string const &target);
		static AForm *shrubberyForm(std::string const &target);
	public:
		Intern();
		Intern(Intern const &copy);
		~Intern();
		Intern &operator=(Intern const &copy);
		AForm *makeForm(std::string const &name, std::string const &target);
};

#endif