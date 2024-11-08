/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:29:35 by miturk            #+#    #+#             */
/*   Updated: 2024/11/08 17:14:28 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
	private:
		std::string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;
	protected:
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
	public:
		AForm();
		AForm(AForm const &copy);
		virtual ~AForm();
		AForm &operator=(AForm const &copy);
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat const &buro);
		virtual void execute(Bureaucrat const &executor) const = 0;
		class FormNotSignedException {
			public:
				virtual const char *what() const throw();
		};
		class FormSignedException {
			public:
				virtual const char *what() const throw();
		};
};
std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif