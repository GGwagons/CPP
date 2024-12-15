/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwagons <ggwagons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:29:08 by miturk            #+#    #+#             */
/*   Updated: 2024/12/15 00:01:27 by ggwagons         ###   ########.fr       */
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

typedef struct PmergeMe
{
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
void mergeSort(T &container, PmergeMe &data) {
    if (container.size() < 2) {
        return ;
    }
	T top; 
	T bot;
	typename T::iterator it = container.begin();
	typename T::iterator pair = it;
	typename T::iterator ite = container.end();
	for (; it != ite;) {
		if (it + 1 == ite) {
			break;
		}
		pair = it + 1;
		if (*it > *pair) {
			top.push_back(*it); bot.push_back(*pair);
		}
		else {
			top.push_back(*pair); bot.push_back(*it);
		}
		it = pair + 1; data.compares++;
	}
	if (container.size() % 2 != 0) {
		bot.push_back(container.back());
	}
	mergeSort(top, data);
	typename T::iterator sit = bot.begin();
	typename T::iterator pos;
	for (; sit != bot.end(); ++sit) {
        pos = std::lower_bound(top.begin(), top.end(), *sit);
        top.insert(pos, *sit);
    }
	container.swap(top);
}

void timeStamp(timeval &start, timeval &end);
void Vector(int argc, char **argv, Pmerge &data);
void Deque(int argc, char **argv, Pmerge &data);

#endif