/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:27:57 by miturk            #+#    #+#             */
/*   Updated: 2025/01/09 16:48:14 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: ./a.out [num1 num2 num3 ...]" << std::endl;
		return (1);
	}
	try {
		Pmerge data;
		data.what = 2;
		if (data.what == 0 || data.what == 2) {
			Vector(argc, argv, data);
			Deque (argc, argv, data);
		}
		else {
			Deque (argc, argv, data);
			Vector(argc, argv, data);
		}
		std::cout << "Containers are Sorted" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}