/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:18:34 by miturk            #+#    #+#             */
/*   Updated: 2024/11/14 19:02:41 by miturk           ###   ########.fr       */
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
	int i = -1;
	int res = 0;
	int sign = 1;
	if (i++, input[0] == '-') {
		sign = sign * -1;
	}
	for (;i < input.length() && isdigit(input[i]); i++) {
		res = res * 10 + input[i] - '0';
	}
	res = res * sign;
	std::cout << "int: " << res << std::endl;
}

void ScalarConverter::toFloat(std::string &input) {
	std::cout << "float: ";
}

void ScalarConverter::toDouble(std::string &input) {
	double res, res1, res2  = 0.0;
	int x, i, j = 0;
	int sign = 1;
	if (input[0] == '-'){
		sign = sign * -1;
		x++;
	}
	for (; x < input.length(); x++) {
		if (isdigit(input[x])) {
			res1 = res1 * 10.0 + (input[x] - '0'); 
		}
		else
			break;
	}
	if (input[x] == '.'){
		x++;
		for (; x < input.length() &&  isdigit(input[x]); x++) {
			res2 = res2 * 10.0 + (input[x] - '0');
			i++;
		}
	}
	for (; j < i; j++) {
		res2 /= 10.0;
	}

	res = (res1 + res2) * sign;
	std::cout << "double: " << res << std::endl;
}

void ScalarConverter::convert(std::string &input) {
	std::cout << "convert called" << std::endl;
	for (int i = 0; i < input.length(); i++) {
		if (input.find(".") && input[input.length()] == 'f') // this is still wrong...
			ScalarConverter::toDouble(input);
	}
	ScalarConverter::toChar(input);
	ScalarConverter::toInt(input);
	ScalarConverter::toFloat(input);
	ScalarConverter::toDouble(input);
}
