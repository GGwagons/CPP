/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:01:55 by miturk            #+#    #+#             */
/*   Updated: 2024/11/20 19:08:19 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <iomanip>

template <typename T>
void print(T &i){
	std::cout << std::fixed << std::setprecision(1) <<  " [" << i << "]" << std::endl; 
}

template <typename ITER, typename LEN>
void iter(ITER *array, LEN len, void (*fun)(const ITER &)) {
	if (len <= 0) {
		std::cout << "Array is empty" << std::endl;
		return;
	}
	for (LEN i = 0; i < len; i++) {
		fun(array[i]);
	}
}

template <typename ITER, typename LEN, typename FUN>
void iter(ITER *array, LEN len, FUN (*fun)(ITER &)) {
	if (len <= 0) {
		std::cout << "Array is empty" << std::endl;
		return;
	}
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
