/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:18:34 by miturk            #+#    #+#             */
/*   Updated: 2024/11/19 17:42:29 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define INT_OVERFLOW   INT_MAX
#define INT_UNDERFLOW  INT_MIN
#define FLOAT_OVERFLOW FLT_MAX
#define FLOAT_UNDERFLOW -FLT_MAX
#define DOUBLE_OVERFLOW DBL_MAX
#define DOUBLE_UNDERFLOW -DBL_MIN

ScalarConverter::ScalarConverter(){
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &copy) {};
	return (*this);
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor called" << std::endl;
}

void toInt(const std::string &input) {
	int i = 0;
	char c = '\0';
	double d = 0.0;
	float f = 0.0f;
	std::cout << "--> INT" << std::endl;
	std::stringstream ss(input);
	ss >> i;
	if (ss.fail()){
		if (i == INT_OVERFLOW) {
			std::cout << "Int: " << INF << std::endl;
			std::cout << "Char: " << N << std::endl;
		}
		else {
			std::cout << "Int: " << NINF << std::endl;
			std::cout << "Char: " << IM << std::endl;
		}
		std::stringstream ssD(input);
		ssD >> d;
		if (ssD.fail()) {
			if (d == DOUBLE_OVERFLOW) {
				std::cout << "Double: " << INF << std::endl;
				std::cout << "Float: " << INF << std::endl;
				return;
			}
			if (d == DOUBLE_UNDERFLOW) {
				std::cout << "Double: " << NINF << std::endl;
				std::cout << "Float: " << NINF << std::endl;
				return;
			}
		}
		std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
		f = static_cast<float>(i);
		std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	else {
		std::cout << "Int: " << i << std::endl;
		if (isascii(i) && isprint(i)) {std::cout << "Char: " << (c = static_cast<char>(i)) << std::endl;}
		else if(i >= 0) {std::cout << "Char: " << N << std::endl;}
		else {std::cout << "Char: " << IM << std::endl;}
		d = static_cast<double>(i);
		std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
		f = static_cast<float>(i);
		std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;	
	}
}

void toChar(const std::string &input) {
	std::cout << "--> CHAR" << std::endl;
	char c = static_cast<char>(input[0]);
	int i = static_cast<int>(c);
	std::cout << "Int: " << i << std::endl;
	std::cout << "Char: " << c << std::endl;
	double d = static_cast<double>(c);
	std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
	float f = static_cast<float>(c);
	std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void toDouble(const std::string &input) {
	std::cout << "--> DOUBLE" << std::endl;
	int i = 0;
	char c = '\0';
	double d = 0.0;
	float f = 0.0f;
	std::stringstream ss(input);
	ss >> d;
	if (ss.fail()) {
		std::stringstream ssI(input);
		ssI >> i;
		if (ssI.fail()){
			if (i == INT_OVERFLOW) {
				std::cout << "Int: " << INF << std::endl;
				std::cout << "Char: " << N << std::endl;
			}
			else {
				std::cout << "Int: " << NINF << std::endl;
				std::cout << "Char: " << N << std::endl;
			}
		}
		else {
			std::cout << "Int: " << i << std::endl;
			if (isascii(i) && isprint(i)) {std::cout << "Char: " << (c = static_cast<char>(i)) << std::endl;}
			else if(i >= 0) {std::cout << "Char: " << N << std::endl;}
			else {std::cout << "Char: " << IM << std::endl;}
		}
		if (d > DOUBLE_OVERFLOW) {
			std::cout << "Double: " << INF << std::endl;
			std::cout << "Float: " << INF << std::endl;

		}
		else {
			std::cout << "Double: " << NINF << std::endl;
			std::cout << "Float: " << NINF << std::endl;
		}
	}
	else {
		std::stringstream ssIi(input);
		ssIi >> i;
		if (ssIi.fail() || !ssIi.eof()){
			if (i == INT_OVERFLOW) {
				std::cout << "Int: " << INF << std::endl;
				std::cout << "Char: " << N << std::endl;
			}
			else if (i == INT_UNDERFLOW) {
				std::cout << "Int: " << NINF << std::endl;
				std::cout << "Char: " << IM << std::endl;
			}
		}
		else {
			i = static_cast<int>(d);
			std::cout << "Int: " << i << std::endl;
			if (isascii(i) && isprint(i)) {std::cout << "Char: " << (c = static_cast<char>(i)) << std::endl;}
			else if(i >= 0) {std::cout << "Char: " << N << std::endl;}
			else {std::cout << "Char: " << IM << std::endl;}
			f = static_cast<float>(d);
			std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
			std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
			return ;	
		}
	}
	i = static_cast<int>(d);
	std::cout << "Int: " << i << std::endl;
	if (isascii(i) && isprint(i)) {std::cout << "Char: " << (c = static_cast<char>(i)) << std::endl;}
	else if(i >= 0) {std::cout << "Char: " << N << std::endl;}
	else {std::cout << "Char: " << IM << std::endl;}
	f = static_cast<float>(d);
	std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	return ;
}

void toFloat(const std::string &input) {
	std::cout << "--> FLOAT" << std::endl;
		int i = 0;
	char c = '\0';
	double d = 0.0;
	float f = 0.0f;
	std::stringstream ss(input);
	ss >> f;
	if (ss.fail()) {
		std::stringstream ssI(input);
		ssI >> i;
		if (ssI.fail()){
			if (i == INT_OVERFLOW) {
				std::cout << "Int: " << INF << std::endl;
				std::cout << "Char: " << N << std::endl;
			}
			else {
				std::cout << "Int: " << NINF << std::endl;
				std::cout << "Char: " << N << std::endl;
			}
		}
		else {
			std::cout << "Int: " << i << std::endl;
			if (isascii(i) && isprint(i)) {std::cout << "Char: " << (c = static_cast<char>(i)) << std::endl;}
			else if(i >= 0) {std::cout << "Char: " << N << std::endl;}
			else {std::cout << "Char: " << IM << std::endl;}
		}
		if (d > FLOAT_OVERFLOW) {
			std::cout << "Double: " << INF << std::endl;
			std::cout << "Float: " << INF << std::endl;

		}
		else {
			std::cout << "Double: " << NINF << std::endl;
			std::cout << "Float: " << NINF << std::endl;
		}
	}
	else {
		std::stringstream ssIi(input);
		ssIi >> i;
		if (ssIi.fail() || !ssIi.eof()){
			if (i == INT_OVERFLOW) {
				std::cout << "Int: " << INF << std::endl;
				std::cout << "Char: " << N << std::endl;
			}
			else if (i == INT_OVERFLOW) {
				std::cout << "Int: " << NINF << std::endl;
				std::cout << "Char: " << IM << std::endl;
			}
		}
		else {
			i = static_cast<int>(f);
			std::cout << "Int: " << i << std::endl;
			if (isascii(f) && isprint(f)) {std::cout << "Char: " << (c = static_cast<char>(f)) << std::endl;}
			else if(f >= 0) {std::cout << "Char: " << N << std::endl;}
			else {std::cout << "Char: " << IM << std::endl;}
			f = static_cast<double>(f);
			std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
			std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
			return ;	
		}
	}
	i = static_cast<int>(f);
	std::cout << "Int: " << i << std::endl;
	if (isascii(f) && isprint(f)) {std::cout << "Char: " << (c = static_cast<char>(f)) << std::endl;}
	else if(f >= 0) {std::cout << "Char: " << N << std::endl;}
	else {std::cout << "Char: " << IM << std::endl;}
	d = static_cast<double>(f);
	std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	return ;
}



void isString(const std::string &input) {
	std::cout << "--> STRING" << std::endl;
	if (input == NAN) {
		std::cout << "Int: " << IM << std::endl;
		std::cout << "Char: " << IM << std::endl;
		std::cout << "Double: " << NAN << std::endl;
		std::cout << "Float: " << NAN << "f" << std::endl;
	}
	else {
		std::cout << "Int: " << IM << std::endl;
		std::cout << "Char: " << IM << std::endl;
		std::cout << "Double: " << IM << std::endl;
		std::cout << "Float: " << IM << std::endl;
	}
}

int inputCheck(const std::string &input) {
	int flag = 0;
	unsigned int i = 0;
	int sign = 0;
	if (input[i] == '-' || input[i] == '+') {
		flag = 2;
		i++;
	}
	sign = i;
	for (;i < input.length() && isdigit(input[i]); i++) {
		if (i + 1 == input.length()) {
			return flag = 1;
		}
	}
	i = sign;
	for (; i < input.length(); i++) {
		if (input.length() == 1 && (isalpha(input[i]) || isascii(input[i]))) {
			 return flag = 2;
		}
		else if (input.length() > 1) {
			flag = 5;
		}
	}
	i = sign;
	for (; i < input.length(); i++) {
		if (isdigit(input[i]) || input[i] == '.' || input[i] == 'f') {
			if (input.find("f") == (input.length() - 1) && ( input.find(".") != std::string::npos)) { flag = 4;}
			if (input.find("f") == std::string::npos && input.find(".") != std::string::npos && input.find_first_of(".") == input.find_last_of(".")) {
				flag = 3;
			}
		}
		else {flag = 5;}
	}
	return flag;
}

void ScalarConverter::convert(const std::string &input) {
	std::cout << "-------THE CONVERTER----------" << std::endl;
	std::cout << "|" << std::endl;
	switch (inputCheck(input)) {
		case 1:
			toInt(input);
			break;
		case 2:
			toChar(input);
			break;
		case 3:
			toDouble(input);
			break;
		case 4:
			toFloat(input);
			break;
		case 5:
			isString(input);
			break;
		default :
			std::cout << "Working on it" << std::endl;
	}
}
