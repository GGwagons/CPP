/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:27:57 by miturk            #+#    #+#             */
/*   Updated: 2024/12/10 18:56:08 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


// typedef std::vector<std::vector<int> > Vvector;

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: ./a.out [num1 num2 num3 ...]" << std::endl;
		return (1);
	}
	// struct timeval start, end;
	// gettimeofday(&start, NULL);
	Vvector V;
	std::cout << "[ VECTOR ]" << std::endl;
	::add(V, argc, argv);
	::print(V);
	std::cout << std::endl;
	V = ::theSort(V);
	::print(V);
	std::cout << std::endl;
	// std::cout << "<-------------------------------------------->" << std::endl;
	// Ddeque D;
	// std::cout << "[ DEQUE ]" << std::endl;
	// ::add(D, argc, argv);
	// ::print(D);
	// std::cout << std::endl;
	// gettimeofday(&end, NULL);
	// std::cout << "Time to process a range of " << V[0].size() << " elements with std::[";
	// ::print(V);
	// std::cout << "] : ";
	// timeStamp(start, end);
	// std::cout << std::endl;
	

	
	return (0);
}