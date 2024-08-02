/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:08:57 by awilliam          #+#    #+#             */
/*   Updated: 2023/07/24 12:28:46 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
}


Bureaucrat::~Bureaucrat()
{
    // std::out << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& oldInstance) : _name(oldInstance.getName())
{
    this->_grade = oldInstance.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& oldInstance)
{
    if (this != &oldInstance)
    {
        this->_grade = oldInstance.getGrade();
    }
    return (*this);
}

void    Bureaucrat::promote()
{
    std::cout << this->getName() << " is receiving a promotion :)" << std::endl;
    if (this->_grade > MAX_GRADE)
        this->_grade--;
    else
        throw Bureaucrat::GradeTooHighException();
}

void    Bureaucrat::demote()
{
    std::cout << this->getName() << " is receiving a demotion :(" << std::endl;
    if (this->_grade < MIN_GRADE)
        this->_grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& instance)
{
    stream << instance.getName() << " is a bureacrat with grade: " << instance.getGrade();
    return (stream);
}

void    Bureaucrat::signForm(AForm & toSign)
{
    toSign.beSigned(*this);    
}

void    Bureaucrat::executeForm(AForm const & toExecute)
{
        toExecute.checkGrade(*this);
		toExecute.execute(*this);
        std::cout << CYAN << this->getName() << GREEN << " successfully executed " << MAGENTA << toExecute.getName() << RESET << std::endl;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}
