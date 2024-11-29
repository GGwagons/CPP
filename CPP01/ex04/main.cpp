/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:00:02 by miturk            #+#    #+#             */
/*   Updated: 2024/10/18 13:04:12 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

class File;

int main(int argc, char **argv) {
	File file;
	(void)argv;
	if (argc != 4) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	for (int i = 0; argv[i] != NULL; i++) {
		if (argv[i][0] == '\0') {
			std::cerr << "Empty argument" << std::endl;
			return (1);
		}
	}
	file.setFileName(argv[1]);
	file.setToFind(argv[2]);
	file.setToReplace(argv[3]);
	file.readFile();
	return 0;
}