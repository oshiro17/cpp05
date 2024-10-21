#include "AForm.hpp"

AForm::AForm(const std::string& name, const int grade_required_to_sign, const int grade_required_to_exec)
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

AForm::AForm(const AForm& src) 
    : grade_required_to_sign_(src.getGradeRequiredToSign()), grade_required_to_exec_(src.getGradeRequiredToExec()), 
      name_(src.getName()), signed_(src.getSigned())
{
    if (this->grade_required_to_sign_ < 1 || this->grade_required_to_exec_ < 1) {
        throw AForm::GradeTooHighException();
    }
    if (this->grade_required_to_sign_ > 150 || this->grade_required_to_exec_ > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm& AForm::operator=(const AForm& src)
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

AForm::~AForm()
{
}

const char* AForm::GradeTooHighException::what(void) const throw() {
    return ("Grade too high");
}

const char* AForm::GradeTooLowException::what(void) const throw() {
    return ("Grade too low");
}

const std::string& AForm::getName(void) const {
    return (this->name_);
}

bool AForm::getSigned(void) const {
    return (this->signed_);
}

int AForm::getGradeRequiredToSign(void) const {
    return (this->grade_required_to_sign_);
}

int AForm::getGradeRequiredToExec(void) const {
    return (this->grade_required_to_exec_);
}

void AForm::beSigned(const Bureaucrat& bc) {
    if (!this->signed_ && this->grade_required_to_sign_ < bc.getGrade())
        throw AForm::GradeTooLowException();
    this->signed_ = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& aform) {
    os << "AForm: " << aform.getName()
       << ", signed: " << (aform.getSigned() ? "yes" : "no")
       << ", grade required to sign: " << aform.getGradeRequiredToSign()
       << ", grade required to execute: " << aform.getGradeRequiredToExec();
    return os;
}
