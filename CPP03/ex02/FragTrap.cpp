/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:08:03 by miturk            #+#    #+#             */
/*   Updated: 2024/10/28 13:23:54 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap") {
	std::cout << "FragTrap default constructor" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	std::cout << "FragTrap name constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
	if (this == &copy)
		return *this;
	std::cout << _name << " assignation operator called" << std::endl;
	_name = copy._name;
	_attackDamage = copy._attackDamage;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << _name << " wants to get a High Five" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (_attackDamage < 0) {
		std::cout << "You can't attack with negative damage!" << std::endl;
		return;
	}
	if (_energyPoints != 0) {
		_energyPoints -= 1;
		std::cout <<"FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		std::cout << _name << " has " << _energyPoints << " energy points!" << std::endl;
	}
	else {
		std::cout << _name << " has no energy points!" << std::endl;
	}
}