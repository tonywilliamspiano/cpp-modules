/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:07:33 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/02 15:36:29 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

// TODO - Add nice colors
// 		- Commit and push
int main(void)
{
	try {
		Bureaucrat charlie("Charlie", 2);
		Bureaucrat lisa("Lisa", 130);
		Form jobApp("Job Appl.", 100, 20);

		std::cout << jobApp << std::endl << std::endl;

		charlie.signForm(jobApp);
		std::cout << jobApp << std::endl << std::endl;

		lisa.signForm(jobApp);
		std::cout << jobApp << std::endl << std::endl;

		// Should throw exception, because the grade is too low:
		Form tooHighForm("Too high", 100, 160);
	} catch (const std::exception & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try {
		// Should throw exception, because the grade is too high:
		Form tooLowForm("Too low", -1, 100);
	} catch (const std::exception & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}