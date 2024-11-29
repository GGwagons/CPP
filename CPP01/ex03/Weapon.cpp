/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:40:33 by miturk            #+#    #+#             */
/*   Updated: 2024/10/17 18:21:51 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type("crude spike club") {
	std::cout << "Weapon " << _type << " created" << std::endl;
};

Weapon::Weapon(std::string type) : _type(type) {
	std::cout << "Weapon " << _type << " created" << std::endl;
};

Weapon::~Weapon() {
	std::cout << "Weapon " << _type << " destroyed" << std::endl;
};

std::string const &Weapon::getType() {
	return (_type);
}

void Weapon::setType(std::string type) {
	_type = type;
}