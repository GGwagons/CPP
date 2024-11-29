/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:57:33 by miturk            #+#    #+#             */
/*   Updated: 2024/10/28 11:48:47 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void testClapTrap(ClapTrap *claptrap, const std::string &target) {
    claptrap->attack(target);
    claptrap->takeDamage(0);
    claptrap->beRepaired(5);
    std::cout << std::endl;
    delete claptrap;
}

int main() {

	ClapTrap claptrap("THE CLAPTOR");
	claptrap.attack("POOR SUCKER");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);
	std::cout << std::endl;
	std::cout << std::endl;
    ClapTrap *clap = new ClapTrap("THE CLAP");
    testClapTrap(clap, "CIVILIAN");
    return 0;
}