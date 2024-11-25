/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wagons <wagons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:07:13 by wagons            #+#    #+#             */
/*   Updated: 2024/11/24 21:38:12 by wagons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>


int main() {
	 try {
        // Test with std::vector
    	std::vector<int> vec;
		for (int i = 0; i < 6; i++) {
			vec.push_back(i);
		}
        std::cout << "Vector test:" << std::endl;
        std::cout << "Searching for 3 in vector... Found: " << *easyfind(vec, 3) << std::endl;
        std::cout << "Searching for 6 in vector..." << std::endl;
        easyfind(vec, 6);  // This will throw an exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	try {
		std::list<int> List;
		for (int i = 0; i < 6; i++) {
			List.push_back(i);
		}
		std::cout << "List test:" << std::endl;
		std::cout << "Searching for 3 in list... Found: " << *easyfind(List, 3) << std::endl;
		std::cout << "Searching for 6 in list..." << std::endl;
        easyfind(List, 6);  // This will throw an exception
		
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}