/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:18:36 by miturk            #+#    #+#             */
/*   Updated: 2024/11/10 11:49:07 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter {
	private:
		std::string _input;
	public:
		ScalarConverter();
		ScalarConverter(std::string &input);
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
};
#endif