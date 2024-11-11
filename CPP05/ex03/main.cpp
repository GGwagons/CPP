/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:29:56 by miturk            #+#    #+#             */
/*   Updated: 2024/11/11 12:54:06 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	try {
		Bureaucrat b1("Steve", 24);
    	Intern someRandomIntern;
    	AForm *form;
		std::cout << b1 << std::endl;
		std::cout << "...Creating forms..." << std::endl;
		std::cout << std::endl;
		try {
			form = someRandomIntern.makeForm("robotomy request", "Bender");
			if (form) {
				b1.signForm(*form);
				std::cout << *form << " by " << b1.getName() << std::endl;
				b1.executeForm(*form);
				delete form;
			}
			std::cout << std::endl;
			form = someRandomIntern.makeForm("shrubbery creation", "home");
			if (form) {
				b1.signForm(*form);
				std::cout << *form << " by " << b1.getName() << std::endl;
				b1.executeForm(*form);
				delete form;
			}
			std::cout << std::endl;
			form = someRandomIntern.makeForm("presidential pardon", "Alice");
			if (form) {
				b1.signForm(*form);
				std::cout << *form << " by " << b1.getName() << std::endl;
				b1.executeForm(*form);
				delete form;
			}
		}
		catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
    return 0;
}