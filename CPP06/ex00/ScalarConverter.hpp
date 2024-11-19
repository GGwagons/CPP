/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:18:36 by miturk            #+#    #+#             */
/*   Updated: 2024/11/18 12:48:07 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdlib>

#define INF "+inf"
#define	NINF "-inf"
#define NAN "nan"
#define IM "impossible"
#define N "Non displayable"

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
void isString(const std::string &input);

#endif