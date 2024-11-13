/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:13:07 by miturk            #+#    #+#             */
/*   Updated: 2024/11/13 16:14:08 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	int id = 42;
	std::string name = "Miturk";
	Data data = {id, name};
	std::cout << "name: " << data.name << std::endl;
	std::cout << "id: " << data.id << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "raw: " << raw << std::endl;
	Data *ptr = Serializer::deserialize(raw);
	std::cout << "id: " << ptr->id << std::endl;
	std::cout << "name: " << ptr->name << std::endl;
	data.id = 43;
	data.name = "Miturk2";
	std::cout << "id: " << ptr->id << std::endl;
	std::cout << "name: " << ptr->name << std::endl;
	return 0;
}