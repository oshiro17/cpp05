
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
:AForm("PresidentialPardonForm",grade_to_sign_,grade_to_exec_),target_(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target_(other.target_) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
    if(this != &other)
        AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void){
    return ;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (getSigned() == false)
            throw FormNotSignedException();
        else if (executor.getGrade() > getGradeRequiredToExec())
            throw GradeTooLowException();
        else
            std::cout << target_ << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    return ;
}
