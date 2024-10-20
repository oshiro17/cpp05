#include "Form.hpp"

Form::Form(const std::string& name, \
    const int grade_required_to_sign, const int grade_required_to_exec) \
    : grade_required_to_sign_(grade_required_to_sign), \
      grade_required_to_exec_(grade_required_to_exec), \
      name_(name), signed_(false)
{
    std::cout << "Form  Default Constructor called for " << this->name_ << std::endl;

    if (this->grade_required_to_sign_ < 1 || this->grade_required_to_exec_ < 1) {
        throw GradeTooHighException();
    }
    if (this->grade_required_to_sign_ > 150 || this->grade_required_to_exec_ > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& src) : grade_required_to_sign_(src.getGradeRequiredToSign()), \
      grade_required_to_exec_(src.getGradeRequiredToExec()), \
      name_(src.getName()), \
      signed_(src.getSigned())
{
    std::cout << "Form  Copy Constructor called for " << this->name_ << std::endl;

    if (this->grade_required_to_sign_ < 1 || this->grade_required_to_exec_ < 1) {
        throw Form::GradeTooHighException();
    }
    if (this->grade_required_to_sign_ > 150 || this->grade_required_to_exec_ > 150) {
        throw Form::GradeTooLowException();
    }

}

Form &Form::operator=(const Form& src)
{
    std::cout << "Form Assignation operator called" << std::endl;
    if (src.getGradeRequiredToExec()<1 || src.getGradeRequiredToSign()<1)
        throw GradeTooHighException();
    if (src.getGradeRequiredToExec()>150 || src.getGradeRequiredToSign()>150)
        throw GradeTooLowException();
    if (this != &src)
    {
        const_cast<std::string&>(this->name_) = src.name_;
        this->signed_ = src.signed_;
        const_cast<int&>(this->grade_required_to_exec_) = src.grade_required_to_exec_;
        const_cast<int&>(this->grade_required_to_sign_) = src.grade_required_to_sign_;
    }
    return(*this);

}

Form::~Form()
{
	std::cout << "Form Destructor for " << this->getName() << " called" << std::endl;
}

const char*	Form::GradeTooHighException::what(void) const throw() {
    return ("Grade too high");
}
const char*	Form::GradeTooLowException::what(void) const throw() {
    return ("Grade too low");
}

const std::string&	Form::getName(void) const{
    return(this->name_);
}
bool    Form::getSigned(void) const{
    return(this->signed_);
}
int Form::getGradeRequiredToSign(void)const
{
    return(this->grade_required_to_sign_);
}
int Form::getGradeRequiredToExec(void)const{
    return(this->grade_required_to_exec_);
}
void	Form::beSigned(const Bureaucrat& bc) {
	std::cout << this \
		<< "<Form> beSigned() called (" \
		<< this->name_ << std::endl;
	if (this->signed_== false &&this->grade_required_to_sign_< bc.getGrade())
		throw Form::GradeTooLowException();
	this->signed_ = true;
}