/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:36:37 by wagons            #+#    #+#             */
/*   Updated: 2024/11/27 14:02:54 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    try {
        Span sp(6);
        sp.addNumber(-2147483648);
		sp.addNumber(-2147483647);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(2147483647);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        // Example with a range of numbers
        Span largeSpan(10000);
        std::vector<int> range(10000);
        for (int i = 0; i < 10000; i++) {
            range[i] = i;
        }
        largeSpan.addRange(range.begin(), range.end());
        std::cout << "Shortest Span (Large): " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span (Large): " << largeSpan.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	// Test with 2 Numbers
	try {
		Span sp(2);
		sp.addNumber(-2147483648);
		sp.addNumber(2147483647);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		Span sp2(2);
		sp2.addNumber(-2147483648);
		sp2.addNumber(-2147483647);
		std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	// Test with 1 Number
	try {
		Span sp(1);
		sp.addNumber(0);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
    return 0;
}