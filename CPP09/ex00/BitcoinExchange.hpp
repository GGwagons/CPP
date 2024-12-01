/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwagons <ggwagons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:56:17 by ggwagons          #+#    #+#             */
/*   Updated: 2024/12/01 13:52:43 by ggwagons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include <fstream>
# include <algorithm>
# include <map>
# include <exception>
# include <sstream>
# include <cstdlib>

struct Split {
	std::string	year;
	std::string	month;
	std::string	day;
	std::string	value;
	int			_year;
	int			_month;
	int			_day;
	int			_value;
	float		_fvalue;
};

template <typename T>
void theSetter(T &s) {
	if (s.value.find('.') != std::string::npos) {
		s._fvalue = std::atof(s.value.c_str());
	}
	else {
		s._value = std::atoi(s.value.c_str());
	}
	s._year = std::atoi(s.year.c_str());
	std::cout << "YEAR: " << s._year << std::endl;
	if (s._year < 2000 || s._year > 2024) {
		std::cerr << "Error: invalid year format" << std::endl;
	}
	s._month = std::atoi(s.month.c_str());
	if (s._month < 1 || s._month > 12) {
		std::cerr << "Error: invalid month format" << std::endl;
	}
	s._day = std::atoi(s.day.c_str());
	if (s._day < 1 || s._day > 31) {
		std::cerr << "Error: invalid day format" << std::endl;
	}
}

template <typename T>
void checkDate(T &date) {
	Split s;
	date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
	if (date.size() != 10) {
		std::cerr << "Error: invalid date format" << std::endl;
	}
	if (date.find_first_of('-') != 4 || date.find_last_of('-') != 7) {
		std::cerr << "Error: invalid date format" << std::endl;
	}
	s.year = date.substr(0, 4);
	s.month = date.substr(5, 2);
	s.day = date.substr(8, 2);
	theSetter(s);
	std::cout << "Year: [" << s.year << "] Month: [" << s.month << "] Day: [" << s.day << "]" << std::endl;
}

template <typename T>
void csvValue(const T &input, std::map<std::string, float> &csv) {
	std::ifstream file(input);
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open file");
	}
	std::string line;
	std::getline(file, line);
	while (line.empty()) {
		if (std::getline(file, line).eof()) {
			throw std::runtime_error("Error: empty file");
		}
	}
	while (std::getline(file, line)) {
		std::istringstream ss(line.c_str());
		std::string date; std::string value;
		if (std::getline(ss, date, ',') &&  std::getline(ss, value)) {
			char *end;
			float f = std::strtof(value.c_str(), &end);
			if (*end != '\0') {
				std::cerr << "Error: invalid value" << std::endl;
			}
			csv[date] = f;
			// std::cout << "Date: " << date << " Value: " << csv[date] << std::endl;
		}
	}
}

template <typename T>
void inputValue(const T &input, std::map<std::string, float> &csv) {
	Split s;
	std::ifstream file(input);
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open file");
	}
	std::string line;
	std::getline(file, line);
	while (line.empty()) {
		if (std::getline(file, line).eof()) {
			throw std::runtime_error("Error: empty file");
		}
	}
	std::cout << line << std::endl;
	if(line.find("date | value") == std::string::npos) {
		throw std::runtime_error("Error: invalid file format");
	}
	(void)csv;
	while (std::getline(file, line)) {
		if (line.find("date | value") != std::string::npos) {throw std::runtime_error("Error: invalid file format");}
		std::istringstream ss(line.c_str());
		std::string date; std::string value;
		if (std::getline(ss, date, '|') &&  std::getline(ss, value)) {
			checkDate(date);
			char *end;
			float f = std::strtof(value.c_str(), &end);
			if (*end != '\0') {
				throw std::runtime_error("Error: invalid price"); //still working on it
			}
			csv[date] = f;
			std::cout << "Date: " << date << " Value: " << f << std::endl;
		}
	}
}

// template <typename T>
// class BitcoinExchange {
// 	private:
// 		int	_year;
// 		int	_month;
// 		int	_day;
// 		int	_value;
// 		float			_fvalue;
// 	public:
// 		BitcoinExchange();
// 		BitcoinExchange(const BitcoinExchange &copy);
// 		BitcoinExchange &operator=(const BitcoinExchange &copy);
// 		~BitcoinExchange();
// 		void setYear(int year);
// 		void setMonth(int month);
// 		void setDay(int day);
// 		void setValue(int value);
// 		void setFValue(float fvalue);
// };

#endif