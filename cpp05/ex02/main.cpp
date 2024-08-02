/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:26:54 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/02 15:48:35 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
# include "colors.hpp"

// TODO - Double check with instructions from PDF
//		- Add 42 headers
int main(void)
{
    try
    {
        Bureaucrat charlie("Charlie", 2);
        Bureaucrat lisa("Lisa", 148);
        ShrubberyCreationForm shrubbery = ShrubberyCreationForm("test");
        RobotomyRequestForm robotomy = RobotomyRequestForm("bender");
        PresidentialPardonForm pres = PresidentialPardonForm("Al Capone");

        charlie.signForm(shrubbery);
        std::cout << std::endl;
        charlie.executeForm(shrubbery);
        std::cout << std::endl;
        charlie.signForm(robotomy);
        std::cout << std::endl;
        charlie.executeForm(robotomy);
        std::cout << std::endl;
        charlie.signForm(pres);
        std::cout << std::endl;
        charlie.executeForm(pres);
        std::cout << std::endl;
        lisa.executeForm(shrubbery);
    }
    catch (const std::exception & e) {
        std::cout << YELLOW << "Caught exception: " << e.what() << RESET << std::endl;
    }
}