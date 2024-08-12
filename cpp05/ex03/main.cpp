/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:33:19 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/12 17:17:18 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "colors.hpp"
#include "Intern.hpp"

int main(void) {
    Intern someRandomIntern;
    AForm *shrubberyCreationForm;
    AForm *robotomyRequestForm;
    AForm *presidentialPardonForm;
    Bureaucrat charlie("Charlie", 4);

    try {
        shrubberyCreationForm = someRandomIntern.makeForm("shrubbery creation", "Lancelot");
        charlie.signForm(*shrubberyCreationForm);
        charlie.executeForm(*shrubberyCreationForm);

        std::cout << std::endl;

        robotomyRequestForm = someRandomIntern.makeForm("robotomy request", "Bender");
        charlie.signForm(*robotomyRequestForm);
        charlie.executeForm(*robotomyRequestForm);

        std::cout << std::endl;
        someRandomIntern.makeForm("nonexistent form", "Nonexistent Person");

        presidentialPardonForm = someRandomIntern.makeForm("presidential pardon", "Richard Nixon");
        charlie.signForm(*presidentialPardonForm);
        charlie.executeForm(*presidentialPardonForm);
    } catch (const std::exception &e) {
        std::cout << YELLOW << "Caught exception: " << e.what() << RESET << std::endl;
    }

    if (shrubberyCreationForm) {
        delete shrubberyCreationForm;
    }

    if (robotomyRequestForm) {
        delete robotomyRequestForm;
    }
}