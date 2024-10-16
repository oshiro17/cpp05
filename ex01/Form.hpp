#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
    	class GradeTooHighException : public std::exception
	{
	public:
	virtual const char* what() const throw() /*override*/; 
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw() /*override*/; 
	};
    Form(const std::string& name, const int grade_required_to_sign, const int grade_required_to_exec);
    Form(const Form& src);
    Form&	operator=(const Form& rhs);
    ~Form(void);
	const std::string&	getName(void) const;
    bool    getSigned(void) const;
    int getGradeRequiredToSign(void)const;
    int getGradeRequiredToExec(void)const;
    void				beSigned(const Bureaucrat& bc);

private:
    const int grade_required_to_sign_;
    const int grade_required_to_exec_;
    const std::string   name_;
    bool    signed_;


};
std::ostream&	operator<<(std::ostream& stream, const Form& form);
#endif