/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:05 by awilliam          #+#    #+#             */
/*   Updated: 2023/07/24 12:16:17 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "colors.hpp"

class PresidentialPardonForm : public AForm {
    private:
        void executeForm(const Bureaucrat& executor) const;
        const std::string _target;

    public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& oldInstance);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& oldInstance);

    void beSigned(const Bureaucrat& signer);

    class GradeTooLowException : public std::exception {
        public:
            virtual const char * what() const throw();
    };
};

#endif