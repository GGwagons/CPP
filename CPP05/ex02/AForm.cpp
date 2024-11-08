/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:29:32 by miturk            #+#    #+#             */
/*   Updated: 2024/11/08 12:10:53 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("SOMEONE"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "AForm constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException();
	if (_gradeToSign < _gradeToExecute)
		throw Bureaucrat::GradeTooLowException();
	_signed = false;
}

AForm::AForm(AForm const &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &copy) {
	std::cout << "AForm assignation operator called" << std::endl;
	if (this != &copy) {
		_signed = copy._signed;
	}
	return (*this);
}

std::string AForm::getName() const {
	return (_name);
}

bool AForm::getSigned() const {
	return (_signed);
}

int AForm::getGradeToSign() const {
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const {
	return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat const &buro) {
	if (buro.getGrade() > _gradeToSign) {
		_signed = true;
	}
	else {
		throw AForm::FormNotSignedException();
	}
}

void AForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > _gradeToExecute) {
		std::cout << "AForm " << _name << " cannot be executed by " << executor.getName() << ". Required grade " << getGradeToExecute() << std::endl;
	}
	else
		std::cout << "AForm " << _name << " executed by " << executor.getName() << std::endl;
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("AForm is not signed");
}

const char *AForm::FormSignedException::what() const throw() {
	return ("AForm is signed");
}

std::ostream &operator<<(std::ostream &out, AForm const &Aform) {
	out << "AForm " << Aform.getName() << " is ";
	if (Aform.getSigned()) {
		out << "signed";
	}
	else {
		out << "not signed" << " and requires grade " << Aform.getGradeToSign() << " to sign and grade " << Aform.getGradeToExecute() << " to execute";
	}
	return (out);
}