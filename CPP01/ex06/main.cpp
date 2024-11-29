/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:57:36 by miturk            #+#    #+#             */
/*   Updated: 2024/10/17 18:19:42 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl harl;
	if (argc == 2) {
		harl.complain(argv[1]);
		return 0;
	}
	std::cout << "Usage: ./harl [DEBUG/INFO/WARNING/ERROR]" << std::endl;
	return 1;
	
}