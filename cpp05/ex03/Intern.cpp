/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:05:06 by tony              #+#    #+#             */
/*   Updated: 2023/07/24 18:33:12 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& oldInstance) {
    *this = oldInstance;
}

Intern& Intern::operator=(const Intern& oldInstance) {
    (void) oldInstance;
    return (*this);
}

AForm * Intern::_make_rrf(std::string target) {
    return (new RobotomyRequestForm(target));
}

AForm * Intern::_make_scf(std::string target) {
    return (new ShrubberyCreationForm(target));
}
    
AForm * Intern::_make_ppf(std::string target) {
    return (new PresidentialPardonForm(target));
}

// TODO - Understand how this passing of functions works so I can explain it.
AForm * Intern::makeForm(std::string type, std::string target) {
    std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm	*(Intern::*make_form[3])(std::string target) = {
		&Intern::_make_scf,
		&Intern::_make_rrf,
		&Intern::_make_ppf,
	};

    for (int i = 0; i < 3; i++) {
        if (type == formTypes[i]) {
            std::cout << CYAN << "Intern creates " << GREEN << type << std::endl;
            return ((this->*make_form[i])(target));
        }
    }
    throw Intern::formTypeNotFoundException();
}

const char * Intern::formTypeNotFoundException::what() const throw() {
    return ("Form type not found!");
}