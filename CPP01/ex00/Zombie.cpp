/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:08:20 by miturk            #+#    #+#             */
/*   Updated: 2024/10/19 12:47:25 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
}

Zombie::~Zombie() {
	std::cout << _name << " is destroyed" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << _name << ": Braiiiiiiinnnzzz" << std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
}
