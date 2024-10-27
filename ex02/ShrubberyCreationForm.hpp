#ifndef SHRUBBERYCRESTIONFORM_HPP
#define SHRUBBERYCRESTIONFORM_HPP
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm{
public:
    ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();
	void execute(Bureaucrat const & executor) const;
private:
    static const int grade_to_sign_=145;
    static const int grade_to_exec_=137;
    std::string target_;
};
#endif