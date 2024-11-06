/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:29:56 by miturk            #+#    #+#             */
/*   Updated: 2024/11/06 16:40:30 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

int main() {
    Bureaucrat john("John", 50);
    Bureaucrat jane("Jane", 150);
    Form formA("FormA", 100, 50);
    Form formB("FormB", 50, 25);
    try {
        std::cout << john << std::endl;
        std::cout << jane << std::endl;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
        // Attempt to sign formA with john (should succeed)
		std::cout << std::endl;
        formA.beSigned(john);
        std::cout << formA << std::endl;
		std::cout << std::endl;
        std::cout << "Attempt to sign formB with jane (should fail)" << std::endl;
        try {
            formB.beSigned(jane);
        }
		catch (const Form::GradeTooLowException &exe) {
            std::cerr << "Exception: " << exe.what() << std::endl;
        }
        std::cout << "Attempt to execute formA with jane (should fail)" << std::endl;
        try {
            formA.execute(jane);
        }
		catch (const Form::GradeTooLowException &exe) {
            std::cerr << "Exception: " << exe.what() << std::endl;
        }
        // Attempt to execute formA with john (should succeed)
        try {
            formA.execute(john);
            std::cout << "FormA executed by John" << std::endl;
        }
		catch (const Form::GradeTooLowException &exe) {
            std::cerr << "Exception: " << exe.what() << std::endl;
        }
        // Attempt to execute formB without signing (should fail)
        try {
            formB.execute(john);
        }
		catch (const Form::FormNotSignedException &exe) {
            std::cerr << "Exception: " << exe.what() << std::endl;
        }
    }
	catch (const Bureaucrat::GradeTooHighException &exe) {
        std::cerr << "Exception: " << exe.what() << std::endl;
    }
	catch (const Bureaucrat::GradeTooLowException &exe) {
        std::cerr << "Exception: " << exe.what() << std::endl;
    }
	std::cout << std::endl;
    return 0;
}
