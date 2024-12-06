/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwagons <ggwagons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:07:48 by miturk            #+#    #+#             */
/*   Updated: 2024/12/06 20:45:41 by ggwagons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int runOne(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		std::string filename = argv[i];
		std::fstream file(filename.c_str());
		if (file.is_open()) {
			if (runTwo(file) == 1) {
				return (1);
			}
			return (0);
		}
		try {
			RPN rpn;
			std::string call = argv[i];
			std::cout << "T: " << call << std::endl;
			std::string token;
			std::istringstream iss(call);
			for (std::string token; iss >> token;) {
				rpn.readInput(token);
			}
			if (iss.eof()) {
				rpn.getStack();
			}
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
			if (argc < 3 && argv[i + 1] == NULL) {
				return (1);
			}
			continue;
		}
	}
	return (0);
}

int runTwo(std::fstream &file) {
	std::string line;
	while (std::getline(file, line)) {
		line.erase(std::remove(line.begin(), line.end(), '"'), line.end());
		if (line.empty()) {
			continue;
		}
		if (line[0] == '[') {
			std::cout << line << std::endl;
			continue;
		}
		std::cout << "T: " << line << std::endl;
		try {
			RPN rpn;
			std::string call = line;
			std::string token;
			std::istringstream iss(call);
			for (std::string token; iss >> token;) {
				rpn.readInput(token);
			}
			if (iss.eof()) {
				rpn.getStack();
			}
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
			if (file.eof()) {
				return (1);
			}
			continue;
		}
	}
	return (0);
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << "Usage: [./RPN [...] ]" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::fstream file(filename.c_str());
	if (!file.is_open()) {
		if (runOne(argc, argv) == 1) {
			return (1);
		}
	}
	else {
		if (argc != 2) {
			std::cerr << "Usage: ./RPN [...].txt" << std::endl;
			return (1);
		}
		if (runTwo(file) == 1) {
			return (1);
		}
	}
	return (0);
}