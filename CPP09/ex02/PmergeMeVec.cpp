/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwagons <ggwagons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:03:59 by miturk            #+#    #+#             */
/*   Updated: 2024/12/16 21:46:13 by ggwagons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

typedef _vector::iterator IT;

void mergeSortVec(_vector &container, Pmerge &data) {
    if (container.size() < 3) {
        return ;
    }
	_vector top; _vector bot;
	IT	it = container.begin();
	IT pair = it;
	IT ite = container.end();
	for (; it != ite;) {
		if (it + 1 == ite) {
			break;
		}
		pair = it + 1;
		if (*it > *pair) {
			top.push_back(*it); bot.push_back(*pair);
		}
		else {
			top.push_back(*pair); bot.push_back(*it);
		}
		it = pair + 1; data.compares++;
	}
	if (container.size() % 2 != 0) {
		bot.push_back(container.back());
	}
	mergeSortVec(top, data);
	puts("hihi");
	::print(top);
	::print(bot);
	_vector res(top.size() + bot.size());
	res = MergeInsertionSort(top, bot, data);
	puts("testy");
	::print(res);
	// IT sit = bot.begin(); IT pos;
	// for (; sit != bot.end(); ++sit) {
    //     pos = std::lower_bound(top.begin(), top.end(), *sit);
    //     top.insert(pos, *sit);
	// 	data.compares++;
	// 	jakobSomething(top,  data);
    // }
	// container.swap(top);
}