/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:04 by awilliam          #+#    #+#             */
/*   Updated: 2023/07/24 12:29:06 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
: AForm("presidential pardon", 25, 5), _target(target) {
    this->_signed = false;
}


PresidentialPardonForm::~PresidentialPardonForm() {
    // std::out << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& f)
: AForm("presidential pardon", 25, 5), _target(f._target) {
    this->_signed = f.getSignedStatus();
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& oldInstance) {
    if (this != &oldInstance)
    {
        this->_signed = oldInstance.getSignedStatus();
    }
    return (*this);
}

void    PresidentialPardonForm::beSigned(const Bureaucrat& signer) {
    if (signer.getGrade() <= this->getSignGrade())
    {
        this->_signed = true;
        std::cout << MAGENTA << "Presidential Pardon Form" << GREEN << " signed by " << CYAN << signer.getName() << RESET << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    std::cout << MAGENTA << this->_target << GREEN << " was pardoned by " << CYAN << "Zaphod Beeblebrox, " << GREEN
		<< "form signed by " << CYAN << executor.getName() << RESET << std::endl;
}