/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:28:50 by miturk            #+#    #+#             */
/*   Updated: 2025/01/07 18:19:33 by miturk           ###   ########.fr       */
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
	gettimeofday(&data.start, NULL);
	data.compares = 0;
	data.row = 0;
	data.x = 0;
	data.y = 0;
	data.i = 0;
	::add(data.vec, argc, argv);
	std::cout << "Before: ";
	::print(data.vec);
	data.vec = stackSortVec(data.vec, data);
	std::cout << "Compares before: " << data.compares << std::endl;
	data.vec = mergeInsertion(data.vec, data);
	std::cout << "After: ";
	::print(data.vec);
	std::cout << "Compares: " << data.compares << std::endl;
	gettimeofday(&data.end, NULL);
	timeStamp(data.start, data.end);	
	std::cout << std::endl;
}

void Deque(int argc, char **argv, Pmerge &data) {
	gettimeofday(&data.start, NULL);
	data.compares = 0;
	data.row = 0;
	data.x = 0;
	data.y = 0;
	data.i = 1;
	::add(data.deq, argc, argv);
	std::cout << "Before: ";
	::print(data.deq);
	data.deq = stackSortDeq(data.deq, data);
	std::cout << "Compares before: " << data.compares << std::endl;
	data.deq = mergeInsertion(data.deq, data);
	std::cout << "After: ";
	::print(data.deq);
	std::cout << "Compares: " << data.compares << std::endl;
	gettimeofday(&data.end, NULL);
	timeStamp(data.start, data.end);
}

size_t JakobsThal(size_t num) {
	size_t sequence;
	num += 2;
	sequence = ((pow(2, num) - pow(-1, num))) / 3;
	return sequence;
}


// std::vector<size_t> generateJakobsThalSequence(size_t size) {
//     std::vector<size_t> sequence;
//     for (size_t i = 0; JacobsThal(i) < size; ++i) {
//         sequence.push_back(JacobsThal(i));
//     }
//     return sequence;
// }
// template <typename V, typename D>
// void printout(V &vec, D &deq) {
// 	std::cout << "Vector: ";
// 	::print(vec);
// 	std::cout << "Deque: ";
// 	::print(deq);
// }

// auto it = tmp[0].begin(); // Your iterator pointing to the insertion position
// auto val = /* your value to insert */;

// tmp[0].insert(it, val);

// // Calculate the index
// int index = std::distance(tmp[0].begin(), it);


// std::vector<std::vector<int>> tmp;

// // Assuming it and val are defined and valid
// std::vector<int>::iterator it;
// int val;

// std::vector<int>::iterator tt = tmp[0].insert(it, val);
// int pos = std::distance(tmp[0].begin(), tt);
// ::smallprint(tmp[0]);

// for (size_t row = 1; row + 2 < tmp.size(); row += 2) {
//     int num = tmp[row + 2][y];
//     tmp[row + 1].insert(tmp[row + 1].begin() + pos, num);
// }