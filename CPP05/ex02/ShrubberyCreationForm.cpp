/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:16:28 by miturk            #+#    #+#             */
/*   Updated: 2024/11/08 19:23:13 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SHRUB", 145, 137) {
// 	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
// }

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("SHRUB", 145, 137) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy) {
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &copy) {
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
	}
	file << "     ~_--_~" << std::endl;
	file << "  ~/~ ~  ~ ~\\" << std::endl;
	file << "~/~~    ~    ~~\\" << std::endl;
	file << "{   ~      ~    }" << std::endl;
	file << " {   ~  ~      }" << std::endl;
	file << "  {\\    ~  //}" << std::endl;
	file << "  ~ \\     // ~" << std::endl;
	file << "- -  \\| |//  _- _" << std::endl;
	file << "  -    | |  - " << std::endl;
	file << " _ -  / . \\ - _" << std::endl;
	file << "     / /\\  \\" << std::endl;
	file.close();
}

std::string ShrubberyCreationForm::getTarget() const {
	return (_target);
}

// std::ofstream &operator<<(std::ofstream &file, ShrubberyCreationForm const &forma) {
// 	std::string const filename = forma.getTarget() + "_shrubbery";
// 	if (!file) {
// 		std::cerr << "Error: file not opened" << std::endl;
// 		return (file);
// 	}
// 	file << "     ~_--_~" << std::endl;
// 	file << "  ~/~ ~  ~ ~\\" << std::endl;
// 	file << "~/~~    ~    ~~\\" << std::endl;
// 	file << "{   ~      ~    }" << std::endl;
// 	file << " {   ~  ~      }" << std::endl;
// 	file << "  {\\    ~  //}" << std::endl;
// 	file << "  ~ \\     // ~" << std::endl;
// 	file << "- -  \\| |//  _- _" << std::endl;
// 	file << "  -    | |  - " << std::endl;
// 	file << " _ -  / . \\ - _" << std::endl;
// 	file << "     / /\\  \\" << std::endl;
// 	file.close();
// 	return (file);
// }