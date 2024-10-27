#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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

  	class FormSignedException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class FormNotSignedException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
    AForm(const std::string& name, const int grade_required_to_sign, const int grade_required_to_exec);
    AForm(const AForm& src);
    AForm&	operator=(const AForm& rhs);
    virtual ~AForm(void);
	const std::string&	getName(void) const;
    bool    getSigned(void) const;
    int getGradeRequiredToSign(void)const;
    int getGradeRequiredToExec(void)const;
    void				beSigned(const Bureaucrat& bc);
    virtual void execute(const Bureaucrat& executor) const = 0;


private:
    const int grade_required_to_sign_;
    const int grade_required_to_exec_;
    const std::string   name_;
    bool    signed_;


};
std::ostream&	operator<<(std::ostream& stream, const AForm& aform);
#endif