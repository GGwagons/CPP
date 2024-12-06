/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwagons <ggwagons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:13:07 by miturk            #+#    #+#             */
/*   Updated: 2024/12/06 20:47:53 by ggwagons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _stack(){}

RPN::RPN(std::stack<double, std::list<double> > stack) : _stack(stack) {}

RPN::RPN(const RPN &copy) { *this = copy; }


RPN &RPN::operator=(const RPN &copy) {
	if (this != &copy) {
		_stack = copy._stack;
	}
	return (*this);
}

RPN::~RPN() {}

bool RPN::Operator(const std::string &input) {
	if (input == "+" || input == "-" || input == "*" || input == "/" || input == "%") {
		return (true);
	}
	return (false);
}

void RPN::getStack() {
	std::stack<double, std::list<double> > tmp = _stack;
	std::cout << "R: " << tmp.top() << std::endl;
}

double RPN::Operation(double a, double b, const std::string &op) {
	if (op == "+") {
		return (a + b);
	}
	else if (op == "-") {
		return (a - b);
	}
	else if (op == "*") {
		return (a * b);
	}
	else if (op == "/") {
		return (a / b);
	}
	return (0);
}

void RPN::readInput(std::string &token) {
	if ((token[0] != ' ' && !Operator(token) && !isdigit(token[0])) || token.empty()) {
		throw std::runtime_error("R: Error");
	}
	if (token[0] == ' ') {return ;}
	if (isdigit(token[0])) {
		_stack.push(std::atof(token.c_str()));
		return;
	}
	if (Operator(token)) {
		if (_stack.size() < 2) {
			throw std::runtime_error("Not enough values");
		}
		double a = _stack.top();
		_stack.pop();
		double b = _stack.top();
		_stack.pop();
		if (a == 0 && token == "/") {
			throw std::runtime_error("Division by zero");
		}
		_stack.push(Operation(b, a, token));
	}
}