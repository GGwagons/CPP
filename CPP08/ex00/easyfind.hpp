/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:08:14 by wagons            #+#    #+#             */
/*   Updated: 2024/11/25 17:11:53 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <exception>

template <typename T>
class NoFind : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Not Found");
		}
};

template <typename T>
typename T::iterator easyFind(T &con, int x) {
	typename T::iterator it = find(con.begin(), con.end(), x);
	if (it == con.end())
		throw NoFind<T>();
	return it;
}

#endif
