/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:49:32 by miturk            #+#    #+#             */
/*   Updated: 2024/10/04 16:20:21 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	_name = "        ";
	_lastName = "        ";
	_nickName = "        ";
	_num = "        ";
	_darkestSecrets = "        ";
}

Contact::~Contact() {}

void Contact::setName(std::string name) {
	_name = name;
}

void Contact::setLastName(std::string lastName) {
	_lastName = lastName;
}

void Contact::setNickName(std::string nickName) {
	_nickName = nickName;
}

void Contact::setNum(std::string num) {
	_num = num;
}

void Contact::setDarkestSecrets(std::string darkestSecrets) {
	_darkestSecrets = darkestSecrets;
}

void	Contact::printLine() {
	if (_name.length() > 9)
		std::cout << _name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << _name << "|";
	if (_lastName.length() > 9)
		std::cout << _lastName.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << _lastName << "|";
	if (_nickName.length() > 9)
		std::cout << _nickName.substr(0, 9) << ".|" << std::endl;
	else
		std::cout << std::setw(10) << _nickName << "|" << std::endl;
}

void	Contact::printContact() {
		std::cout << "Name:            " << _name << std::endl;
		std::cout << "Last Name:       " << _lastName << std::endl;
		std::cout << "Nick Name:       " << _nickName << std::endl;
		std::cout << "Number:          " << _num << std::endl;
		std::cout << "Darkest Secrets: " << _darkestSecrets << std::endl;
}