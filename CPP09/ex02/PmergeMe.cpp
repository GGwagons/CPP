/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:28:50 by miturk            #+#    #+#             */
/*   Updated: 2025/01/09 16:49:13 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void timeStamp(timeval &start, timeval &end) {
	size_t Tstart = (start.tv_sec) + (start.tv_usec);
	size_t Tend = (end.tv_sec) + (end.tv_usec);
	float elapsedTime = (Tend - Tstart) * 0.00001;
	std::cout << std::fixed << std::setprecision(5) << elapsedTime << "us" << std::endl;
}

void Vector(int argc, char **argv, Pmerge &data) {
	data.compares = 0;
	::add(data.vec, argc, argv);
	if (data.what == 0 || data.what == 2) {
		std::cout << "[VECTOR] Before: ";
		::print(data.vec);
	}
	gettimeofday(&data.start, NULL);
	data.ogSize = data.vec[0].size();
	data.vec = stackSortVec(data.vec, data);
	data.vec = mergeInsertion(data.vec, data);
	if (data.what == 0 || data.what == 2) {
		std::cout << "[VECTOR] After: ";
		::print(data.vec);
		std::cout << "Compares: " << data.compares << std::endl;
	}
	gettimeofday(&data.end, NULL);
	std::cout << "Time to process a range of " << data.vec[0].size() << " with std::vector<std::vector<int> > : ";
	timeStamp(data.start, data.end);
	isSorted(data.vec[0], data);
}

void Deque(int argc, char **argv, Pmerge &data) {
	data.compares = 0;
	::add(data.deq, argc, argv);
	if (data.what == 1 || data.what == 2) {
		std::cout << "[DEQUE] Before: ";
		::print(data.deq);
	}
	gettimeofday(&data.start, NULL);
	data.ogSize = data.deq[0].size();
	data.deq = stackSortDeq(data.deq, data);
	data.deq = mergeInsertion(data.deq, data);
	if (data.what == 1 || data.what == 2) {
		std::cout << "[DEQUE] After: ";
		::print(data.deq);
		std::cout << "Compares: " << data.compares << std::endl;
	}
	gettimeofday(&data.end, NULL);
	std::cout << "Time to process a range of " << data.deq[0].size() << " with std::deque<std::deque<int> > : ";
	timeStamp(data.start, data.end);
	isSorted(data.deq[0], data);
}
