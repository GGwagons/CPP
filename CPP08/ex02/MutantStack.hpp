/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:14:14 by wagons            #+#    #+#             */
/*   Updated: 2024/11/26 12:40:41 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>
#include <iterator>
#include <deque>
#include <sstream>

template <typename T>
class MutantStack : public std::stack<T>{
	private:
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();
		typedef typename std::deque<T>::iterator iterator;
		iterator begin() {
			return std::stack<T>::c.begin();
		}
		iterator end() {
			return std::stack<T>::c.end();
		}
		
		typedef typename std::deque<T>::const_iterator const_iterator;
		const_iterator begin() const {
			return std::stack<T>::c.begin();
		}
		const_iterator end() const {
			return std::stack<T>::c.end();
		}

		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() {
			return std::stack<T>::c.rbegin();
		}
		reverse_iterator rend() {
			return std::stack<T>::c.rend();
		}

		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const {
			return std::stack<T>::c.rbegin();
		}
		const_reverse_iterator rend() const {
			return std::stack<T>::c.rend();
		}
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}	

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &copy) {
	if (this != &copy) {
		std::stack<T>::operator=(copy);
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

#endif
