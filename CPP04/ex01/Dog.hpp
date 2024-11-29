/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:35:32 by miturk            #+#    #+#             */
/*   Updated: 2024/10/30 20:13:57 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(const std::string &type);
		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);
		void setBrain(const Brain &brain);
		Brain &getBrain() const;
		virtual void makeSound() const;
		virtual ~Dog();
};

#endif