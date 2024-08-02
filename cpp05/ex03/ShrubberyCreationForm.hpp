/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:10 by awilliam          #+#    #+#             */
/*   Updated: 2023/07/24 12:16:23 by tony             ###   ########.fr       */
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