/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:17:40 by miturk            #+#    #+#             */
/*   Updated: 2024/11/08 19:13:11 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PRESIDENT", 25, 5) {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PRESIDENT", 25, 5) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy) {
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	if (this != &copy) {
		_target = copy._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getSigned()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}