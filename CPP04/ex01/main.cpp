/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:31:42 by miturk            #+#    #+#             */
/*   Updated: 2024/10/31 09:40:35 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    j->makeSound();
    i->makeSound();

    delete j; // Should call Dog destructor and Brain destructor
    delete i; // Should call Cat destructor and Brain destructor
	std::cout << "<----------------------------------->" << std::endl;
    // Testing array of Animals with mixed types
	Dog dog;
	Cat cat;
    Animal* Animals[100];
	int index = 0;
	for (; index < 100; ++index) {
		if (index % 2 == 0) {
			Animals[index] = new Dog();
			Animals[index]->makeSound();
			dog.getBrain().setIdea(index, "I am a dog, bork bork");
			std::cout << dog.getBrain().getIdea(index) << std::endl;
			std::cout << std::endl;
		}
		else {
			Animals[index] = new Cat();
			Animals[index]->makeSound();
			cat.getBrain().setIdea(index, "I am a cat, meow meow");
			std::cout << cat.getBrain().getIdea(index) << std::endl;
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "<----------DELETE-Animals---------->" << std::endl;
	std::cout << std::endl;
	for (int k = 0; k < index; ++k) {
		delete Animals[k];
	}
	std::cout << "<----------DEEP-COPY-TEST---------->" << std::endl;
	std::cout << std::endl;
    // Test deep copy behavior
    Dog originalDog;
	std::cout << std::endl;
    Dog copyDog = originalDog;
	std::cout << std::endl;
    Cat originalCat;
	std::cout << std::endl;
    Cat copyCat = originalCat;
	std::cout << std::endl;
	std::cout << "<----------DEEP-COPY-TEST---------->" << std::endl;
	Dog basic;
	{
	Dog tmp = basic;
	}
	Dog dog1;
	Dog dog2;
	Dog dog3;
	dog1.getBrain().setIdea(0, "dog1");
	dog2.getBrain().setIdea(0, "dog2");
	dog3 = dog1;
	std::cout << dog3.getBrain().getIdea(0) << std::endl;
	Dog dog4(dog2);
	std::cout << dog1.getBrain().getIdea(0) << std::endl;
	std::cout << dog4.getBrain().getIdea(0) << std::endl;
	dog3.getBrain().setIdea(0, "Nice evaluation so far");
	std::cout << dog1.getBrain().getIdea(0) << std::endl;
	std::cout << dog3.getBrain().getIdea(0) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "<----------DEEP-COPY-TEST---------->" << std::endl;
	return 0;
}