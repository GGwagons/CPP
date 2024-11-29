/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:40:01 by miturk            #+#    #+#             */
/*   Updated: 2024/10/17 18:36:21 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	std::cout << _name << " was created" << std::endl;
};

HumanA::~HumanA() {
	std::cout << _name << " was destroyed" << std::endl;
};

void HumanA::attack() const{
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}