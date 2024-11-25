/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wagons <wagons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:15:26 by wagons            #+#    #+#             */
/*   Updated: 2024/11/24 21:34:12 by wagons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"

EasyFind::EasyFind() {};

EasyFind::EasyFind(const EasyFind &copy) {
	*this = copy;
}

EasyFind::~EasyFind() {};

EasyFind &EasyFind::operator=(const EasyFind &copy) {
	if (this != &copy) {}
	return *this;
}