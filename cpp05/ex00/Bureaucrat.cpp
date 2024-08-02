#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {
//	 std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : _name(rhs.getName()) {
	this->_grade = rhs.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this != &rhs) {
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

void Bureaucrat::promote() {
	std::cout << this->getName() << " is receiving a promotion :)" << std::endl;
	if (this->_grade > MAX_GRADE)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::demote() {
	std::cout << this->getName() << " is receiving a demotion :(" << std::endl;
	if (this->_grade < MIN_GRADE)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& instance) {
	stream << instance.getName() << " is a bureacrat with grade: " << instance.getGrade();
	return (stream);
}

//EXCEPTIONS

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}