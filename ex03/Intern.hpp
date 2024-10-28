#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public :
    Intern(void);
    Intern(Intern const & copy);
    ~Intern(void);
    Intern & operator =(Intern const & src);
    AForm* makeForm(const std::string &name, const std::string &target);
};
#endif