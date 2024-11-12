/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:43:49 by miturk            #+#    #+#             */
/*   Updated: 2024/11/12 14:42:21 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

static void *serialize(Data *ptr) {
	return reinterpret_cast<void *>(ptr);
}

static Data *deserialize(void *raw) {
	return reinterpret_cast<Data *>(raw);
}