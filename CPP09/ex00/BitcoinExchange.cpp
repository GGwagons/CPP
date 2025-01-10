/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:56:01 by ggwagons          #+#    #+#             */
/*   Updated: 2025/01/10 16:46:07 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool getTime(Split &s) {
	std::time_t now = std::time(NULL);
    std::tm *localTime = std::localtime(&now);
    char timeBuffer[11];
    std::strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d", localTime);
    std::string buffer = static_cast<std::string>(timeBuffer);
	int Year = std::atoi(buffer.substr(0, 4).c_str());
	int Month = std::atoi(buffer.substr(5, 2).c_str());
	int Day = std::atoi(buffer.substr(8, 2).c_str());
	if (s._year > Year) return false;

    // Compare months (if years are equal)
    if (s._year == Year && s._month > Month) return false;

    // Compare days (if years and months are equal)
    if (s._year == Year && s._month == Month && s._day > Day) return false;

    // If all checks pass, the date is valid
    return true;
}

bool dayWalker(Split &s) {
	if (s._month <= 5) {
		if (s._month <= 5 && s._month % 2 == 0 && s._day > 30) {return false;}
		else {if (s._month <= 5 && s._month % 2 != 0 && s._day > 31) {return false;}};
	}
	else {
		if (((s._month > 5 && s._month % 2 == 0) && s._month != 6) && s._day > 31) {return false;}
		else {if (((s._month > 5 && s._month % 2 != 0) && (s._month != 7 || s._month == 6)) && s._day > 30) {return false;}};
	}
	return true;
}

bool howRate(Split &s, std::string &value) {
	s.value = value;
	std::stringstream fss(s.value);
	fss >> s._fvalue;
	// std::cout << "Value: [" << s._fvalue << "]" << std::endl;
	if (s._fvalue < 0 || !fss.eof() || fss.fail()) {
		// std::cout << "Error: invalid value format => " << value << std::endl;
		return false;
	}
	return true;
}

bool howMuch(Split &s, std::string &value) {
	s.value = value;
	std::stringstream fss(s.value);
	fss >> s._fvalue;
	if (s._fvalue < 0 || s._fvalue > 1000 || !fss.eof() || fss.fail()) {
		return false;
	}
	return true;
}
