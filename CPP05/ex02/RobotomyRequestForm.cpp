/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:17:51 by miturk            #+#    #+#             */
/*   Updated: 2024/11/08 19:24:51 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("ROBOT", 72, 45) {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("ROBOT", 72, 45) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy) {
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this != &copy) {
		_target = copy._target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getSigned()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw Bureaucrat::GradeTooLowException();
	}
	srand(time(0));
	std::cout << "*drilling noises*" << std::endl;
	if (rand() % 2) {
		std::cout << _target << " has been robotomized successfully" << std::endl;
	}
	else {
		std::cout << _target << " has not been robotomized" << std::endl;
	}
}