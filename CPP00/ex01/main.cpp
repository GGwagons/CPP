/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:49:19 by miturk            #+#    #+#             */
/*   Updated: 2024/10/05 15:56:55 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void	start_print() {
	std::cout << "WELCOME TO THE PHONEBOOK" << std::endl << std::endl;
	std::cout << "\t \"ADD\" \n   save a new contact\n" << std::endl;
	std::cout << "\t\"SEARCH\" \n display specific contact\n" << std::endl;
	std::cout << "\t \"EXIT\" \n  exit the PhoneBook\n" << std::endl;
}

std::string mega(const std::string &str) {
	std::string result;
	for (size_t i = 0; str[i]; i++) {
		result += std::toupper(str[i]);
	}
	return result;
}

int	main() {
	PhoneBook mBook;
	std::string input;
	start_print();
	while (std::cin) {
		input.clear();
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (1);
		input = mega(input);
		if (input == "EXIT")
			return (1);
		else if (input == "ADD")
			mBook.add();
		else if (input == "SEARCH") {
			mBook.search();
		}
	}
	return (0);
}