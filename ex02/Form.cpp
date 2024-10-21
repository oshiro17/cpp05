#include "Form.hpp"

Form::Form(const std::string& name, const int grade_required_to_sign, const int grade_required_to_exec)
    : grade_required_to_sign_(grade_required_to_sign), grade_required_to_exec_(grade_required_to_exec), 
      name_(name), signed_(false)
{
    if (this->grade_required_to_sign_ < 1 || this->grade_required_to_exec_ < 1) {
        throw GradeTooHighException();
    }
    if (this->grade_required_to_sign_ > 150 || this->grade_required_to_exec_ > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& src) 
    : grade_required_to_sign_(src.getGradeRequiredToSign()), grade_required_to_exec_(src.getGradeRequiredToExec()), 
      name_(src.getName()), signed_(src.getSigned())
{
    if (this->grade_required_to_sign_ < 1 || this->grade_required_to_exec_ < 1) {
        throw Form::GradeTooHighException();
    }
    if (this->grade_required_to_sign_ > 150 || this->grade_required_to_exec_ > 150) {
        throw Form::GradeTooLowException();
    }
}

Form& Form::operator=(const Form& src)
{
    if (src.getGradeRequiredToExec() < 1 || src.getGradeRequiredToSign() < 1)
        throw GradeTooHighException();
    if (src.getGradeRequiredToExec() > 150 || src.getGradeRequiredToSign() > 150)
        throw GradeTooLowException();
    if (this != &src)
    {
        const_cast<std::string&>(this->name_) = src.name_;
        this->signed_ = src.signed_;
        const_cast<int&>(this->grade_required_to_exec_) = src.grade_required_to_exec_;
        const_cast<int&>(this->grade_required_to_sign_) = src.grade_required_to_sign_;
    }
    return (*this);
}

Form::~Form()
{
}

const char* Form::GradeTooHighException::what(void) const throw() {
    return ("Grade too high");
}

const char* Form::GradeTooLowException::what(void) const throw() {
    return ("Grade too low");
}

const std::string& Form::getName(void) const {
    return (this->name_);
}

bool Form::getSigned(void) const {
    return (this->signed_);
}

int Form::getGradeRequiredToSign(void) const {
    return (this->grade_required_to_sign_);
}

int Form::getGradeRequiredToExec(void) const {
    return (this->grade_required_to_exec_);
}

void Form::beSigned(const Bureaucrat& bc) {
    if (!this->signed_ && this->grade_required_to_sign_ < bc.getGrade())
        throw Form::GradeTooLowException();
    this->signed_ = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName()
       << ", signed: " << (form.getSigned() ? "yes" : "no")
       << ", grade required to sign: " << form.getGradeRequiredToSign()
       << ", grade required to execute: " << form.getGradeRequiredToExec();
    return os;
}
