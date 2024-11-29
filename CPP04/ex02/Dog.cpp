/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:35:21 by miturk            #+#    #+#             */
/*   Updated: 2024/10/30 14:07:47 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _brain(new Brain()) {
	std::cout << "Dog constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const std::string &type) : AAnimal(type) {
	std::cout << "Dog type constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : AAnimal(copy), _brain(new Brain(*copy._brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &copy) {
		AAnimal::operator=(copy);
		*_brain = *copy._brain;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Brain &Dog::getBrain() const {
	return *_brain;
}

void Dog::makeSound() const {
	if (_type == "Dog")
		std::cout << "Woof Woof!" << std::endl;
	else
		std::cout << "Dog sound" << std::endl;
}
