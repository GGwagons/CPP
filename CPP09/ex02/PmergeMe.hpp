/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:29:08 by miturk            #+#    #+#             */
/*   Updated: 2025/01/08 16:57:45 by miturk           ###   ########.fr       */
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
#include <cmath>

typedef std::deque<std::deque<int> > _Ddeq;
typedef std::vector<std::vector<int> > _Vvec;
typedef std::vector<int> _vec;
typedef std::deque<int> _deq;

typedef struct PmergeMe {
    _Vvec vec;
    _Ddeq deq;
    int compares;
	int what;
    struct timeval start;
    struct timeval end;
} Pmerge;

_Ddeq stackSortDeq(_Ddeq &container, Pmerge &data);
_Vvec stackSortVec(_Vvec &container, Pmerge &data);
size_t JakobsThal(size_t num);
void timeStamp(timeval &start, timeval &end);
void Vector(int argc, char **argv, Pmerge &data);
void Deque(int argc, char **argv, Pmerge &data);


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
void add(T &container, int argc, char **argv) {
    std::string str;
    typename T::value_type innerContainer;
    for (int i = 1; i < argc; i++) {
        str = argv[i];
        int num = std::atoi(str.c_str());
        if (num < 0) {
            std::cerr << "Error: Negative Value";
            throw std::runtime_error("");
        }
        innerContainer.push_back(num);
    }
    container.push_back(innerContainer);
}

template <typename T>
int binaryInsert(T *container, int val, Pmerge &data, typename T::iterator ite) {
    typename T::iterator it = container->begin();
    while (it < ite) {
        data.compares++;
		typename T::iterator mid = it;	
    	std::advance(mid, (ite - it) / 2);
        if (val < *mid) {ite = mid;}
		else {it = mid + 1;}
    }
	size_t ret = it - container->begin();
	container->insert(it, val);
	return (ret);
}

template <typename T>
T mergeInsertion(T &container, Pmerge &data) {
	if (container.size() == 1) {return container;}
	for (size_t row = 1; row < container.size(); row += 2) {
		container[row - 1].insert(container[row - 1].begin(), container[row][0]);
		container[row][0] = -1;
		container[row].insert(container[row].begin(), -1);
	}
	size_t j;
	for (size_t i = 2; pow(2, i - 1) < container[1].size(); i++) {
		if (pow(2, i) >= container[1].size()) {j = container[1].size() - 1;}
		else {j = pow(2, i) - 1;}
		size_t jj = j + 1;
		for (; j > 0; j--) {
			if (container[1][j] != -1) {
				typename T::value_type::iterator end;
				if (j < container[0].size()) {end = container[0].begin() + j;}
				else {end = container[0].end();}
				int pos = binaryInsert(&container[0], container[1][j], data, end);
				container[1][j] = -1;
				container[1].insert(container[1].begin() + pos, -1);
				for (size_t x = 3; x < container.size(); x += 2) {
					container[x - 1].insert(container[x - 1].begin() + pos, container[x][j]);
					container[x][j] = -1;
					container[x].insert(container[x].begin() + pos, -1);
				}
				j = jj;
			}
		}
	}
	for (size_t x = 3; x < container.size(); x += 2) {
		for (size_t y = 0; y < container[x].size(); y++) {
			if (container[x][y] != -1) {container[x - 1].push_back(container[x][y]);}
		}
	}
	T tmp;
	for (size_t x = 0; x < container.size(); x += 2) {tmp.push_back(container[x]);}
	return mergeInsertion(tmp, data);
}

#endif