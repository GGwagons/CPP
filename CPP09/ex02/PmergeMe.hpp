/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:29:08 by miturk            #+#    #+#             */
/*   Updated: 2024/12/17 15:48:57 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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
	_Vvec vec;
	_Ddeq deq;
	int compares;
	struct timeval start;
	struct timeval end;
} Pmerge;

template <typename  T>
void smallprint(T &container) {
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();
	for (; it != ite; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

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
void add(T &container, int argc, char **argv) {
	std::string str;
	typename T::value_type innerContainer;
	for (int i = 1; i < argc; i++) {
		str = argv[i];
		int num = std::atoi(str.c_str());
		if (num < 0) {
			std::cerr << "Error";
			throw std::runtime_error("");
		}
		innerContainer.push_back(num);
	}
	container.push_back(innerContainer);
}

// template <typename T>
// void MergeInsertionSort(T &container, Pmerge &data) {
// 	data.compares++;
// 	::print(container);
// }

_Ddeq &stackSortDeq(_Ddeq &container, Pmerge &data);
_Vvec &stackSortVec(_Vvec &container, Pmerge &data);
void timeStamp(timeval &start, timeval &end);
void Vector(int argc, char **argv, Pmerge &data);
void Deque(int argc, char **argv, Pmerge &data);

#endif