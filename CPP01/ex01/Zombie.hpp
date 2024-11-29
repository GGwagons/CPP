/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 09:41:59 by miturk            #+#    #+#             */
/*   Updated: 2024/10/17 18:51:10 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Zombie {
	private:
			std::string _name;
			int _index;
	public:
			Zombie(std::string name);
			Zombie();
			~Zombie();
			void announce(void);
			void setName(std::string name);
			void setIndex(int index);
};
Zombie *zombieHorde( int N, std::string name );

#endif