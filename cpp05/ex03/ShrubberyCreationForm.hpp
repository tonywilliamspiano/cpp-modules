/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:02:54 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/02 15:16:17 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <fstream>
# include "colors.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        void executeForm(const Bureaucrat& executor) const;
        const std::string _target;

    public:
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& oldInstance);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& oldInstance);

    void beSigned(const Bureaucrat& signer);

    class GradeTooLowException : public std::exception {
        public:
            virtual const char * what() const throw();
    };
};

#endif