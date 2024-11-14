/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:18:36 by miturk            #+#    #+#             */
/*   Updated: 2024/11/14 17:47:23 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>

class ScalarConverter {
	private:
		std::string _input;
		static void toChar(std::string &input);
		static void toInt(std::string &input);
		static void toFloat(std::string &input);
		static void toDouble(std::string &input);
	public:
		ScalarConverter();
		ScalarConverter(std::string &input);
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		static void convert(std::string &input);
};
#endif