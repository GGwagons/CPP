/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:29:27 by wagons            #+#    #+#             */
/*   Updated: 2024/11/26 17:06:29 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

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
		unsigned int shortestSpan();
		unsigned int longestSpan();
		
		// FOR RANGE
		template <class inputIterator>
    	void addRange(inputIterator begin, inputIterator end) {
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
