/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:57:33 by miturk            #+#    #+#             */
/*   Updated: 2024/10/28 15:05:47 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void testFragTrap(FragTrap &frag, const std::string &target) {
    frag.attack(target);
    frag.takeDamage(100);
    frag.beRepaired(80);
    frag.highFivesGuys();
    std::cout << std::endl;
}

void testScavTrap(ScavTrap &scav, const std::string &target) {
	scav.attack(target);
	scav.takeDamage(20);
	scav.beRepaired(80);
	scav.guardGate();
	std::cout << std::endl;
}

void testClapTrap(ClapTrap &claptrap, const std::string &target) {
    claptrap.attack(target);
    claptrap.takeDamage(100);
    claptrap.beRepaired(20);
    std::cout << std::endl;
}

int main() {
    {
	ClapTrap clap1 ("Clapy");
    testClapTrap(clap1, "Target_3");
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
	
	{
	ScavTrap scav("Scavy");
	testScavTrap(scav, "Target_2");
	}

	std::cout << std::endl;
	std::cout << std::endl;

	FragTrap fragy;
	testFragTrap(fragy, "Target_1");
	
	std::cout << std::endl;
	std::cout << std::endl;
	
	FragTrap fragie("Fragie");
    testFragTrap(fragie, "Target_1.1");

    return 0;
}