
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>  // rand, srand
#include <ctime>   
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
:AForm("RobotomyRequestForm",grade_to_sign_,grade_to_exec_),target_(target){
     static bool seeded = false;  
    if (!seeded) {
        std::srand(std::time(0)); 
        seeded = true;
    }
}

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
        {
            std::cout << target_ << "!!!Drilling noises!!!!!! Bzzz Prrrrr Brr" << std::endl;


            if (std::rand() % 2==0)
                 std::cout << target_ << " has been robotomized successfully!" << std::endl;
            else
                std::cout << "The robotomy failed for " << target_ << "!" << std::endl;

        }
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    return ;
}
