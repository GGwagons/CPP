/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:36:47 by miturk            #+#    #+#             */
/*   Updated: 2024/10/30 20:13:22 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal {
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(const std::string &type);
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);
		void setBrain(const Brain &brain);
		Brain &getBrain() const;
		void makeSound() const;
		virtual ~Cat();
};

#endif