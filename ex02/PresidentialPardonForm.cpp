#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
:AForm("PresidentialPardonForm",grade_to_sign_,grade_to_exec_),target_(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {
}

PresidentialPardonForm::PresidentialPardonForm&operator=(const PresidentialPardonForm &other){
    if(this != &other)
        AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void){
    return ;
}

void PresidentialPardonForm::excute(Bureaucrat const & executor) const
{
    try
    {

    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
        return;
    }
}