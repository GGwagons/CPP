/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ItIter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mIterurk <mIterurk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:11:35 by mIterurk            #+#    #+#             */
/*   Updated: 2024/11/18 16:45:59 by mIterurk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

Iter::Iter() {};

Iter::Iter(const Iter &copy) {
	*this = copy;
}

Iter &Iter::operator=(const Iter &copy) {
	if (this != &copy) {};
	return (*this);
}

Iter::~Iter() {};
