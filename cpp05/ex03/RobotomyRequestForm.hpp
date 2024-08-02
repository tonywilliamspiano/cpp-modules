/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:02:54 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/02 15:16:08 by awilliam         ###   ########.fr       */
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