/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:35:53 by wagons            #+#    #+#             */
/*   Updated: 2024/11/27 13:48:17 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _max(0) {}

Span::Span(unsigned int N) : _max(N) {
	std::cout << "Max: " << _max << std::endl;
	if (_max < 2 && _array.size() < 2) {
		throw InvalidSpan();
	}
}

Span::Span(const Span &copy) {
	*this = copy;
}

Span &Span::operator=(const Span &copy) {
	if (this != &copy) {
		_max = copy._max;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
	if (_array.size() >= _max) {
		throw maxSpan();
	}
	_array.push_back(num);
}

unsigned int Span::shortestSpan() {
	if (_array.size() < 2) {
		throw InvalidSpan();
	}
	std::vector<int> issorted = _array;
	std::sort(issorted.begin(), issorted.end());
	unsigned int diff;
	unsigned minSpan = std::numeric_limits<unsigned int>::max();
	for (std::size_t i = 1; i < _array.size(); i++) {
		diff = issorted[i] - issorted[i - 1];
		if (diff < minSpan) {
			minSpan = diff;
		}
	}
	return minSpan;
}

unsigned int Span::longestSpan() {
	if (_array.size() < 2) {
		throw InvalidSpan();
	}
	int minN = *std::min_element(_array.begin(), _array.end());
	int maxN = *std::max_element(_array.begin(), _array.end());
	return maxN - minN;
}
