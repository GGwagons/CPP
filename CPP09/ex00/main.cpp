/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwagons <ggwagons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:00:08 by ggwagons          #+#    #+#             */
/*   Updated: 2024/12/01 19:09:28 by ggwagons         ###   ########.fr       */
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
		throw std::runtime_error("Error: could not open file");
	}
}

int main (int argc, char **argv) {
	try {
		std::map<std::string, float> csv;
		checkInput(argc, argv[1], "data.csv");
		csvValue("data.csv", csv);
		inputValue(argv[1], csv);		
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}