/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:09:44 by miturk            #+#    #+#             */
/*   Updated: 2024/11/10 12:11:01 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &copy) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &copy) {
	std::cout << "Intern assignation operator called" << std::endl;
	if (this != &copy) {
	}
	return (*this);
}

AForm *Intern::makeForm(std::string const &name, std::string const &target) {
	if (name == "robotomy request") {
		std::cout << "Intern creates " << name << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (name == "presidential pardon") {
		std::cout << "Intern creates " << name << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else if (name == "shrubbery creation") {
		std::cout << "Intern creates " << name << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else {
		std::cout << "Intern can't create " << name << std::endl;
		return (NULL);
	}
}