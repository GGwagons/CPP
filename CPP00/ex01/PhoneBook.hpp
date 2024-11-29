/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:49:27 by miturk            #+#    #+#             */
/*   Updated: 2024/10/05 15:54:50 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"
class Contact;

class	PhoneBook {
	private:
			Contact		_contacts[8];
			int			_index;
			void		_number(std::string &input);
			void		_printCheck(std::string &str);
			void		_checkEmpty(std::string &input);
			void		_checkTab(std::string &input);
			int			_isTab(int c);
			int			_justSpace(std::string &input);
	public:
			PhoneBook();
			~PhoneBook();
			void		search();
			void		add();
			void		size(Contact &mCont);
			std::string	getContacts() const;
};
#endif