/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:31:48 by miturk            #+#    #+#             */
/*   Updated: 2024/11/20 16:44:35 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 3
int main() {
	Array<int> intArr(MAX_VAL);
	Array<double> doubleArr(MAX_VAL);
	Array<std::string> stringArr(MAX_VAL);
	for (int i = 0; i < MAX_VAL; i++) {
		intArr[i] = i;
		doubleArr[i] = i + (i * 0.1);
	}
	stringArr[0] = "Hello";
	stringArr[1] = "World";
	stringArr[2] = "!";
	Array<int> intArrCopy = intArr;
	Array<double> doubleArrCopy = doubleArr;
	Array<std::string> stringArrCopy = stringArr;
	
	std::cout << "Int Array" << std::endl;
	for (int i = 0; i < MAX_VAL; i++) {
		std::cout << "OG: "<< intArr[i] << std::endl;
		std::cout << "Copy: "<< intArrCopy[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Double Array" << std::endl;
	for (int i = 0; i < MAX_VAL; i++) {
		std::cout << "OG: " << doubleArr[i] << std::endl;
		std::cout << "Copy: " << doubleArrCopy[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "String Array" << std::endl;
	for (int i = 0; i < MAX_VAL; i++) {
		std::cout << "OG: " << stringArr[i] << std::endl;
		std::cout << "Copy: " << stringArrCopy[i] << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "intArr[MAX_VAL] = 0" << std::endl;
		intArr[MAX_VAL] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try {
		std::cout << "doubleArr[MAX_VAL] = 0" << std::endl;
		doubleArr[MAX_VAL] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try {
		std::cout << "stringArr[MAX_VAL] = \"!\"" << std::endl;
		stringArr[MAX_VAL] = "!";
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try {
		std::cout << "intArr[-2] = 0" << std::endl;
		intArr[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try {
		std::cout << "std::cout << stringArr[-1] << std::endl" << std::endl;
		std::cout << stringArr[-1] << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try {
		std::cout << "stringArr[1]" << std::endl;
		std::cout << stringArr[1] << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try {
		std::cout << "stringArr[1] = Capitalism" << std::endl;
		stringArr[1] = "Capitalism";
		std::cout << "Is now: " << stringArr[1] << std::endl;
		std::cout << "Copy of the OG : " << stringArrCopy[1]  << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	return 0;
}
