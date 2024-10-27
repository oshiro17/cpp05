#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    PresidentialPardonForm form("Trump");
    Bureaucrat b("bbb",30);

    try{
    form.beSigned(b);
    form.execute(b);
    }
    catch(const AForm::GradeTooLowException& e)
    {
     std::cerr << "Failed to sign the form: " << e.what() << std::endl;
    }
};