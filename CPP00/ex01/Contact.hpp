/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:49:24 by miturk            #+#    #+#             */
/*   Updated: 2024/10/03 14:16:56 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class	Contact {
	private:
			std::string	_name;
			std::string	_lastName;
			std::string	_nickName;
			std::string	_num;
			std::string	_darkestSecrets;
			std::string	setField(std::string &str);
	public:
			Contact();
			~Contact();
			void		printContact();
			void		printLine();
			void		setName(std::string name);
			void		setLastName(std::string lastName);
			void		setNickName(std::string nickName);
			void		setNum(std::string num);
			void		setDarkestSecrets(std::string darkestSecrets);
			// std::string getContact();
};
#endif