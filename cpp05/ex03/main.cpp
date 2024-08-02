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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "colors.hpp"
#include "Intern.hpp" 

int main(void)
{
    Intern  someRandomIntern;
    AForm*   scf = NULL;
    Bureaucrat charlie("Charlie", 4);

    try
    {
        scf = someRandomIntern.makeForm("shrubbery creation", "Lancelot");
        charlie.signForm(*scf);
        charlie.executeForm(*scf);
    }
    catch (const std::exception & e)
    {
        std::cout << YELLOW << "Caught exception: " << e.what() << RESET << std::endl;
    }
    if (scf != NULL)
        delete scf;
}