/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:13:07 by miturk            #+#    #+#             */
/*   Updated: 2024/11/14 12:28:48 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	int id = 42;
	std::string name = "Miturk";
	unsigned int boo = 13;
	Data data = {id, name, boo};
	std::cout << "name: " << data.name << std::endl;
	std::cout << "id: " << data.id << std::endl;
	std::cout << "boo: " << data.boo << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "raw: " << raw << std::endl;
	Data *ptr = Serializer::deserialize(raw);
	std::cout << "name: " << ptr->name << std::endl;
	std::cout << "id: " << ptr->id << std::endl;
	std::cout << "boo: " << ptr->boo << std::endl;
	data.name = "Miturk2";
	data.id = 43;
	data.boo = 85;
	std::cout << "name: " << ptr->name << std::endl;
	std::cout << "id: " << ptr->id << std::endl;
	std::cout << "boo: " << ptr->boo << std::endl;
	return 0;
}