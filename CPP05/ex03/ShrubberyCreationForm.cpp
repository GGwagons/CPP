/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:16:28 by miturk            #+#    #+#             */
/*   Updated: 2024/11/09 18:53:31 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SHRUB", 147, 137) {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("SHRUB", 147, 137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _target(copy._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy) {
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &copy) {
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getSigned()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw Bureaucrat::GradeTooLowException();
	}
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file) {
		std::cerr << "Error: file not opened" << std::endl;
		return ;
	}
    file << "       ccee88oo\n";
    file << "  C8O8O8Q8PoOb o8oo\n";
    file << " dOB69QO8PdUOpugoO9bD\n";
    file << "CgggbU8OU qOp qOdoUOdcb\n";
    file << "    6OuU  /p u gcoUodpP\n";
    file << "      \\\\//  /douUP\n";
    file << "        \\\\////\n";
    file << "         |||/\\\n";
    file << "         |||\\/\n";
    file << "         |||||\n";
    file << "   .....//||||\\....\n";
    file.close();
    std::cout << "File " << filename << " created successfully." << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
	return (_target);
}
