/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:29:56 by miturk            #+#    #+#             */
/*   Updated: 2024/11/09 11:05:01 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	try {
		try {
			Bureaucrat biroA("BiroA", 50);
			Form formA("FormA", 50, 49);
			std::cout << biroA << std::endl;
			std::cout << formA << std::endl;
			biroA.incrementGrade();
			formA.beSigned(biroA);
			biroA.signForm(formA);
			formA.execute(biroA);
			std::cout << biroA << std::endl;
			formA.execute(biroA);
		}
		catch (const std::exception &exe) {
			std::cerr << exe.what() << std::endl;
		}
	}
	catch (std::exception &exe) {
		std::cerr << exe.what() << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	try {
		try {
			Bureaucrat biroB("BiroB", 25);
			Form formB("FormB", 15, 10);
			std::cout << biroB << std::endl;
			std::cout << formB << std::endl;
			formB.beSigned(biroB);
			biroB.signForm(formB);
			formB.execute(biroB);
			biroB.incrementGrade();
			std::cout << biroB << std::endl;
			formB.execute(biroB);
		}
		catch (const std::exception &exe) {
			std::cerr << exe.what() << std::endl;
		}
	}
	catch (std::exception &exe) {
		std::cerr << exe.what() << std::endl;
	}
    return 0;
}
