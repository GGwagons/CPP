/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SwapComp.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:25:39 by miturk            #+#    #+#             */
/*   Updated: 2024/11/18 13:29:51 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SwapComp.hpp"

SwapComp::SwapComp() {}

SwapComp::SwapComp(const SwapComp &copy) {
	*this = copy;
};

SwapComp &SwapComp::operator=(const SwapComp &copy) {
	if (this != &copy) {};
	return *this;
}

SwapComp::~SwapComp() {}