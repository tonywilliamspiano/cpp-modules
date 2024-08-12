/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:16:44 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/12 16:50:51 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	this->_isSigned = false;

	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE) {
		throw Form::GradeTooHighException();
	}
	if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE) {
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form& rhs)
		: _name(rhs.getName()), _gradeToSign(rhs.getGradeToSign()), _gradeToExecute(rhs.getGradeToExecute()) {
	this->_isSigned = rhs.getIsSigned();
}

Form& Form::operator=(const Form& rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs.getIsSigned();
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
	} else {
		std::cout << signer.getName() << " could not sign Form " << this->getName() << " because their grade is too low" << std::endl;
	}
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
	stream << "Grade to sign: " << instance.getGradeToSign() << std::endl;
	stream << "Grade to execute: " << instance.getGradeToExecute() << std::endl;
	stream << "Is the form signed? " << (instance.getIsSigned() ? "Yes :)" : "No :(") << std::endl;

	return stream;
}

// Exceptions

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}
