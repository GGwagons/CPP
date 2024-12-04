/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:56:17 by ggwagons          #+#    #+#             */
/*   Updated: 2024/12/04 20:04:41 by miturk           ###   ########.fr       */
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

template <typename T>
class BitcoinExchange {
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();
	public:
		void inputValue(const T &input, std::map<std::string, float> &csv, Split &s);
		void csvValue(const T &input, std::map<std::string, float> &csv);
		std::string theDate(const std::map<std::string, float> &csv, const T &date);
		bool checkDate(T &date, Split &s);
		bool theSetter(T &s);
		bool getTime(Split &s);	
};
bool getTime(Split &s);
bool dayWalker(Split &s);

template <typename T>
bool howRate(T &s) {
	std::stringstream fss(s.value);
	fss >> s._fvalue;
	// std::cout << "[" << s._fvalue << "]" << std::endl;
	if (s._fvalue < 0 || !fss.eof() || fss.fail()) {
		return false;
	}
	return true;
}

template <typename T>
bool howMuch(T &s) {
	std::stringstream fss(s.value);
	fss >> s._fvalue;
	// std::cout << "[" << s._fvalue << "]" << std::endl;
	if (s._fvalue < 0 || s._fvalue > 1000 || !fss.eof() || fss.fail()) {
		return false;
	}
	return true;
}

template <typename T>
bool checkDate(T &date, Split &s) {
	date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
	if (date.size()!= 10 || date.find_first_of('-') != 4 || date.find_last_of('-') != 7) {return false;}
	else {
		s._year = std::atoi(date.substr(0, 4).c_str());
		s._month = std::atoi(date.substr(5, 2).c_str());
		if (s._month < 1 || s._month > 12) {return false;}
		s._day = std::atoi(date.substr(8, 2).c_str());
        int leap = (s._year % 4 == 0 && (s._year % 400 == 0 || s._year % 100 != 0)) ? 1 : 0;
        if (leap == 1 && s._month == 2 && s._day > 29) {return false;}
        else {if (leap == 0 && s._month == 2 && s._day > 28) {return false;}};
		if (dayWalker(s) == false) {return false;}
	}
	return true;
}

template <typename T>
void csvValue(const T &input, std::map<std::string, float> &csv, Split &s) {
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
            if (checkDate(date, s) == true) {
				if (getTime(s) == false) {
					std::cerr << "Error: How can you see into the future => " << date << std::endl;
					continue;
				}
            }
			else {
				std::cerr << "Error: invalid date format => " << date << std::endl;
				continue;
			}
			if (howRate(s) == false) {
				std::cerr << "Error: invalid value format => " << value << std::endl;
				continue;
			}
			
            float f = std::atof(value.c_str());
            csv[date] = f;
        }
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
        throw std::runtime_error("Error: could not open file");
    }
    std::string line;
    std::getline(file, line);
    while (line.empty()) {
        if (std::getline(file, line).eof()) {
            throw std::runtime_error("Error: empty file");
        }
    }
    if(line.find("date | value") == std::string::npos) {
		std::cerr << "Error: invalid file format => " << line;
        throw std::runtime_error("");
    }
    while (std::getline(file, line)) {
        if (line.find("date | value") != std::string::npos) {
			std::cerr << "Error: invalid file format => [" << line << "] x2";
            throw std::runtime_error("");
        }
		if (line.empty()) {continue;}
        std::istringstream ss(line.c_str()); std::string date; std::string value;
        if (std::getline(ss, date, '|') &&  std::getline(ss, value)) {
            if (checkDate(date, s) == true) {
				if (getTime(s) == false) {
					std::cerr << "Error: why do you want to know the future => " << date << std::endl;
					continue;
				}
			}
			else {
				std::cerr << "Error: invalid date format => " << date << std::endl;
				continue;
			}
			date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
			value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
			s.value = value;
			if (howMuch(s) == false) {
				std::cerr << "Error: invalid value format => " << value << std::endl;
				continue;
			}
            std::string closeDate = theDate(csv, date);
            if (closeDate.empty()) {
				std::cerr << "Error: no data for date => " << date << std::endl;
                continue;
            }
            float value = csv.at(closeDate);
			if (value < 0) {
				std::cerr << "Error: invalid value" << std::endl;
				continue;
			}
			float res;
			res = s._fvalue * value;
            std::ostringstream output;
            output << std::fixed << std::setprecision(2) << res;
            std::cout << date << " => " << s.value << " = " << output.str() << std::endl;
        }
		else {
			std::cerr << "Error: invalid format => " << line << std::endl;
			continue;
		}
    }
    file.close();
}

#endif