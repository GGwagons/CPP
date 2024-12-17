/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwagons <ggwagons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:03:59 by miturk            #+#    #+#             */
/*   Updated: 2024/12/17 22:15:25 by ggwagons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

_Vvec stackSortVec(_Vvec &container, Pmerge &data) {
	if (container[0].size() < 3) {
		return container;
	}
	_Vvec temp(container.size() * 2);
	for (size_t x = 1; x < container[0].size(); x += 2) {
		if (container[0][x] > container[0][x - 1]) {
			temp[0].push_back(container[0][x]);
			temp[1].push_back(container[0][x - 1]);
			for (size_t y = 1; y < container.size(); y++) {
				temp[y + 1].push_back(container[1][x]);
				temp[y + 2].push_back(container[1][x - 1]);
				data.compares++;
				y++;
			}
		} 
		else {
			temp[0].push_back(container[0][x - 1]);
			temp[1].push_back(container[0][x]);
			for (size_t y = 1; y < container.size(); y++) {
				temp[y + 1].push_back(container[1][x - 1]);
				temp[y + 2].push_back(container[1][x]);
				data.compares++;
				y++;
			}
		data.compares++;
		}
		// size_t size = container[0].size();
		// for (size_t x = 1; x < container.size(); x++) {
		// 	for (size_t y = size; size != container[x].size(); y++) {
		// 		temp[(x * 2) + 1].push_back(container[x][y]);
		// 	}
		// }
	}
	puts("temp");
	::print(temp);
	if (container[0].size() % 2 != 0) {
		temp[1].push_back(container[0].back());
	}
	return stackSortVec(temp, data);
}
