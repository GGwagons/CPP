/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:36:42 by miturk            #+#    #+#             */
/*   Updated: 2024/10/17 18:17:13 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string fileName, std::string toFind, std::string toReplace) : _fileName(fileName), _toFind(toFind), _toReplace(toReplace) {};

File::File() : _fileName(""), _toFind(""), _toReplace("") {};

File::~File() {};

void	File::setToFind(std::string toFind) {
	_toFind = toFind;
}

void	File::setToReplace(std::string toReplace) {
	_toReplace = toReplace;
}

void 	File::theSwitch(std::string &str, std::string _toFind, std::string _toReplace) {
	size_t pos = str.find(_toFind);
    while (pos != std::string::npos) {
        str = str.substr(0, pos) + _toReplace + str.substr(pos + _toFind.length());
        pos = str.find(_toFind, pos + _toReplace.length());
    }
}

void File::writerFile(std::ifstream &file, std::string newFileName) {
	std::string line;
	std::ofstream newFile(newFileName.c_str());
	while (std::getline(file, line)) {
		theSwitch(line, _toFind, _toReplace);
		newFile << line << std::endl;
	}
	newFile.close();
}

void	File::setFileName(std::string fileName) {
	_fileName = fileName;
}

void File::createFile(std::string str) {
	std::string fileName = str;
	std::ofstream file(fileName.c_str());
	if (!file.is_open()) {
		std::cout << "File not created" << std::endl;
		return ;
	}
	std::cout << "File created" << std::endl;
}

void	File::readFile() {
	std::ifstream file(_fileName.c_str());
	if (!file.is_open()) {
		std::cout << "File not found" << std::endl;
		return ;
	}
	std::string newFileName = _fileName + ".replace";
	createFile(newFileName);
	writerFile(file, newFileName);
	file.close();
}