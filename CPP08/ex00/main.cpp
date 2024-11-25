/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:07:13 by wagons            #+#    #+#             */
/*   Updated: 2024/11/25 16:52:35 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>


int main() {
	 try {
        std::cout << "Vector test:" << std::endl;
    	std::vector<int> vec;
		for (int i = 0; i < 6; i++) {
			vec.push_back(i);
			std::cout << vec[i] << std::endl;
		}
        std::cout << "Searching for 3 in vector... Found: " << *easyFind(vec, 3) << std::endl;
        std::cout << "Searching for 6 in vector..." << std::endl;
        easyFind(vec, 6);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	 try {
        std::cout << "Deque test:" << std::endl;
    	std::deque<int> vec;
		for (int i = 0; i < 6; i++) {
			vec.push_back(i * 2);
			std::cout << vec[i] << std::endl;
		}
        std::cout << "Searching for 3 in deque... Found: " << *easyFind(vec, 3) << std::endl;
        std::cout << "Searching for 6 in deque..." << std::endl;
        easyFind(vec, 6);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	try {
		std::cout << "List test:" << std::endl;
		std::list<int> list;
		for (int i = 0; i < 6; i++) {
			list.push_back(i + 3);
		}
		std::list<int>::iterator it = list.begin();
		for (int i = 0; i < 6; i++) {
			std::cout << *it << std::endl;
			it++;
		}
		std::cout << "Searching for 3 in list... Found: " << *easyFind(list, 3) << std::endl;
		std::cout << "Searching for 6 in list..." << std::endl;
        easyFind(list, 6);
		
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}