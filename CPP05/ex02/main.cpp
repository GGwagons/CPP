/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:29:56 by miturk            #+#    #+#             */
/*   Updated: 2024/11/09 19:02:29 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat bob("BOB", 1);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Alice");

        std::cout << bob << std::endl;
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        // Signing forms
        try {
			bob.signForm(shrubbery);
            // std::cout << "ShrubberyCreationForm signed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception during ShrubberyCreationForm signing: " << e.what() << std::endl;
        }
        try {
			bob.signForm(robotomy);
            // std::cout << "RobotomyRequestForm signed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception during RobotomyRequestForm signing: " << e.what() << std::endl;
        }

        try {
			bob.signForm(pardon);
            // std::cout << "PresidentialPardonForm signed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception during PresidentialPardonForm signing: " << e.what() << std::endl;
        }

        std::cout << shrubbery << " by " << bob.getName() << std::endl;
        std::cout << robotomy << " by " << bob.getName() << std::endl;
        std::cout << pardon << " by " << bob.getName() << std::endl;

        // Executing forms
        try {
            bob.executeForm(shrubbery);
			// shrubbery.execute(bob);
            // std::cout << "ShrubberyCreationForm executed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception during ShrubberyCreationForm execution: " << e.what() << std::endl;
        }

        try {
            bob.executeForm(robotomy);
			// robotomy.execute(bob);
            // std::cout << "RobotomyRequestForm executed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception during RobotomyRequestForm execution: " << e.what() << std::endl;
        }

        try {
            bob.executeForm(pardon);
			// pardon.execute(bob);
            std::cout << "PresidentialPardonForm executed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception during PresidentialPardonForm execution: " << e.what() << std::endl;
        }
    }
	catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}