#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat {
private:
	const std::string	_name;
	int 				_grade;

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &rhs);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat();

	std::string	getName() const;
	int 		getGrade() const;
	void        promote();
	void        demote();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& instance);

#endif
