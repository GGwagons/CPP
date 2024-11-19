/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:01:55 by miturk            #+#    #+#             */
/*   Updated: 2024/11/19 14:26:49 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITER_HPP
#define ITER_HPP

#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>

template <typename I>
void increment(I &i) {
	size_t x = static_cast<size_t>(i);
    x += 1;
}

template <typename T>
void print(T &i){
	std::cout << std::fixed << std::setprecision(1) <<  " [" << i << "]"; 
}

template <typename ITER, typename LEN>
void iter(ITER *array, LEN len, void (*fun)(ITER &)) {
	for (LEN i = 0; i < len; i++) {
		fun(array[i]);
	}
}

class Iter {
	private:
		Iter();
		Iter(const Iter &copy);
		Iter &operator=(const Iter &copy);
		~Iter();
	public:
};

#endif