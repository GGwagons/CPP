/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:29:32 by miturk            #+#    #+#             */
/*   Updated: 2024/11/06 17:04:09 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("SOMEONE"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Form constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
	if (_gradeToSign < _gradeToExecute)
		throw Form::GradeTooLowException();
	_signed = false;
}

Form::Form(Form const &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(Form const &copy) {
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &copy) {
		_signed = copy._signed;
	}
	return (*this);
}

std::string Form::getName() const {
	return (_name);
}

bool Form::getSigned() const {
	return (_signed);
}

int Form::getGradeToSign() const {
	return (_gradeToSign);
}

int Form::getGradeToExecute() const {
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat const &buro) {
	if (buro.getGrade() > _gradeToSign) {
		throw Form::GradeTooLowException();
	}
	_signed = true;
}

void Form::execute(Bureaucrat const &executor) const {
	if (!_signed) {
		throw Form::FormNotSignedException();
	}
	if (executor.getGrade() > _gradeToExecute) {
		throw Form::GradeTooLowException();
	}
}

const char *Form::FormNotSignedException::what() const throw() {
	return ("Form is not signed");
}

const char *Form::FormSignedException::what() const throw() {
	return ("Form is signed");
}

std::ostream &operator<<(std::ostream &out, Form const &form) {
	out << "Form " << form.getName() << " is ";
	(form.getSigned()) ? out << "signed" : out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
	return (out);
}