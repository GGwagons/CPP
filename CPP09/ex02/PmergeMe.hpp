/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:29:08 by miturk            #+#    #+#             */
/*   Updated: 2024/12/10 19:03:03 by miturk           ###   ########.fr       */
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

typedef std::deque<std::deque<int> > Ddeque;
typedef std::vector<std::vector<int> > Vvector;

template <typename T>
void print(T &container) {
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();
	for (; it != ite; ++it) {
		for (size_t i = 0; i < it->size(); i++) {
			if (i == it->size() - 1) {
				std::cout << (*it)[i];
				break;
			}
			std::cout << (*it)[i] << ", ";
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
		innerContainer.push_back(std::atoi(str.c_str()));
	}
	container.push_back(innerContainer);
}

template <typename T>
T theSort(T &container) {
	if (container[0].size() < 2) {
		::print(container);
		return container;
	}
	T temp(2);
	int i = 0;
	for (size_t x = 1; x < container[0].size() - 1; x += 2) {
		if (container[0][x] > container[0][x - 1]) {
			temp[0].push_back(container[0][x]);
			temp[1].push_back(container[0][x - 1]);
		} 
		else {
			temp[0].push_back(container[0][x - 1]);
			temp[1].push_back(container[0][x]);
		}
		// ::print(temp);
	}
	if (container[0].size() % 2 != 0)
		temp[1].push_back(container[0].back());
	::print(temp);
	std::cout << std::endl;
	return theSort(temp);
}

void timeStamp(timeval &start, timeval &end);

#endif