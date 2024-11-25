/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wagons <wagons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:35:53 by wagons            #+#    #+#             */
/*   Updated: 2024/11/24 22:15:27 by wagons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <limits>

Span::Span() : _max(0) {}

Span::Span(unsigned int N) : _max(N) {
	std::cout << "Max: " << _max << std::endl;
	if (_max < 2) {
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

int Span::shortestSpan() {
	std::vector<int> issorted = _array;
	std::sort(issorted.begin(), issorted.end());
	int minSpan = std::numeric_limits<int>::max();
	for (std::size_t i = 1; i < _array.size(); i++) {
		int diff = issorted[i] - issorted[i - 1];
		if (diff < minSpan) {
			minSpan = diff;
		}
	}
	return minSpan;
}

int Span::longestSpan() {
	int minN = *std::min_element(_array.begin(), _array.end());
	int maxN = *std::max_element(_array.begin(), _array.end());
	return maxN - minN;
}
