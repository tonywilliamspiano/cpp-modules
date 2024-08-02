/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:16:06 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/02 18:57:00 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"
# include "colors.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class AForm;

class Bureaucrat {
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& rhs);
        Bureaucrat& operator=(const Bureaucrat& rhs);

    std::string getName() const;
    int         getGrade() const;
    void        promote();
    void        demote();
    void        signForm(AForm & toSign);
    void        executeForm(AForm const & toExecute);

    class GradeTooHighException : public std::exception {
        public:
            virtual const char * what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
        public:
            virtual const char * what() const throw();
    };
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& instance);

#endif