/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:24:26 by miturk            #+#    #+#             */
/*   Updated: 2024/12/09 21:12:09 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _values(0), _combo(0), _compare(0) {}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	_combo = copy.getCombo();
	_values = copy.getValues();
	_compare = copy._compare;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
	if (this != &copy) {
		_combo = copy.getCombo();
		_values = copy.getValues();
		_compare = copy._compare;
	};
	return *this;
}

std::vector<int> PmergeMe::getValues() const {
	return _values;
}

vd PmergeMe::getCombo() const {
	return _combo;
}

void PmergeMe::setCombo(vd combo) {
	_combo = combo;
}

int PmergeMe::getCompare() const {
	return _compare;
}

void PmergeMe::storage(std::string &str) {
	if (str.empty() || str.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error("Invalid input");
	_values.push_back(conVal(str));
}

void PmergeMe::comboStore(std::vector<int> &values) {
	vd combo;
	for (size_t i = 0; i < values.size(); i += 2) {
		std::deque<int> tmp;
		for (size_t j = 0; j < 2; j++) {
			if (j + i >= values.size())
				tmp.push_back(-1);
			tmp.push_back(values[i + j]);
		}
		combo.push_back(tmp);
	}
	setCombo(combo);
}

void PmergeMe::checkDouble() {
	v values = getValues();
	std::sort(values.begin(), values.end());
	if (std::adjacent_find(values.begin(), values.end()) != values.end())
		throw std::runtime_error("Double value");
}

d PmergeMe::compare(vd &combo) {
	d tmp;
	for (size_t i = 0; i < combo.size(); i++) {
		if (combo[i][0] > combo[i][1]) {
			pushToNew(tmp, combo[i][0]);
			// combo[i].erase(combo[i].begin());
			// std::cout << combo[i][0] << " ";
		}
		else {
			pushToNew(tmp, combo[i][1]);
			//combo[i].erase(combo[i].begin() + 1);
		}
		_compare++;
		setCombo(combo);
	}
	return _tmp = tmp;
}