/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:55:19 by miturk            #+#    #+#             */
/*   Updated: 2024/12/19 18:17:34 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <stdio.h>
#include <sys/time.h>
#include <cstdlib>
#include <exception>

typedef std::deque<std::deque<int> > _Ddeq;
typedef std::deque<int> _deque;
typedef std::vector<std::vector<int> > _Vvec;
typedef std::vector<int> _vector;

typedef struct PmergeMe {
	size_t x;
	size_t y;
	size_t row;
	_Vvec vec;
	_Ddeq deq;
	int compares;
	// struct timeval start;
	// struct timeval end;
} Pmerge;

template <typename T>
void print(T &container) {
	typename T::iterator it;
	typename T::value_type::iterator inner_it;
	for (it = container.begin(); it != container.end(); ++it) {
		for (inner_it = it->begin(); inner_it != it->end(); ++inner_it) {
			if (inner_it != it->begin()) {
				std::cout << ", ";
			}
			std::cout << *inner_it;
		}
		std::cout << std::endl;
	}
}

template <typename T>
T mergeInsertion(T &container, Pmerge &data) {
	if (container.size() == 1)
		return (container);
	T temp(container.size());
	for (size_t i = 0; data.row < container.size(); data.row += 2) {
		temp[data.row].push_back(container[data.row + 1][data.x]);
		for (; i < container[data.row].size(); i++) {
			temp[data.row].push_back(container[data.row][i]);
			if (i + 1 != container[data.row].size())
				temp[data.row + 1].push_back(container[data.row + 1][i + 1]);
		}
		i = 0;
	}
	// for (size)
	// if (temp.size() != temp.size() / 2)
	// 	return mergeInsertion(temp, data);
	return (temp);
}

int main() {
	Pmerge data;
	data.x = 0;
	data.y = 0;
	data.row = 0;
	data.compares = 0;
	_Vvec temp(5);
	data.vec = temp;
	data.vec[0].push_back(6);
	data.vec[0].push_back(10);
	data.vec[1].push_back(4);
	data.vec[1].push_back(3);
	data.vec[2].push_back(5);
	data.vec[2].push_back(9);
	data.vec[3].push_back(2);
	data.vec[3].push_back(1);
	data.vec[3].push_back(7);
	puts("before");
	::print(data.vec);
	data.vec = mergeInsertion(data.vec, data);
	puts("after");
	::print(data.vec);

}


// 2, 4 | 6, 5 | 1, 3 | 10, 9  7

// 4 6 3 10
// 2 5 1 9 7

// 6 10
// 4 3
// 5 9
// 2 1 7
