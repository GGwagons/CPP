/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwagons <ggwagons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:09:38 by miturk            #+#    #+#             */
/*   Updated: 2024/12/06 20:28:29 by ggwagons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <fstream>

class RPN {
	private:
		std::stack<double, std::list<double> > _stack;
		bool Operator(const std::string &input);
		double Operation(double a, double b, const std::string &op);
	public:
		void getStack();
		RPN();
		RPN(std::stack<double, std::list<double> > stack);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN();
		void readInput(std::string &token);
};
int runOne(int argc, char *argv[]);
int runTwo(std::fstream &file);

#endif