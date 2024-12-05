/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:13:07 by miturk            #+#    #+#             */
/*   Updated: 2024/12/05 17:55:23 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

template <typename S, typename L>
RPN<S, L>::RPN() : std::stack<S, L>(),  _result(0), _input(""), _numA(0.0), _numB(0.0) {}

template <typename S, typename L>
RPN<S, L>::RPN(const RPN &copy) : std::stack<S, L>(copy), _stack(copy._stack), _input(copy._input), _result(copy._result), _numA(copy._numA), _numB(_numB) {}

template <typename S, typename L>
RPN<S, L> &RPN<S, L>::operator=(const RPN &copy) {
	if (this == &copy)
		return (*this);
	std::stack<S, L>::operator=(copy);
	_stack = copy._stack;
	_input = copy._input;
	_result = copy._result;
	return (*this);
}

template <typename S, typename L>
RPN<S, L>::~RPN() {}

template <typename S, typename L>
void RPN<S, L>::readInput(int in) {
	if (in != ' ') {
		_stack.push(in);
	}
	return ;
}