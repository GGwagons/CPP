/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:18:34 by miturk            #+#    #+#             */
/*   Updated: 2024/11/11 16:37:17 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _input("What") {
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string &input) : _input(input) {
	std::cout << "Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &copy)
		_input = copy._input;
	return (*this);
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor called" << std::endl;
}

void ScalarConverter::toChar(std::string &input) {
	std::cout << "char: ";
}

void ScalarConverter::toInt(std::string &input) {
	std::cout << "int: ";
}

void ScalarConverter::toFloat(std::string &input) {
	std::cout << "float: ";
}

void ScalarConverter::toDouble(std::string &input) {
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '.')
			std::cout << "double: ";
	}
	std::cout << "double: ";
}

void ScalarConverter::convert(std::string &input) {
	std::cout << "convert called" << std::endl;
	ScalarConverter::toChar(input);
	ScalarConverter::toInt(input);
	ScalarConverter::toFloat(input);
	ScalarConverter::toDouble(input);
}
