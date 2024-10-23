#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

#include "AForm.hpp"

class PresidentialPardonForm: public AForm{
public:
    PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();
	void executeInDerived() const;
private:
    static const int grade_to_sign_=25;
    static const int grade_to_exec_=5;
    std::string target_;
}