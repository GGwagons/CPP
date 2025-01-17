/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:09:44 by miturk            #+#    #+#             */
/*   Updated: 2024/11/11 17:01:00 by miturk           ###   ########.fr       */
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

AForm *Intern::robotomyForm(std::string const &target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::presidentialForm(std::string const &target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::shrubberyForm(std::string const &target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string const &name, std::string const &target) {
        FormType formTypes[] = {
			{"robotomy request", &robotomyForm},
			{"presidential pardon", &presidentialForm},
			{"shrubbery creation", &shrubberyForm}
        };
		for (size_t i = 0; i < sizeof(formTypes) / sizeof(FormType); ++i) {
            if (formTypes[i].formName == name) {
                std::cout << "Intern creates " << name << std::endl;
                return formTypes[i].create(target);
            }
        }
        std::cout << "Intern can't create " << name << std::endl;
        return NULL;
}
