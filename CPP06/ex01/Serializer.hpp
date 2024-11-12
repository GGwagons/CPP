/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:44:02 by miturk            #+#    #+#             */
/*   Updated: 2024/11/12 14:47:31 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>


struct Data {
	int _i;
	std::string _s;
	Data(int i, std::string s) : _i(i), _s(s) {}
};

class Serializer {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data *deserialize(uintptr_t raw);
};




#endif