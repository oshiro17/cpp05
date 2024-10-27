
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
:AForm("RobotomyRequestForm",grade_to_sign_,grade_to_exec_),target_(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target_(other.target_) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    if(this != &other)
        AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void){
    return ;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
