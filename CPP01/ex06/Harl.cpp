/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:18:31 by miturk            #+#    #+#             */
/*   Updated: 2024/10/18 13:10:57 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl; 
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl; 
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable. I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

int Harl::getLevel(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			return i;
		}
	}
	return -1;
}

typedef void (Harl::*complaints)(void);

void Harl::complain(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	complaints comp[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int lvl = getLevel(level);
	switch (lvl) {
	case 0:
		for (int i = lvl; i < 4; i++) {
			(this->*comp[i])();
		}
		break;
	case 1:
		for (int i = lvl; i < 4; i++) {
			(this->*comp[i])();
		}
		break;
	case 2:
		for (int i = lvl; i < 4; i++) {
			(this->*comp[i])();
		}
		break;
	case 3:
		(this->*comp[3])();
		break;
	default:
		break;
	}
	if (lvl == -1)
		std::cout << "[ Probably complaining about insignificant problem ]" << std::endl;
}