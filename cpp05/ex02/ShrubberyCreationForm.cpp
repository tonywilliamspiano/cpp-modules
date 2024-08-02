/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:10 by awilliam          #+#    #+#             */
/*   Updated: 2023/07/24 12:29:12 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
: AForm("shrubbery creation", 145, 137), _target(target)
{
    this->_signed = false;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
    // std::out << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& f)
: AForm("shrubbery creation", 145, 137), _target(f._target)
{
    this->_signed = f.getSignedStatus();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& oldInstance)
{
    if (this != &oldInstance)
    {
        this->_signed = oldInstance.getSignedStatus();
    }
    return (*this);
}

void    ShrubberyCreationForm::beSigned(const Bureaucrat& signer)
{
    if (signer.getGrade() <= this->getSignGrade())
    {
        this->_signed = true;
        std::cout << MAGENTA << "Shrubbery Creation Form" << GREEN << " signed by " << CYAN << signer.getName() << RESET << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	std::ofstream outfile;

    outfile.open(this->_target + "_shrubbery");
    if (!outfile.is_open()) {
        std::cerr << "could not open file!" << std::endl;
    }
    outfile << "          .     .  .      +     .      .          .\n"
             "     .       .      .     #       .           .\n"
             "        .      .         ###            .      .      .\n"
             "      .      .   '#:. .:##'##:. .:#'  .      .\n"
             "          .      . '####'###'####'  .\n"
             "       .     '#:.    .:#'###'#:.    .:#'  .        .       .\n"
             "  .             '#########'#########'        .        .\n"
             "        .    '#:.  '####'###'####'  .:#'   .       .\n"
             "     .     .  '#######''##'##''#######'                  .\n"
             "                .'##'#####'#####'##'           .      .\n"
             "    .   '#:. ...  .:##'###'###'##:.  ... .:#'     .\n"
             "      .     '#######'##'#####'##'#######'      .     .\n"
             "    .    .     '#####''#######''#####'    .      .\n"
             "            .     '      000      ''    .     .\n"
             "       .         .   .   000     .        .       .\n"
             ".. .. ..................O000O........................ ...... ..." << std::endl;
    std::cout << GREEN << "Shrubbery created by " << CYAN << executor.getName() << RESET << std::endl;
}