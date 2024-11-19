/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:06:56 by miturk            #+#    #+#             */
/*   Updated: 2024/11/19 18:24:58 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <iomanip>

template <class T, typename SIZE>
class Array {
	private:
		T data[SIZE];
	public:
		Array();
		Array(const Array &copy);
		~Arrat();
		T &operator new[](SIZE index);
};

#endif