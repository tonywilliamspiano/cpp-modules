/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:09 by awilliam          #+#    #+#             */
/*   Updated: 2023/07/24 12:21:47 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <fstream>
# include <cstdlib>
# include "colors.hpp"

class RobotomyRequestForm : public AForm {
    private:
        void executeForm(const Bureaucrat& executor) const;
        const std::string _target;

    public:
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& oldInstance);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& oldInstance);

    void beSigned(const Bureaucrat& signer);

    class GradeTooLowException : public std::exception {
        public:
            virtual const char * what() const throw();
    };
};

#endif