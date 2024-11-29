/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:32:38 by miturk            #+#    #+#             */
/*   Updated: 2024/10/30 11:28:26 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(const std::string &type);
		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &copy);
		std::string getType() const;
		void setType(const std::string &type);
		virtual void makeSound() const = 0;
		virtual ~AAnimal();
};

#endif