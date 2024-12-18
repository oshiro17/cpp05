#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    ShrubberyCreationForm form("Trump");
    Bureaucrat b("bbb",2);

    try{
    form.beSigned(b);
    form.execute(b);
    form.execute(b);
    form.execute(b);
    form.execute(b);
    form.execute(b);
    }
    catch(const AForm::GradeTooLowException& e)
    {
     std::cerr << "Failed to sign the form: " << e.what() << std::endl;
    }
};