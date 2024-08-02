/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:16:44 by awilliam          #+#    #+#             */
/*   Updated: 2024/07/22 17:06:38 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	this->_isSigned = false;
}

Form::Form(const Form& f)
		: _name(f.getName()), _gradeToSign(f.getGradeToSign()), _gradeToExecute(f.getGradeToExecute()) {
	this->_isSigned = f.getIsSigned();
}

Form& Form::operator=(const Form& oldInstance) {
	if (this != &oldInstance) {
		this->_isSigned = oldInstance.getIsSigned();
	}
	return (*this);
}

Form::~Form() {
//	std::cout << "Form destructor called." << std::endl;
}

void    Form::beSigned(const Bureaucrat& signer) {
	if (signer.getGrade() <= this->getGradeToSign()) {
		this->_isSigned = true;
		std::cout << "Form " << this->getName() << " signed by " << signer.getName() << std::endl;
	}
	else
		throw Form::GradeTooLowException();
}

const std::string& Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

std::ostream& operator<<(std::ostream& stream, const Form& instance)
{
	stream << "Form name: " << instance.getName() << std::endl;
	stream << "Grade to execute: " << instance.getGradeToExecute() << std::endl;
	stream << "Form name: " << instance.getGradeToSign() << std::endl;
	stream << "Is the form signed? ";

	std::string signedStatus = instance.getIsSigned() ? "Yes :)" : "No :(";
	stream << signedStatus;

	return (stream);
}

// Exceptions

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}
