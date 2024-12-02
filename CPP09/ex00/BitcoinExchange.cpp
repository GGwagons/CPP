/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:56:01 by ggwagons          #+#    #+#             */
/*   Updated: 2024/12/02 17:08:38 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

template <typename T>
BitcoinExchange<T>::BitcoinExchange() {}

template <typename T>
BitcoinExchange<T>::BitcoinExchange(const BitcoinExchange &copy) {*this = copy;}

template <typename T>
BitcoinExchange<T> &BitcoinExchange<T>::operator=(const BitcoinExchange<T> &copy) {
	if (this != &copy) {}
	return *this;
}

template <typename T>
BitcoinExchange<T>::~BitcoinExchange() {}

// template <typename T>
// bool getTime(T &date) {
//     std::time_t now = std::time(NULL);
//     std::tm *localTime = std::localtime(&now);
//     char buffer[11];
//     std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", localTime);
//     if (date > buffer) {
// 		return false;
// 	}
// 	return true;
// }