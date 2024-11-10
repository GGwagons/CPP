/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:12:50 by miturk            #+#    #+#             */
/*   Updated: 2024/11/10 11:54:40 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	std::string input(argv[1]);
	if (argc != 2) {
		std::cout << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	ScalarConverter con(input);
	return 0;
}