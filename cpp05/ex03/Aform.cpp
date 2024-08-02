/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:08:55 by awilliam          #+#    #+#             */
/*   Updated: 2023/07/21 09:39:00 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade) 
: _name(name), _gradeRequiredToSign(signGrade), _gradeRequiredToExecute(execGrade) {
    this->_signed = false;
}


AForm::~AForm() {
    // std::out << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm& f) 
: _name(f.getName()), _gradeRequiredToSign(f.getSignGrade()), _gradeRequiredToExecute(f.getExecuteGrade()) {
    this->_signed = f.getSignedStatus();
}

AForm& AForm::operator=(const AForm& oldInstance) {
    if (this != &oldInstance) {
        this->_signed = oldInstance.getSignedStatus();
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

void AForm::execute(const Bureaucrat& executor) const {
    if (this->getSignedStatus() == false)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
}

const char * AForm::GradeTooLowException::what() const throw() {
    return ("Grade too low to sign form!");
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