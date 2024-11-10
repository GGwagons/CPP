/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:09:54 by miturk            #+#    #+#             */
/*   Updated: 2024/11/10 13:21:45 by miturk           ###   ########.fr       */
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

class Intern {
	private:
		static AForm *createRobotomyRequestForm(std::string const &target);
		static AForm *createPresidentialPardonForm(std::string const &target);
		static AForm *createShrubberyCreationForm(std::string const &target);
	public:
		Intern();
		Intern(Intern const &copy);
		~Intern();
		Intern &operator=(Intern const &copy);
		AForm *makeForm(std::string const &name, std::string const &target);
};

#endif