/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwagons <ggwagons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:28:50 by miturk            #+#    #+#             */
/*   Updated: 2024/12/17 20:52:43 by ggwagons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void timeStamp(timeval &start, timeval &end) {
	size_t Tstart = (start.tv_sec *1000) + (start.tv_usec / 1000);
	size_t Tend = (end.tv_sec *1000) + (end.tv_usec / 1000);
	size_t elapsedTime = (Tend - Tstart);
	std::cout << elapsedTime << "ms" << std::endl;
}

void Vector(int argc, char **argv, Pmerge &data) {
	data.compares = 0;	
	gettimeofday(&data.start, NULL);
	::add(data.vec, argc, argv);
	std::cout << "Before: ";
	::print(data.vec);
	// _Vvec res;
	// res.resize((stackSortVec(data.vec, data)).size());
	data.vec = stackSortVec(data.vec, data);
	std::cout << "After: ";
	::print(data.vec);
	std::cout << "Compares: " << data.compares << std::endl;
	gettimeofday(&data.end, NULL);
}

void Deque(int argc, char **argv, Pmerge &data) {
	data.compares = 0;
	gettimeofday(&data.start, NULL);
	::add(data.deq, argc, argv);
	::print(data.vec);
	_Ddeq res;
	res = stackSortDeq(data.deq, data);
	std::cout << "After: ";
	::print(res);
	std::cout << "Compares: " << data.compares << std::endl;
	gettimeofday(&data.end, NULL);
}

// template <typename V, typename D>
// void printout(V &vec, D &deq) {
// 	std::cout << "Vector: ";
// 	::print(vec);
// 	std::cout << "Deque: ";
// 	::print(deq);
// }