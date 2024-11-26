/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:14:14 by wagons            #+#    #+#             */
/*   Updated: 2024/11/26 16:34:41 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <list>
#include <deque>

template <typename T, typename D = std::deque<T> >
class MutantStack : public std::stack<T, D>{
	private:
	public:
		MutantStack();
		MutantStack(const MutantStack &copy);
		MutantStack &operator=(const MutantStack &copy);
		~MutantStack();
		typedef typename D::iterator iterator;
		iterator begin() {return std::stack<T, D>::c.begin();}
		iterator end() {return std::stack<T, D>::c.end();}
		
		typedef typename D::const_iterator const_iterator;
		const_iterator begin() const {return std::stack<T, D>::c.begin();}
		const_iterator end() const {return std::stack<T, D>::c.end();}

		typedef typename D::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() {return std::stack<T, D>::c.rbegin();}
		reverse_iterator rend() {return std::stack<T, D>::c.rend();}

		typedef typename D::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const {return std::stack<T, D>::c.rbegin();}
		const_reverse_iterator rend() const {return std::stack<T, D>::c.rend();}
};

template <typename T, typename D>
MutantStack<T, D>::MutantStack() : std::stack<T, D>() {}

template <typename T, typename D>
MutantStack<T, D>::MutantStack(const MutantStack &copy) : std::stack<T, D>(copy) {}	

template <typename T, typename D>
MutantStack<T, D> &MutantStack<T, D>::operator=(const MutantStack &copy) {
	if (this != &copy) {
		std::stack<T, D>::operator=(copy);
	}
	return *this;
}

template <typename T, typename D>
MutantStack<T, D>::~MutantStack() {}

#endif
