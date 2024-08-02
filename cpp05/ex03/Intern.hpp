/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:20:48 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/02 19:04:12 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

# define FORM_NOT_FOUND 0
# define ROBOTOMY_REQUEST 1
# define SHRUBBERY_CREATION 2
# define PRESIDENTIAL_PARDON 3

class AForm;

class Intern {
    private:
        AForm * _make_rrf(std::string target);
        AForm * _make_scf(std::string target);
        AForm * _make_ppf(std::string target);

    public:
        Intern();
        ~Intern();
        Intern(const Intern& rhs);
        Intern& operator=(const Intern& rhs);

        AForm * makeForm(std::string type, std::string target);

    class formTypeNotFoundException : public std::exception {
        public:
            virtual const char * what() const throw();
    };
};

#endif