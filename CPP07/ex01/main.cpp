/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:59:38 by miturk            #+#    #+#             */
/*   Updated: 2024/11/19 18:05:24 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main() {
	int Iray[5] = {1, 2, 3, 4, 5};
	std::cout << "Iray: ";
	iter(Iray, 5, print);
	std::cout << std::endl;

	double Dray[5] = {1.0, 2.0, 3.2, 4.3, 5.4};
	std::cout << "Dray: ";
	iter(Dray, 5, print);
	std::cout << std::endl;

	float Fray[5] = {1.3f, 2.6f, 3.12f, 4.55f, 5.56f};
	std::cout << "Fray: ";
	iter(Fray, 5, print);
	std::cout << std::endl;
	
	std::cout << "ARRAY:   ";
	std::string arr = "Hello, World!";
	size_t len = arr.size();
	iter(arr.c_str(), len, print);
	std::cout << std::endl;

	std::cout << "ARRAY1:   ";
	std::string arr1 = "Hello, World!";
	iter(arr1.c_str(), 13, print);
	std::cout << std::endl;

	std::cout << "ARRAY2:   ";
	const char arr2[14] = "Hello, World!";
	iter(arr2, 14, print);
	std::cout << std::endl;
	
	return (0);
}