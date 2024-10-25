#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    PresidentialPardonForm form("Trump");
    Bureaucrat b("bbb",2);

    form.beSigned(b);
    form.execute(b);
};