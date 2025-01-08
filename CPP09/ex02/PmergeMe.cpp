/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:28:50 by miturk            #+#    #+#             */
/*   Updated: 2025/01/08 16:58:18 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void timeStamp(timeval &start, timeval &end) {
	size_t Tstart = (start.tv_sec) + (start.tv_usec);
	size_t Tend = (end.tv_sec) + (end.tv_usec);
	size_t elapsedTime = (Tend - Tstart);
	std::cout << elapsedTime << "us" << std::endl;
}

void Vector(int argc, char **argv, Pmerge &data) {
	gettimeofday(&data.start, NULL);
	data.compares = 0;
	::add(data.vec, argc, argv);
	if (data.what == 0 || data.what == 2) {
		std::cout << "Before: ";
		::print(data.vec);
	}
	data.vec = stackSortVec(data.vec, data);
	data.vec = mergeInsertion(data.vec, data);
	if (data.what == 0 || data.what == 2) {
		std::cout << "After: ";
		::print(data.vec);
	}
	gettimeofday(&data.end, NULL);
	std::cout << "Time to process a range of " << data.vec[0].size() << " with std::vector<std::vector<int> > : ";
	timeStamp(data.start, data.end);
	std::cout << "Compares: " << data.compares << std::endl;
}

void Deque(int argc, char **argv, Pmerge &data) {
	gettimeofday(&data.start, NULL);
	data.compares = 0;
	::add(data.deq, argc, argv);
	if (data.what == 1 || data.what == 2) {
		std::cout << "Before: ";
		::print(data.deq);
	}
	data.deq = stackSortDeq(data.deq, data);
	data.deq = mergeInsertion(data.deq, data);
	if (data.what == 1 || data.what == 2) {
		std::cout << "After: ";
		::print(data.deq);
	}
	gettimeofday(&data.end, NULL);
	std::cout << "Time to process a range of " << data.deq[0].size() << " with std::deque<std::deque<int> > : ";
	timeStamp(data.start, data.end);
	std::cout << "Compares: " << data.compares << std::endl;
}
