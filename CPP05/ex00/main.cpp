/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   main.cpp	   :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: miturk <miturk@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2024/11/06 10:17:29 by miturk	#+#	#+#	 */
/*   Updated: 2024/11/06 11:49:43 by miturk	   ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("b1", 5);
		std::cout << b1 << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &exe) {
	std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &exe) {
	std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	// This will throw an exception
	std::cout << std::endl;
	try {
		Bureaucrat b2("b2", 152);
		std::cout << b2 << std::endl;
		std::cout << "Before increment: " << b2 << std::endl;
		b2.decrementGrade();
		std::cout << "After increment: " << b2 << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat b3("b3", 150);
		std::cout << b3 << std::endl;
		std::cout << "Before increment: " << b3 << std::endl;
		b3.incrementGrade();
		std::cout << "After increment: " << b3 << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat b4("b4", 1);
		std::cout << b4 << std::endl;
		std::cout << "Before increment: " << b4 << std::endl;
		b4.incrementGrade(); // This will throw an exception
		std::cout << "After increment: " << b4 << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat b5("b5", 150);
		std::cout << b5 << std::endl;
		std::cout << "Before decrement: " << b5 << std::endl;
		b5.decrementGrade(); // This will throw an exception
		std::cout << "After decrement: " << b5 << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	std::cout << std::endl;
	Bureaucrat *b6;
	try {
		b6 = new Bureaucrat("b6", 149);
		std::cout << *b6 << std::endl;
		std::cout << "Before decrement: " << *b6 << std::endl;
		b6->decrementGrade(); // This will throw an exception
		std::cout << "After decrement: " << *b6 << std::endl;
		delete b6;
	}
	catch (const Bureaucrat::GradeTooHighException &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
		delete b6;
	}
	catch (const Bureaucrat::GradeTooLowException &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
		delete b6;
	}
	std::cout << std::endl;
	Bureaucrat *b7;
	try {
		b7 = new Bureaucrat();
		std::cout << *b7 << std::endl;
		std::cout << "Before decrement: " << *b7 << std::endl;
		b7->decrementGrade(); // This will throw an exception
		std::cout << "After decrement: " << *b7 << std::endl;
		delete b7;
	}
	catch (const Bureaucrat::GradeTooHighException &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
		delete b7;
	}
	catch (const Bureaucrat::GradeTooLowException &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
		delete b7;
	}
	std::cout << std::endl;
	return 0;
}