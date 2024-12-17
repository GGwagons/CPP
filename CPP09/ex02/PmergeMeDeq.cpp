/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeq.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:04:14 by miturk            #+#    #+#             */
/*   Updated: 2024/12/17 13:59:08 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

_Ddeq &stackSortDeq(_Ddeq &container, Pmerge &data) {
	if (container[0].size() < 3) {
		return container;
	}
	_Ddeq temp(container.size() * 2);
	puts("D test");
	for (size_t x = 1; x < container[0].size(); x += 2) {
		if (container[0][x] > container[0][x - 1]) {
			temp[0].push_back(container[0][x]);
			temp[1].push_back(container[0][x - 1]);
			for (size_t y = 1; y < container.size(); y++) {
				temp[y].push_back(container[0][x]);
				temp[y + 1].push_back(container[0][x - 1]);
			}
		} 
		else {
			temp[0].push_back(container[0][x - 1]);
			temp[1].push_back(container[0][x]);
			for (size_t y = 1; y < container.size(); y++) {
				temp[y].push_back(container[0][x - 1]);
				temp[y + 1].push_back(container[0][x]);
			}
		}
		for (size_t y = 1; y < container.size(); y++) {
			size_t size = container[0].size();
			if (container[y].size() > size) {
				for (size_t i = size; i < container[y].size(); i++) {
					container[y - 1].push_back(container[y][2*i+1]);			
				}
			}
		}
		::print(temp);
		return stackSortDeq(temp, data);
	}
	if (container[0].size() % 2 != 0) {
		temp[1].push_back(container[0].back());
	}
	return stackSortDeq(container, data);
}