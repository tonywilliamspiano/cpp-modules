/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:29:09 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/12 17:12:07 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
        : AForm("robotomy request", 72, 45), _target(target) {
    this->_signed = false;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &f)
        : AForm("robotomy request", 72, 45), _target(f._target) {
    this->_signed = f.getSignedStatus();
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &oldInstance) {
    if (this != &oldInstance)
        this->_signed = oldInstance.getSignedStatus();
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    // std::out << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::beSigned(const Bureaucrat &signer) {
    if (signer.getGrade() <= this->getSignGrade()) {
        this->_signed = true;
        std::cout << MAGENTA << "Robotomy Request Form" << GREEN << " signed by " << CYAN << signer.getName() << RESET
                  << std::endl;
    } else {
        throw AForm::GradeTooLowException();
    }
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    this->checkGradeAndSignedStatus(executor);

    std::srand(static_cast<unsigned int>(std::time(0)));
    int num = std::rand() % 2;

    std::cout << YELLOW << "* LOUD DRILLING NOISES *" << std::endl;
    if (num == 0) {
        std::cout << MAGENTA << this->_target << GREEN << " was successfully robotomized by " << CYAN
                  << executor.getName() << RESET << std::endl;
    } else {
        std::cout << RED << "Robotimization of " << MAGENTA << this->_target << RED << " by " << CYAN
                  << executor.getName() << RED << " failed!" << RESET << std::endl;
    }
    std::cout << YELLOW << "* Drilling noises fade... *" << std::endl;
}