/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:32:44 by miturk            #+#    #+#             */
/*   Updated: 2024/10/31 09:27:49 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unknown") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type) {
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy) {
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return *this;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::setType(const std::string &type) {
	_type = type;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Unknown animal sound" << std::endl;
}