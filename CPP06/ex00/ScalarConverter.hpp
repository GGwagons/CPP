/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:18:36 by miturk            #+#    #+#             */
/*   Updated: 2024/11/16 18:43:42 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
	public:
		static void convert(const std::string &input);
};

void Print(int i, char c, double d, float f);
int inputCheck(const std::string &input);
void toInt(const std::string &input);
void toChar(const std::string &input);
void toDouble(const std::string &input);
void toFloat(const std::string &input);
long long ft_atoi(const std::string &input);
void isString(const std::string &input);

#endif