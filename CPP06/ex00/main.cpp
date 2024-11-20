/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:12:50 by miturk            #+#    #+#             */
/*   Updated: 2024/11/17 14:33:34 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	std::string input(argv[1]);
	if (input.length() == 0) {
		std::cerr << "Empty input" << std::endl;
		return (1);
	}
	if (input.empty()) {
		std::cerr << "Invalid input" << std::endl;
		return (1);
	}
	ScalarConverter::convert(input);
	return 0;
}
