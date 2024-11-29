/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:28:32 by miturk            #+#    #+#             */
/*   Updated: 2024/10/17 18:48:21 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		int getLevel(std::string level);
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif