/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wagons <wagons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:08:14 by wagons            #+#    #+#             */
/*   Updated: 2024/11/24 21:38:51 by wagons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class NoFind : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Not Found");
		}
};

template <typename T>
typename T::iterator easyfind(T &con, int x) {
	typename T::iterator t = find(con.begin(), con.end(), x);
	if (t == con.end())
		throw NoFind();
	return t;
}

class EasyFind {
	private:
		EasyFind();
		EasyFind(const EasyFind &copy);
		~EasyFind();
		EasyFind &operator=(const EasyFind &copy);
	public:
};

#endif