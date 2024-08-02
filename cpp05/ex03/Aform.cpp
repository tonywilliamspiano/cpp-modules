/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:07:12 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/02 15:47:06 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade) 
: _name(name), _gradeRequiredToSign(signGrade), _gradeRequiredToExecute(execGrade) {
    this->_signed = false;

	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE) {
		throw AForm::GradeTooHighException();
	}
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE) {
		throw AForm::GradeTooLowException();
	}
}


AForm::~AForm() {
    // std::out << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm& rhs)
: _name(rhs.getName()), _gradeRequiredToSign(rhs.getSignGrade()), _gradeRequiredToExecute(rhs.getExecuteGrade()) {
    this->_signed = rhs.getSignedStatus();
}

AForm& AForm::operator=(const AForm& rhs) {
    if (this != &rhs) {
        this->_signed = rhs.getSignedStatus();
    }
    return (*this);
}

std::string AForm::getName() const {
    return (this->_name);
}

bool AForm::getSignedStatus() const {
    return (this->_signed);
}

int AForm::getSignGrade() const {
    return (this->_gradeRequiredToSign);
}

int AForm::getExecuteGrade() const {
    return (this->_gradeRequiredToExecute);
}

void AForm::checkGradeAndSignedStatus(const Bureaucrat& executor) const {
    if (this->getSignedStatus() == false)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
}

const char * AForm::GradeTooLowException::what() const throw() {
    return ("Grade too low!");
}

const char * AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char * AForm::NotSignedException::what() const throw() {
    return ("Cannot execute: Form not signed");
}


std::ostream& operator<<(std::ostream& stream, const AForm& instance) {
    stream << "Form name: " << instance.getName() << std::endl;
    stream << "Grade to execute: " << instance.getExecuteGrade() << std::endl;
    stream << "Form name: " << instance.getSignGrade() << std::endl;
    stream << "Is the form signed? ";
    if (instance.getSignedStatus())
        stream << "Yes :)";
    else
        stream << "No :(";
    return (stream);
}