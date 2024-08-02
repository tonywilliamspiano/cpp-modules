#include <iostream>
#include "Bureaucrat.hpp"

// TODO - Double check formatting and style
// 		- Double check with instructions from PDF
// 		- Commit and push
//		- Add 42 headers
int main(void) {
	try {
		Bureaucrat charlie("Manfred", 2);

		// Promote once to grade 1
		std::cout << charlie << std::endl;
		charlie.promote();

		// Second promotion is impossible, so we expect an exception to be thrown
		std::cout << charlie << std::endl;
		charlie.promote();
	}
	catch (const std::exception & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	// Test
	try {
		Bureaucrat hansDieter("Hans-Dieter", 149);
		std::cout << hansDieter << std::endl;

		// First demotion, Hans-Dieter now has a grade of 150
		hansDieter.demote();
		std::cout << hansDieter << std::endl;

		// Second demotion, we now expect an exception to be thrown
		hansDieter.demote();
		std::cout << hansDieter << std::endl;
		hansDieter.promote();
	}
	catch (const std::exception & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat presidentOfTheUniverse("Mr. President", 0);
	}
	catch (const std::exception & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat presidentOfTheUniverse("Stephen the Intern", 151);
	}
	catch (const std::exception & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}