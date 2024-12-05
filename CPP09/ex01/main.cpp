/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:07:48 by miturk            #+#    #+#             */
/*   Updated: 2024/12/05 17:57:36 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iterator>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./RPN [file_name]" << std::endl;
		return (1);
	}
	std::string call(argv[1]);
	for (size_t i = call.size(); i > 0; i--) {
		// readInput(call[i]);
	}
	
	return (0);
}