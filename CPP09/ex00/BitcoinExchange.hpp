/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:56:17 by ggwagons          #+#    #+#             */
/*   Updated: 2025/01/10 16:50:50 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include <fstream>
# include <string>
# include <ctime>

# include <algorithm>
# include <iterator>
# include <map>

typedef struct s_Split {
	std::string date;
    std::string	year;
    std::string	month;
    std::string	day;
    std::string	value;
    int			_year;
    int			_month;
    int			_day;
    float		_fvalue;
} Split;

bool dayWalker(Split &s);
bool getTime(Split &s);
bool howMuch(Split &s, std::string &value);
bool howRate(Split &s, std::string &value);

template <typename T>
bool checkDate(T &date, Split &s) {
	date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
	// std::cout << "Date: [" << date << "]" << std::endl;
	if (date.size()!= 10 || date.find_first_of('-') != 4 || date.find_last_of('-') != 7) {return false;}
	else {
		s._year = std::atoi(date.substr(0, 4).c_str());
		if (s._year < 0) {return false;}
		s._month = std::atoi(date.substr(5, 2).c_str());
		if (s._month < 1 || s._month > 12) {return false;}
		s._day = std::atoi(date.substr(8, 2).c_str());
		if (s._day < 1 || s._day > 31) {return false;}
        int leap = (s._year % 4 == 0 && (s._year % 400 == 0 || s._year % 100 != 0)) ? 1 : 0;
        if (leap == 1 && s._month == 2 && s._day > 29) {std::cerr << "Leap year: "; return false;}
        else {if (leap == 0 && s._month == 2 && s._day > 28) {std::cerr << "Not a Leap year: "; return false;}};
		if (dayWalker(s) == false) {return false;}
	}
	return true;
}

template <typename T>
void csvValue(const T &input, std::map<std::string, float> &csv, Split &s) {
	int flag = 0;
	int i = 0;
    std::ifstream file(input);
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file");
    }
    std::string line;
    std::getline(file, line);
    while (i++, line.empty()) {
		
        if (std::getline(file, line).eof()) {
            throw std::runtime_error("Error: empty file");
        }
    }
    while (i++, std::getline(file, line)) {
		if (flag == 1) {
			std::cout << std::endl;
		}
		flag = 0;
        std::istringstream ss(line.c_str());
        std::string date; std::string value;
        if (std::getline(ss, date, ',') &&  std::getline(ss, value)) {
            if (checkDate(date, s) == true) {
				if (getTime(s) == false) {
					std::cerr << "Error: DataBase: index: [" << i << "] => Values: [" << line << "]";
					flag = 1;
					continue;
				}
            }
			else {
				std::cerr << "Error: DataBase: index: [" << i << "] => Values: [" << line << "]";
				flag = 1;
				continue;
			}
			if (howRate(s, value) == false) {
				std::cerr << "Error: DataBase: index: [" << i << "] => Values: [" << line << "]";
				flag = 1;
				continue;
			}
            float f = std::atof(value.c_str());
            csv[date] = f;
        }
    }
	if (flag == 1) {
		throw std::runtime_error("");
	}
}

template <typename T>
std::string theDate(const std::map<std::string, float> &csv, T &date) {
    std::map<std::string, float>::const_iterator it = csv.lower_bound(date);
    if (it == csv.end() || it->first != date) {
        if (it == csv.begin()) {
            return "";
        }
        --it;
    }
    return it->first;
}

template <typename T>
void inputValue(const T &input, std::map<std::string, float> &csv, Split &s) {
    std::ifstream file(input);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could Not Open File");
    }
    std::string line;
    std::getline(file, line);
    while (line.empty()) {
        if (std::getline(file, line).eof()) {
            throw std::runtime_error("Error: Empty File");
        }
    }
    if(line.find("date | value") == std::string::npos) {
		std::cerr << "Error: Invalid File Format => " << line;
        throw std::runtime_error("");
    }
    while (std::getline(file, line)) {
        if (line.find("date | value") != std::string::npos) {
			std::cerr << "Error: Invalid File Format => [" << line << "] x2";
            throw std::runtime_error("");
        }
		if (line.empty()) {continue;}
        std::istringstream ss(line.c_str()); std::string date; std::string value;
        if (std::getline(ss, date, '|') &&  std::getline(ss, value)) {
			date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
			if (checkDate(date, s) == false) {
				std::cerr << "Error: Invalid Date format => " << date << std::endl;
				continue;
			}
			value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
			if (howMuch(s, value) == false) {
				std::cerr << "Error: Invalid value format => " << value << std::endl;
				continue;
			}
            std::string closeDate = theDate(csv, date);
            if (closeDate.empty()) {
				std::cerr << "Error: No Data For Date => " << date << std::endl;
                continue;
            }
            float value = csv.at(closeDate);
			float res;
			res = s._fvalue * value;
			std::ostringstream out_t;
            out_t << std::fixed << std::setprecision(2) << res;
            std::cout << date << " => " << s.value << " = " << out_t.str() << std::endl;
        }
		else {
			std::cerr << "Error: Invalid format => " << line << std::endl;
			continue;
		}
    }
    file.close();
}

#endif