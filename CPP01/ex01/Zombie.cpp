/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 09:41:36 by miturk            #+#    #+#             */
/*   Updated: 2024/10/17 18:51:41 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name), _index() {
	std::cout << _name << " is born" << std::endl;
};

Zombie::Zombie() : _name("Fred"), _index() {
	std::cout << _name << " is born" << std::endl;
};

Zombie::~Zombie() {
	std::cout << _name << " " << _index << " is dead" << std::endl;
};

void Zombie::setName(std::string name) {
	_name = name;
}

void Zombie::setIndex(int index) {
	_index = index;
}

void Zombie::announce(void) {
	std::cout << _name << " " << _index << " BraiiiiiiinnnzzzZ..." << std::endl;
}
