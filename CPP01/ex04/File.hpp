/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:03:01 by miturk            #+#    #+#             */
/*   Updated: 2024/10/16 14:25:51 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
# define FILE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <iomanip>

class File {
	private:
		std::string _fileName;
		std::string _toFind;
		std::string _toReplace;
	public:
		File(std::string fileName, std::string toFind, std::string toReplace);
		std::string	getFileName();
		std::string	getToFind();
		std::string	getToReplace();
		File();
		~File();
		void		setFileName(std::string fileName);
		void		setToFind(std::string toFind);
		void		setToReplace(std::string toReplace);
		void 		theSwitch(std::string &str, std::string _toFind, std::string _toReplace);
		void		readFile();
		void 		createFile(std::string str);
		void		writerFile(std::ifstream &file, std::string newFileName);
};

#endif