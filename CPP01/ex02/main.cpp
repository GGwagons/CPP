/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:16:57 by miturk            #+#    #+#             */
/*   Updated: 2024/10/15 14:05:29 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

int main () {
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "String address: " << &str << std::endl;
	std::cout << "Pointer address: " << ptr << std::endl;
	std::cout << "Reference address: " << &ref << std::endl;

	std::cout << "String value: " << str << std::endl;
	std::cout << "Pointer value: " << *ptr << std::endl;
	std::cout << "Reference value: " << ref << std::endl;
	return (0);
}