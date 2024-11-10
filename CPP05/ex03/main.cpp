/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:29:56 by miturk            #+#    #+#             */
/*   Updated: 2024/11/10 13:12:42 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* form;

    // Request a RobotomyRequestForm for "Bender"
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        delete form;
    }

    form = someRandomIntern.makeForm("unknown form", "Target");
    if (form) {
        delete form;
    }

    return 0;
}