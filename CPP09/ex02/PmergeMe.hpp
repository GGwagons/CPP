/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:24:40 by miturk            #+#    #+#             */
/*   Updated: 2024/12/09 21:21:14 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>

typedef std::vector<std::deque<int> > vd;
typedef std::vector<int> v;
typedef std::deque<int> d;

template <typename T>
void pushToNew(T &newContainer, int num) {
	newContainer.push_back(num);
}

template <typename T>
void printContainer(T &container) {
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();
	while (it != ite) {
		std::cout << *it;
		it++;
	}
	std::cout << std::endl;
}

template <typename T>
void comboPrint(T &container) {
	for (size_t i = 0; i < container.size(); i++) {
		std::cout << container[i][0];
		std::cout << container[i][1] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
int conVal(T &val) {
	int num;
	std::stringstream ss(val);
	ss >> num;
	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Invalid input");
	return num;
}

// template <typename V, typename D = std::deque<int> >
class PmergeMe {
	private:
		v _values;
		d _tmp;
		vd _combo;
		int _compare;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &op);
		
		vd	getCombo() const;
		v	getValues() const;
		int getCompare() const;
		void setCombo(vd combo);
		
		void storage(std::string &str);
		//void setStorage(PmergeMe &pm, char **argv);
		void comboStore(std::vector<int> &values);
		void checkDouble();
		d compare(vd &combo);
};



#endif