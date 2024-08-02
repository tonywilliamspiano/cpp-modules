/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:01 by awilliam          #+#    #+#             */
/*   Updated: 2023/07/24 18:33:19 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "colors.hpp"
#include "Intern.hpp" 

// TODO - Add 42 headers
//  	- Double check formatting and style
// 		- Double check with instructions from PDF
// 		- Commit and push
int main(void)
{
    Intern  someRandomIntern;
    AForm*   shrubberyCreationForm;
    AForm*   robotomyRequestForm;
    AForm*   presidentialPardonForm;
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
    }
    catch (const std::exception & e) {
        std::cout << YELLOW << "Caught exception: " << e.what() << RESET << std::endl;
    }
    if (shrubberyCreationForm)
        delete shrubberyCreationForm;
	if (robotomyRequestForm)
		delete robotomyRequestForm;
}