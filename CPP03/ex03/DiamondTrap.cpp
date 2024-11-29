/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:13:12 by miturk            #+#    #+#             */
/*   Updated: 2024/10/27 13:19:09 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap constructor with name" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ScavTrap(copy), FragTrap(copy) {
	std::cout << "DiamondTrap copy constructor" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy) {
	std::cout << "DiamondTrap assignation operator" << std::endl;
	_name = copy._name;
	_attackDamage = copy._attackDamage;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}