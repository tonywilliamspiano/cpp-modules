#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string   _name;
	bool                _isSigned;
	const int           _gradeToSign;
	const int           _gradeToExecute;

public:
	AForm(std::string name, int signGrade, int execGrade);
	~AForm();
	AForm(const AForm& oldInstance);
	AForm& operator=(const AForm& oldInstance);

	const std::string&	getName() const;
	bool        		getIsSigned() const;
	int         		getGradeToSign() const;
	int         		getGradeToExecute() const;
	void        		beSigned(const Bureaucrat& signer);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char * what() const throw();
	};
};

std::ostream& operator<<(std::ostream& stream, const AForm& instance);

#endif