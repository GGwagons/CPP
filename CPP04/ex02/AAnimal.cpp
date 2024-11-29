/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:32:44 by miturk            #+#    #+#             */
/*   Updated: 2024/10/29 14:46:45 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAanimal") {
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string &type) : _type(type) {
	std::cout << "AAnimal type constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : _type(copy._type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &copy) {
	std::cout << "AAnimal assignation operator called" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return *this;
}

std::string AAnimal::getType() const {
	return _type;
}

void AAnimal::setType(const std::string &type) {
	_type = type;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

//void AAnimal::makeSound() const {
// 	std::cout << "Unknown Aanimal sound" << std::endl;
// }