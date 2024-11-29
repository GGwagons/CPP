/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:40:45 by miturk            #+#    #+#             */
/*   Updated: 2024/10/15 11:46:42 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Weapon {
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		Weapon();
		~Weapon();
		std::string const &getType();
		void setType(std::string type);
};

#endif