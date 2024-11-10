/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:18:34 by miturk            #+#    #+#             */
/*   Updated: 2024/11/10 11:51:38 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _input("nanf") {
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