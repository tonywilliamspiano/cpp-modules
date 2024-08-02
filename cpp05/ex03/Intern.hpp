/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:49:47 by tony              #+#    #+#             */
/*   Updated: 2023/07/24 18:20:48 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern {
    private:
        AForm * _make_rrf(std::string target);
        AForm * _make_scf(std::string target);
        AForm * _make_ppf(std::string target);

    public:
        Intern();
        ~Intern();
        Intern(const Intern& oldInstance);
        Intern& operator=(const Intern& oldInstance);

        AForm * makeForm(std::string type, std::string target);

    class formTypeNotFoundException : public std::exception {
        public:
            virtual const char * what() const throw();
    };
};

#endif