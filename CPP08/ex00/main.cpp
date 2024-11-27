/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:07:13 by wagons            #+#    #+#             */
/*   Updated: 2024/11/27 14:19:30 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	 try {
        std::cout << "Vector test:" << std::endl;
    	std::vector<int> vec;
		for (int i = 0; i < 6; i++) {
			vec.push_back(i);
			std::cout << vec[i] << std::endl;
		}
        std::cout << "Searching for 3 in vector... Found: " << *easyFind(vec, 3) << std::endl;
        std::cout << "Searching for 6 in vector... Found: " << *easyFind(vec, 6) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	 try {
        std::cout << "Deque test:" << std::endl;
    	std::deque<int> deq;
		for (int i = 0; i < 6; i++) {
			deq.push_back(i * 2);
			std::cout << deq[i] << std::endl;
		}
        std::cout << "Searching for 3 in deque... Found: " << *easyFind(deq, 3) << std::endl;
        std::cout << "Searching for 6 in deque... Found: " << *easyFind(deq, 6) << std::endl;
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
		std::cout << "Searching for 6 in list... Found: " << *easyFind(list, 6) << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
