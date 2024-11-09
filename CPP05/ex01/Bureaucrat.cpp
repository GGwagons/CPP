/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:19:17 by miturk            #+#    #+#             */
/*   Updated: 2024/11/09 18:45:51 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("SOMEONE"), _grade(150) {
	std::cout << "Default constructor called" << std::endl;	
}

Bureaucrat:: Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade) {
	std::cout << "Constructor with parameters called" << std::endl;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &copy) {
		_grade = copy._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();	
	}
	_grade -= 1;
	std::cout << _name << "Grade incremented" << std::endl;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade += 1;
	std::cout << _name << "Grade decremented" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &biro) {
	out << biro.getName() << ", bureaucrat grade " << biro.getGrade();
	return (out);
}

void Bureaucrat::signForm(Form &form) const {
	try {
		form.beSigned(*this);
	}
	catch (std::exception &exe) {
		std::cerr << exe.what() << std::endl;
	}
}