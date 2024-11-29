/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:31:42 by miturk            #+#    #+#             */
/*   Updated: 2024/10/31 10:13:44 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"

int main() {
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    j->makeSound();
    i->makeSound();

    delete j; // Should call Dog destructor and Brain destructor
    delete i; // Should call Cat destructor and Brain destructor
	std::cout << "<----------------------------------->" << std::endl;
    // Testing array of Aanimals with mixed types
	Dog dog;
	Cat cat;
    AAnimal* Aanimals[100];
	int index = 0;
	for (; index < 100; ++index) {
		if (index % 2 == 0) {
			Aanimals[index] = new Dog();
			Aanimals[index]->makeSound();
			dog.getBrain().setIdea(index, "I am a dog, bork bork");
			std::cout << dog.getBrain().getIdea(index) << std::endl;
			std::cout << std::endl;
		}
		else {
			Aanimals[index] = new Cat();
			Aanimals[index]->makeSound();
			cat.getBrain().setIdea(index, "I am a cat, meow meow");
			std::cout << cat.getBrain().getIdea(index) << std::endl;
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "<----------DELETE-AAnimals---------->" << std::endl;
	std::cout << std::endl;
	for (int k = 0; k < index; ++k) {
		delete Aanimals[k];
	}
    std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "<----------DEEP-COPY----------->" << std::endl;
	std::cout << std::endl;
    // Test deep copy behavior
    Dog originalDog;
	std::cout << std::endl;
    Dog copyDog = originalDog;
	std::cout << std::endl;
    Cat originalCat;
	std::cout << std::endl;
    Cat copyCat = originalCat;
	std::cout << "<----------DEEP-COPY-TEST---------->" << std::endl;

	// const AAnimal* animal = new AAnimal();	
	return 0;
}