
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Form.hpp"
class Form;
class Bureaucrat
{
public:
	class GradeTooHighException : public std::exception
	{
	public:
	virtual const char* what() const throw() /*override*/; 
// 	const char* exception::what() const noexcept
// {
//   return "std::exception";
// }
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw() /*override*/; 
	};

	Bureaucrat(const std::string& name, int grade = 100);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat(void);

	Bureaucrat& operator=(const Bureaucrat& rhs);

	const std::string& getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(Form& form);

private:
	const std::string name_;
	int grade_;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bc);

#endif