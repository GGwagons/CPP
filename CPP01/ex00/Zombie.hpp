/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:08:17 by miturk            #+#    #+#             */
/*   Updated: 2024/10/17 18:49:54 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Zombie {
	private:
			std::string _name;
	public:
			Zombie(std::string name);
			~Zombie();
			void announce(void);
			void setName(std::string name);
			
};

Zombie *newZombie( std::string name );
void randomChump( std::string name );

#endif