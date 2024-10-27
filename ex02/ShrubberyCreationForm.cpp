
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
:AForm("ShrubberyCreationForm",grade_to_sign_,grade_to_exec_),target_(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target_(other.target_) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    if(this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
    return ;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
