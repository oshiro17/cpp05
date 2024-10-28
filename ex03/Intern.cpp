#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(Intern const & copy)
{
    *this = copy;
    return ;
}


Intern & Intern::operator =(Intern const & src)
{
    (void)src;
    return (*this);
}

namespace {
    AForm* makePresident(const std::string& target) {
        return new PresidentialPardonForm(target);
    }

    AForm* makeRobotomy(const std::string& target) {
        return new RobotomyRequestForm(target);
    }

    AForm* makeShrubbery(const std::string& target) {
        return new ShrubberyCreationForm(target);
    }
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    const int arraySize = 3;
    AForm* (*formCreators[])(const std::string&) = { makePresident, makeRobotomy, makeShrubbery };
    const std::string formNames[] = { "presidential pardon", "robotomy request", "shrubbery creation" };

    for (int i = 0; i < arraySize; i++) {
        if (name == formNames[i]) {
            std::cout << "Intern created " << formNames[i] << " form" << std::endl;
            return formCreators[i](target);
        }
    }
    std::cout << "Intern could not create " << name << " form" << std::endl;
    return nullptr;
}