/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:49:30 by miturk            #+#    #+#             */
/*   Updated: 2024/10/05 19:11:33 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::_number(std::string &input) {
	for (size_t i = 0; input[i]; i++) {
		if (isdigit(input[i]) == 0 && input[i] != ' ') {
			std::cout << "Please enter a valid number" << std::endl;
			input.clear();
			std::getline(std::cin, input);
			if (std::cin.eof())
				return ;
			i = 0;
		}
	}
}

int PhoneBook::_justSpace(std::string &input) {
	int i = 0;
	int x = 0;
	while (input[i] != '\0') {
		if (input[i] == ' ')
			x++;
		i++;
	}
	if (x == i)
		return (0);
	return (1);
}

void	PhoneBook::_checkEmpty(std::string &input) {
	while (input.empty() || _justSpace(input) == 0) {
		std::cout << "Please enter a valid input" << std::endl;
		input.clear();
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
	}
}

int	PhoneBook::_isTab(int c) {
	if (c == '\t')
		return (0);
	return (1);
}

void	PhoneBook::_checkTab(std::string &input) {
	for (int i = 0; input[i] != '\0'; i++) {
		if (_isTab(input[i]) == 0) {
			std::cout << "Why are you using Tab in PhoneBook? Try again" << std::endl;
			input.clear();
			std::getline(std::cin, input);
			if (std::cin.eof())
				return ;
			i = 0;
		}
	}
}

void	PhoneBook::add() {
	std::cout << "Enter the following details: " << std::endl;
	std::string input;
	int i = _index % 8;

	input.clear();
	std::cout << "Name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	_checkEmpty(input);
	_checkTab(input);
	_contacts[i].setName(input);

	input.clear();
	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	_checkTab(input);
	_checkEmpty(input);
	_contacts[i].setLastName(input);

	input.clear();
	std::cout << "Nick Name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	_checkEmpty(input);
	_checkTab(input);
	_contacts[i].setNickName(input);

	input.clear();
	std::cout << "Number: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	_checkEmpty(input);
	_checkTab(input);
	_number(input);
	_contacts[i].setNum(input);

	input.clear();
	std::cout << "Darkest Secrets: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	_checkTab(input);
	_checkEmpty(input);
	_contacts[i].setDarkestSecrets(input);

	std::cout << "Contact added successfully" << std::endl;
	_index++;
}

void	PhoneBook::_printCheck(std::string &str) {
	_number(str);
	int i;
	std::stringstream ss(str);
	ss >> i;
	if (i > 0 && i < 9) {	
		if (i--, i >= 0 && i < 8 && i <= _index - 1) {
			_contacts[i].printContact();
		}
		else {
			std::cout << "Empty contact. Run \"SEARCH\", \"ADD\" or \"EXIT\""<< std::endl;
		}
	}
	else {
		std::cout << "Invalid input. Run \"SEARCH\", \"ADD\" or \"EXIT\"" << std::endl;
	}
}

void	PhoneBook::search() {
	std::cout << "––––––––––––––––––––––––––––––––––––––––––––" << std::endl;
	std::cout << "|  Index  |   First  |   Last   | nickname |" << std::endl;
	std::cout << "|         |    name  |    name  |          |" << std::endl;
	std::cout << "––––––––––––––––––––––––––––––––––––––––––––" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << "|" << std::setw(9) << i + 1 << "|";
		_contacts[i].printLine();
		std::cout << "––––––––––––––––––––––––––––––––––––––––––––" << std::endl;
	}
	std::cout << "Enter the index of the contact you want to see" << std::endl;
	std::string str;
	std::getline(std::cin, str);
	if (std::cin.eof())
		return ;
	_checkTab(str), _checkEmpty(str), _printCheck(str);
}