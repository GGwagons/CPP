/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wagons <wagons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:29:27 by wagons            #+#    #+#             */
/*   Updated: 2024/11/24 22:32:36 by wagons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	private:
		unsigned int _max;
		std::vector<int> _array;
	public:
		// ORTHODOX CANONICAL FORM
		Span();
		Span(unsigned int max);
		Span(const Span &copy);
		~Span();
		Span &operator=(const Span &copy);
		
		// MANUAL
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		
		// FOR RANGE
		template <typename Iterator>
    	void addNumbers(Iterator begin, Iterator end) {
    	    if (std::distance(begin, end) + _array.size() > _max) {
    	        throw InvalidSpan();
    	    }
    	    _array.insert(_array.end(), begin, end);
    	}
		
		// EXCEPTIONS
		class InvalidSpan : public std::exception {
			public :
				virtual const char *what() const throw() {
					return "Span has a invalid size";
				}
		};
		class maxSpan : public std::exception {
			public :
				virtual const char *what() const throw() {
					return "Cannot add more. Span is full";
				}
		};
};

#endif
