/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:02:54 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/02 15:16:03 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("robotomy request", 72, 45), _target(target) {
    this->_signed = false;
}


RobotomyRequestForm::~RobotomyRequestForm() {
    // std::out << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& f)
: AForm("robotomy request", 72, 45), _target(f._target) {
    this->_signed = f.getSignedStatus();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& oldInstance) {
    if (this != &oldInstance)
    {
        this->_signed = oldInstance.getSignedStatus();
    }
    return (*this);
}

void    RobotomyRequestForm::beSigned(const Bureaucrat& signer) {
    if (signer.getGrade() <= this->getSignGrade())
    {
        this->_signed = true;
        std::cout << MAGENTA <<  "Robotomy Request Form" << GREEN << " signed by " << CYAN << signer.getName() << RESET << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}

void RobotomyRequestForm::executeForm(const Bureaucrat& executor) const {
    std::srand(static_cast<unsigned int>(std::time(0)));

    int coin = std::rand() % 2;

    this->execute(executor);
    std::cout << YELLOW << "* LOUD DRILLING NOISES *" << std::endl;
    if (coin == 0)
        std::cout << MAGENTA << this->_target << GREEN << " was successfully robotomized by " << CYAN << executor.getName() << RESET << std::endl;
    else 
        std::cout << RED << "Robotimization of " << MAGENTA << this->_target << RED << " by " << CYAN << executor.getName() << RED << " failed!" << RESET << std::endl;
    std::cout << YELLOW << "* Drilling noises fade... *" << std::endl;
}