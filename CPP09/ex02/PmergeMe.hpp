/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwagons <ggwagons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:29:08 by miturk            #+#    #+#             */
/*   Updated: 2024/12/16 21:57:34 by ggwagons         ###   ########.fr       */
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

typedef std::deque<int> _deque;
typedef std::vector<int> _vector;

typedef struct PmergeMe {
	_vector vec;
	_deque deq;
	int compares;
	struct timeval start;
	struct timeval end;
} Pmerge;

template <typename T>
void print(const T &container) {
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void add(T &container, int argc, char **argv) {
	std::string str;
	for (int i = 1; i < argc; i++) {
		str = argv[i];
		int num = std::atoi(str.c_str());
		if (num < 0) {
			std::cerr << "Error";
			throw std::runtime_error("");
		}
		container.push_back(num);
	}
}

template <typename T>
T MergeInsertionSort(T &top, T &bot, Pmerge &data) {
	T container;
	size_t i = 0;
	size_t j = 0;
	if (top[i] < top[i + 1] && top.size() > 1) {
		::print(top);
		::print(bot);
		puts("swap");
		std::swap(top[i], top[i + 1]);
		std::swap(bot[i], bot[i + 1]);
		data.compares++;
		::print(top);
		::print(bot);
	}
	for (; i < top.size(); i++) {
		if (top[i] > bot[j]) {
			container.push_back(top[i]);
		}
		else {
			container.push_back(bot[j]);
		}
		j++;
		data.compares++;
	}
	for (; i < top.size(); i++) {
		container.push_back(top[i]);
		data.compares++;
	}
	for (; j < bot.size(); j++) {
		container.push_back(bot[j]);
		data.compares++;
	}
	::print(container);
	return container;
}

void mergeSortDeq(_deque &container, Pmerge &data);
void mergeSortVec(_vector &container, Pmerge &data);
void timeStamp(timeval &start, timeval &end);
void Vector(int argc, char **argv, Pmerge &data);
void Deque(int argc, char **argv, Pmerge &data);

#endif