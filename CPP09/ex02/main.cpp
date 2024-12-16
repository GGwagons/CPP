/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:27:57 by miturk            #+#    #+#             */
/*   Updated: 2024/12/16 13:52:54 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: ./a.out [num1 num2 num3 ...]" << std::endl;
		return (1);
	}
	try {
		PmergeMe data;
		Vector(argc, argv, data);
		timeStamp(data.start, data.end);
		Deque (argc, argv, data);
		timeStamp(data.start, data.end);
		
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}