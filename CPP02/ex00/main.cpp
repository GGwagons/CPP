/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:24:58 by miturk            #+#    #+#             */
/*   Updated: 2024/10/18 16:34:01 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;
	return 0;
}