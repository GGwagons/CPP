/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:08:03 by miturk            #+#    #+#             */
/*   Updated: 2024/10/27 12:22:09 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap") {
	std::cout << _name << " default constructor" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	std::cout << _name << " Name constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) {
	std::cout << _name << " copy constructor called" << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
	std::cout << _name << " assignation operator called" << std::endl;
	_name = copy._name;
	_attackDamage = copy._attackDamage;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << _name << " destructor" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << _name << " wants to get a High Five" << std::endl;
}