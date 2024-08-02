/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:11:45 by awilliam          #+#    #+#             */
/*   Updated: 2024/07/22 16:56:03 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()) {
	this->_grade = other.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& oldInstance) {
	if (this != &oldInstance)
	{
		this->_grade = oldInstance.getGrade();
	}
	return (*this);
}

void    Bureaucrat::promote() {
	std::cout << this->getName() << " is receiving a promotion :)" << std::endl;
	if (this->_grade > MAX_GRADE)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void    Bureaucrat::demote() {
	std::cout << this->getName() << " is receiving a demotion :(" << std::endl;
	if (this->_grade < MIN_GRADE)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(Form &toSign) {
	toSign.beSigned(*this);
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