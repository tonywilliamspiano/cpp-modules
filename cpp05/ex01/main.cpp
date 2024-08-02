#include "Bureaucrat.hpp"
#include <iostream>

// TODO - Double check formatting and style
// 		- Double check with instructions from PDF
// 		- Commit and push
//		- Add 42 headers
int main(void)
{
	try {
		Bureaucrat charlie("Charlie", 2);
		Bureaucrat lisa("Lisa", 130);
		Form jobApp("Job Appl.", 100, 20);

		std::cout << jobApp << std::endl;
		charlie.signForm(jobApp);
		std::cout << jobApp << std::endl;
		lisa.signForm(jobApp);
		std::cout << jobApp << std::endl;
	} catch (const std::exception & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}