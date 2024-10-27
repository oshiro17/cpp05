#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#include "AForm.hpp"

class RobotomyRequestForm: public AForm{
public:
    RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();
	void execute(Bureaucrat const & executor) const;
private:
    static const int grade_to_sign_=72;
    static const int grade_to_exec_=45;
    std::string target_;
};
#endif