/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwagons <ggwagons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:27:57 by miturk            #+#    #+#             */
/*   Updated: 2024/12/15 00:06:34 by ggwagons         ###   ########.fr       */
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
		gettimeofday(&data.start, NULL);
		Vector(argc, argv, data);
		gettimeofday(&data.end, NULL);
		timeStamp(data.start, data.end);
		gettimeofday(&data.start, NULL);
		Deque (argc, argv, data);
		gettimeofday(&data.end, NULL);
		timeStamp(data.start, data.end);
		
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}