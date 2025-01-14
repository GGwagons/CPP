/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeq.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:04:14 by miturk            #+#    #+#             */
/*   Updated: 2025/01/09 13:50:47 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

_Ddeq stackSortDeq(_Ddeq &container, Pmerge &data) {
	if (container[0].size() <= 2) {
		if (container[0].size() == 2) {
			data.compares++;
			if (container[0][0] > container[0][1]) {
				for (size_t i = 0; i < container.size(); i++) {
					std::swap(container[i][0], container[i][1]);
				}
			}
		}
		return container;
	}
	_Ddeq temp(container.size() * 2);
	for (size_t x = 1; x < container[0].size(); x += 2) {
		if (container[0][x] > container[0][x - 1]) {
			temp[0].push_back(container[0][x]);
			temp[1].push_back(container[0][x - 1]);
			for (size_t y = 1; y < container.size(); y++) {
				temp[2 * y].push_back(container[y][x]);
				temp[2 * y + 1].push_back(container[y][x - 1]);
			}
		} 
		else {
			temp[0].push_back(container[0][x - 1]);
			temp[1].push_back(container[0][x]);
			for (size_t y = 1; y < container.size(); y++) {
				temp[2 * y].push_back(container[y][x - 1]);
				temp[(2 * y) + 1].push_back(container[y][x]);
			}
		}
		data.compares++;
	}
	if (container[0].size() % 2 != 0) {
		temp[1].push_back(container[0].back());
		for (size_t y = 1; y < container.size(); y++) {
			temp[(y * 2) + 1].push_back(container[y][container[0].size() - 1]);
		}
	}
	size_t size = container[0].size();
	for (size_t x = 1; x < container.size(); x++) {
		for (size_t y = size; y < container[x].size(); y++) {
			temp[(x * 2) + 1].push_back(container[x][y]);
		}
	}
	return stackSortDeq(temp, data);
}
