/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:57:33 by miturk            #+#    #+#             */
/*   Updated: 2024/10/28 13:34:38 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void testScavTrap(ScavTrap &scavtrap, const std::string &target) {
    scavtrap.attack(target);
    scavtrap.takeDamage(20);
    scavtrap.beRepaired(80);
    scavtrap.guardGate();
    std::cout << std::endl;
}

int main() {
	{
	ClapTrap claptrap("Fred");
	claptrap.attack("Target");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	ScavTrap scav;
	testScavTrap(scav, "Target");
	
	std::cout << std::endl;

    ScavTrap scavtrap("Lulu Lemon");
    testScavTrap(scavtrap, "Target");

    return 0;
}