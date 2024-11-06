/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:18:01 by miturk            #+#    #+#             */
/*   Updated: 2024/11/06 16:46:53 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
	protected:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		virtual ~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &copy);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm();
		class GradeTooHighException {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException {
			public:
				virtual const char *what() const throw();
		};
};
std::ostream &operator<<(std::ostream &out, Bureaucrat const &biro);


#endif