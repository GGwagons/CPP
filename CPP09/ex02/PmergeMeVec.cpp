/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:03:59 by miturk            #+#    #+#             */
/*   Updated: 2024/12/16 16:40:42 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

typedef _vector::iterator IT;

void mergeSortVec(_vector &container, Pmerge &data) {
    if (container.size() < 3) {
        return ;
    }
	_vector top; 
	_vector bot;
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
	puts("hi");
	::print(top);
	::print(bot);
	mergeSortVec(top, data);
	IT sit = bot.begin();
	IT pos;
	for (; sit != bot.end(); ++sit) {
        pos = std::lower_bound(top.begin(), top.end(), *sit);
        top.insert(pos, *sit);
		data.compares++;
		jakobSomething(top, data);
    }
	container.swap(top);
}