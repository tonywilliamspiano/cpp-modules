/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:16:12 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/02 15:46:18 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "colors.hpp"

class Bureaucrat;

class AForm {
    protected:
        const std::string   _name;
        bool                _signed;
        const int           _gradeRequiredToSign;
        const int           _gradeRequiredToExecute;


    public:
        AForm(std::string name, int signGrade, int execGrade);
        virtual ~AForm();
        AForm(const AForm& oldInstance);
        AForm& operator=(const AForm& oldInstance);

	    std::string 	getName() const;
    	bool        	getSignedStatus() const;
    	int         	getSignGrade() const;
    	int         	getExecuteGrade() const;
    	virtual void	beSigned(const Bureaucrat& signer) = 0;
		virtual void	execute(const Bureaucrat& executor) const = 0;
		void 			checkGradeAndSignedStatus(const Bureaucrat& executor) const;

    class GradeTooLowException : public std::exception {
        public:
            virtual const char * what() const throw();
    };

	class GradeTooHighException : public std::exception {
	public:
		virtual const char * what() const throw();
	};

    class NotSignedException : public std::exception {
        public:
            virtual const char * what() const throw();
    };

};

std::ostream& operator<<(std::ostream& stream, const AForm& instance);

#endif