/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:50:00 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/02 15:17:38 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

// TODO - add nice colors
//		- add .o files to gitignore
int main(void) {
	try {
		Bureaucrat charlie("Manfred", 2);

		// Promote once to grade 1
		std::cout << charlie << std::endl;
		charlie.promote();
		std::cout << std::endl;

		// Second promotion is impossible, so we expect an exception to be thrown
		std::cout << charlie << std::endl;
		charlie.promote();
		std::cout << std::endl;

	} catch (const std::exception & e) {
		std::cout << "Caught exception: " << e.what() << std::endl << std::endl;
	}

	// Test
	try {
		Bureaucrat hansDieter("Hans-Dieter", 149);
		std::cout << hansDieter << std::endl << std::endl;

		// First demotion, Hans-Dieter now has a grade of 150
		hansDieter.demote();
		std::cout << hansDieter << std::endl << std::endl;

		// Second demotion, we now expect an exception to be thrown
		hansDieter.demote();
		std::cout << hansDieter << std::endl;
		hansDieter.promote();
		std::cout << std::endl;

	} catch (const std::exception & e) {
		std::cout << "Caught exception: " << e.what() << std::endl << std::endl;
	}

	try {
		// Instantiating a Bureaucrat with a grade higher than 1 should throw an exception!
		Bureaucrat presidentOfTheUniverse("Mr. President", 0);
	} catch (const std::exception & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try {
		// Instantiating a Bureaucrat with a grade lower than 0 should throw an exception!
		Bureaucrat presidentOfTheUniverse("Stephen the Intern", 151);
	} catch (const std::exception & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}