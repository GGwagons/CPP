/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:09:38 by miturk            #+#    #+#             */
/*   Updated: 2024/12/05 17:28:41 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <fstream>

template <typename S, typename L = std::list<S> >
class RPN : public std::stack<T, L> {
private:
	unsigned int _size;
	std::string _input;
	double _numA;
	double _numB;
	double _result;
public:
	RPN();
	RPN(const std::string &input);
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);
	~RPN();
	void readInput(int in);
};

#endif