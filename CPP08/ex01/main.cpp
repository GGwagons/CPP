/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wagons <wagons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:36:37 by wagons            #+#    #+#             */
/*   Updated: 2024/11/24 21:49:26 by wagons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Output: 2
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // Output: 14

        // Example with a range of numbers
        Span largeSpan(10000);
        std::vector<int> range(10000);
        for (int i = 0; i < 10000; i++) {
            range[i] = i;
        }
        largeSpan.addNumbers(range.begin(), range.end());
        std::cout << "Shortest Span (Large): " << largeSpan.shortestSpan() << std::endl; // Output: 1
        std::cout << "Longest Span (Large): " << largeSpan.longestSpan() << std::endl;   // Output: 9999

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}