/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwagons <ggwagons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:00:08 by ggwagons          #+#    #+#             */
/*   Updated: 2024/12/04 22:33:05 by ggwagons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

template <typename AC, typename AV, typename CS>
void checkInput(AC count, AV &input, CS &value) {
	if (count != 2 || !input){
		throw std::runtime_error("Usage: ./btc [file_name]");
	}
	std::ifstream file(input);
	std::ifstream info(value);
	if (!file.is_open() || !info.is_open()){
		throw std::runtime_error("Error: Could Not Open File");
	}
}

int main (int argc, char **argv) {
	try {
		Split s;
		std::map<std::string, float> csv;
		checkInput(argc, argv[1], "data.csv");
		csvValue("data.csv", csv, s);
		inputValue(argv[1], csv, s);		
	}
	catch (std::runtime_error &e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}