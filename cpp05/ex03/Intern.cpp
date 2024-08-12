/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:33:12 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/12 17:16:37 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &rhs) {
    *this = rhs;
}

Intern &Intern::operator=(const Intern &rhs) {
    (void) rhs;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::_make_rrf(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::_make_scf(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::_make_ppf(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string type, std::string target) {
    AForm *form;

    if (type == "shrubbery creation")
        form = _make_scf(target);
    else if (type == "robotomy request")
        form = _make_rrf(target);
    else if (type == "presidential pardon")
        form = _make_ppf(target);
    else
        throw Intern::formTypeNotFoundException();

    std::cout << CYAN << "Intern creates " << GREEN << type << std::endl;

    return form;
}

const char *Intern::formTypeNotFoundException::what() const throw() {
    return "Form type not found!";
}