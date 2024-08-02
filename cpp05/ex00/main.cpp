#include <iostream>
#include "Bureaucrat.hpp"

// TODO - Add 42 headers
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
		Bureaucrat presidentOfTheUniverse("Mr. President", 0);
	} catch (const std::exception & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat presidentOfTheUniverse("Stephen the Intern", 151);
	} catch (const std::exception & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}