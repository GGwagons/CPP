/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:29:35 by miturk            #+#    #+#             */
/*   Updated: 2024/11/06 16:42:26 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form : public Bureaucrat {
	private:
		std::string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;
	public:
		Form();
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(Form const &copy);
		~Form();
		Form &operator=(Form const &copy);
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat const &buro);
		void execute(Bureaucrat const &executor) const;
		class FormNotSignedException {
			public:
				virtual const char *what() const throw();
		};
		class FormSignedException {
			public:
				virtual const char *what() const throw();
		};
};
std::ostream &operator<<(std::ostream &out, Form const &form);

#endif