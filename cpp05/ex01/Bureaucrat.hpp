#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class Form;

class Bureaucrat {
private:
	const std::string   _name;
	int                 _grade;

public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& oldInstance);
	Bureaucrat& operator=(const Bureaucrat& oldInstance);

	std::string getName() const;
	int         getGrade() const;
	void        promote();
	void        demote();
	void        signForm(Form & toSign);

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