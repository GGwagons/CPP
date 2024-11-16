/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:18:34 by miturk            #+#    #+#             */
/*   Updated: 2024/11/16 21:29:10 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <cstdlib>

const int IMAX = std::numeric_limits<int>::max();
const int IMIN = std::numeric_limits<int>::min();
const double DMAX = std::numeric_limits<double>::max();
const double DMIN = -std::numeric_limits<double>::max();
const double FMAX = std::numeric_limits<double>::max();
const double FMIN = -std::numeric_limits<double>::max();

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

long long ft_atoi(const std::string &input) {
	unsigned int y = 0;
	int sign = 1;
	long long x = 0;
	if (input[y] == '-') {
		sign = sign * -1;
		y++;
	}
	for (; y < input.length() && isdigit(input[y]); y++) {
		x = x * 10 + input[y] - '0';
	}
	return (x = x * sign);
}

// double ft_deci(const std::string &input) {
// 	double d;
// 	double res1;
// 	double res2;
// }

void toInt(const std::string &input) {
	std::cout << "-----> INT" << std::endl;
	long long x = 0;
	int i = 0;
	x = ft_atoi(input);
	if (x > IMAX || x < IMIN) {
		std::cout << "Int: impossible" << std::endl;
	}
	else {
		i = static_cast<int>(x);
		std::cout << "Int: " << i << std::endl;
		if (isprint(i)) {
			char c = static_cast<char>(i);
			std::cout << "Char: " << c << std::endl;
		}
		else {
			std::cout << "Char: impossible" << std::endl;
		}
		double d = static_cast<double>(i);
		std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
		float f = static_cast<float>(i);
		std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	}
}

void toChar(const std::string &input) {
	std::cout << "-----> CHAR" << std::endl;
	char c = static_cast<char>(input[0]);
	std::cout << "Char: " << c << std::endl;
	int i = static_cast<int>(c);
	std::cout << "Int: " << i << std::endl;
	double d = static_cast<double>(c);
	std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
	float f = static_cast<float>(c);
	std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void toDouble(const std::string &input) {
	std::cout << "-----> DOUBLE" << std::endl;
	double d;
	double sign = 1;
	double res = 0;
	unsigned int i = 0;
	std::stringstream ss(input);
	ss >> d;
	if (ss.fail() || d > DMAX || d < DMIN) {
		std::cout << "THis is shit" << std::endl;
		return;
	}
	if (input[0] == '-') {
		sign = sign * -1;
		i++;
	}
	for (; i < input.length() && isdigit(input[i]); i++) {
		res = res * 10 + input[i] - '0';
	}
	res = res * sign;
}

void toFloat(const std::string &input) {
	std::cout << "-----> FLOAT" << std::endl;
	float f;
	int sign = 1;
	int res = 0;
	unsigned int i = 0;
	double temp;
	std::stringstream ss(input);
	ss >> temp;
	if(ss.fail() || temp > FMAX || temp < FMIN) {
		std::cout << "This is also shit" << std::endl;
		return;
	}
	if (input[0] == '-') {
		sign = sign * -1;
		i++;
	}
	for (; i < input.length() && isdigit(input[i]); i++) {
		res = res * 10 + input[i] - '0';
	}
	res = res * sign;
	f = static_cast<float>(res) / (1 << 8);
}

void isString(const std::string &input) {
	(void)input;
	std::cout << "-----> STRING" << std::endl;
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
			if (input.find("f") == (input.length() - 1) && ( input.find(".") != std::string::npos)) {
				flag = 4;
			}
			if (input.find("f") == std::string::npos && input.find(".") != std::string::npos) {
				flag = 3;
			}
		}
		else {
			flag = 5;
		}
	}
	return flag;
}

void ScalarConverter::convert(const std::string &input) {
	std::cout << "----------THE CONVERTER----------" << std::endl;
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
		default :
			std::cout << "Working on it" << std::endl;
	}
}
