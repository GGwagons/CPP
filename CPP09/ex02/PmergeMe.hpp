/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:29:08 by miturk            #+#    #+#             */
/*   Updated: 2024/12/21 12:25:48 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <stdio.h>
#include <sys/time.h>
#include <exception>

typedef std::deque<std::deque<int> > _Ddeq;
typedef std::vector<std::vector<int> > _Vvec;

typedef struct PmergeMe {
	_Vvec vec;
	size_t row;
	size_t x;
	size_t y;
	_Ddeq deq;
	size_t i;
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

template <typename T>
T mergeInsertion(T &container, Pmerge &data) {
    if (container.size() <= 1) {return container;}
    T temp(container.size());
	if (data.row == 0) {
		puts("how");
		for (size_t i = 0; data.row < container.size(); data.row += 2) {
			temp[data.row].push_back(container[data.row + 1][data.x]);
			for (; i < container[data.row].size(); i++) {
				temp[data.row].push_back(container[data.row][i]);
			}
			for (data.y = 1; data.y < container[data.row + 1].size(); data.y++) {
				temp[data.row + 1].push_back(container[data.row + 1][data.y]);
			}
			i = 0;
		}
		return mergeInsertion(temp, data);
	}
	else {for (size_t i = 0; i < container.size(); i++) {temp[i] = container[i];}}
	T tmp(temp.size());
    for (size_t row = 0; row < temp.size(); ++row) {tmp[row] = temp[row];}
	for (size_t row = 1; row < tmp.size(); row += 2) {
		for (size_t y = 0; y < tmp[row].size(); ++y) {
			int val = tmp[row][y];
			typename T::value_type::iterator it = tmp[row - 1].begin();
			typename T::value_type::iterator ite = tmp[row - 1].end();
			while (it != ite) {
			    typename T::value_type::iterator mid = it;
			    std::advance(mid, std::distance(it, ite) / 2);
			    data.compares++;
			    if (*mid < val) {it = mid + 1;}
				else {ite = mid;}
			}
			tmp[row - 1].insert(it, val);
		}
	}
	T result;
	for (size_t row = 0; row < tmp.size(); row += 2) {result.push_back(tmp[row]);}
	data.row = 0;
	return mergeInsertion(result, data);
}

_Ddeq stackSortDeq(_Ddeq &container, Pmerge &data);
_Vvec stackSortVec(_Vvec &container, Pmerge &data);
void timeStamp(timeval &start, timeval &end);
void Vector(int argc, char **argv, Pmerge &data);
void Deque(int argc, char **argv, Pmerge &data);

#endif