/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:29:08 by miturk            #+#    #+#             */
/*   Updated: 2024/12/16 16:39:59 by miturk           ###   ########.fr       */
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
void jakobSomething(T &container, Pmerge &data) {
	::print(container);
	std::cout << data.compares << std::endl;
}

void mergeSortDeq(_deque &container, Pmerge &data);
void mergeSortVec(_vector &container, Pmerge &data);
void timeStamp(timeval &start, timeval &end);
void Vector(int argc, char **argv, Pmerge &data);
void Deque(int argc, char **argv, Pmerge &data);

#endif