/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:56:17 by ggwagons          #+#    #+#             */
/*   Updated: 2024/12/02 17:46:46 by miturk           ###   ########.fr       */
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
bool theSetter(T &s) {
    s._fvalue = std::atof(s.value.c_str());
	if (s._fvalue < 0 || s._fvalue > 1000) {
		return false;
	}
	return true;
}

template <typename T>
bool checkDate(T &date) {
	Split s;
	std::time_t now = std::time(NULL);
    std::tm *localTime = std::localtime(&now);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", localTime);
	std::string buffer = static_cast<std::string>(buffer);
	int Day = std::atoi(buffer.c_str().substr(8, 2));
	int Month = std::atoi(buffer.substr(5, 2).c_str());
	int Year = std::atoi(buffer.substr(0, 4).c_str());
	
	date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
	if (date.size()!= 10 || date.find_first_of('-') != 4 || date.find_last_of('-') != 7) {return false;}
	else {
		s._year = std::atoi(date.substr(0, 4).c_str());
		if (s._year < 2009 || s._year > 2024) {return false;}
		s._month = std::atoi(date.substr(5, 2).c_str());
		if (s._month < 1 || s._month > 12) {return false;}
		s._day = std::atoi(date.substr(8, 2).c_str());
		if (s._day < 1 || s._day > 31) {return false;}
	}
	if (Year >= s._year) {
		if (Month >= s._month) {
			if (Day >= s._day) {return true;}
		}
	}
	return true;
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
            float f = std::atof(value.c_str());
            csv[date] = f;
        }
    }
}

template <typename T>
std::string theDate(const std::map<std::string, float> &csv, const T &date) {
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
    if(line.find("date | value") == std::string::npos) {
		std::cerr << "Error: invalid file format => " << line;
        throw std::runtime_error("");
    }
    while (std::getline(file, line)) {
        if (line.find("date | value") != std::string::npos) {
			std::cerr << "Error: invalid file format => [" << line << "] x2";
            throw std::runtime_error("");
        }
        std::istringstream ss(line.c_str());
        std::string date; std::string value;
        if (std::getline(ss, date, '|') &&  std::getline(ss, value)) {
            if (checkDate(date) == false) {
				std::cerr << "Error: invalid date format => " << date << std::endl;
				continue;
			}
			date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
			value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
			s.value = value;
			if (theSetter(s) == false) {
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

template <typename T>
class BitcoinExchange {
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();
	public:
		void inputValue(const T &input, std::map<std::string, float> &csv);
		void csvValue(const T &input, std::map<std::string, float> &csv);
		std::string theDate(const std::map<std::string, float> &csv, const T &date);
		bool checkDate(T &date);
		bool theSetter(T &s);
		bool getTime();	
};

#endif
