#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) \
: name_(name), grade_(grade) {
	std::cout << "Bureaucrat Default Constructor called for " << this->name_ << \
	" with grade of " << this->grade_<< std::endl;
	if (this->grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor for " << this->getName() << " called" << std::endl;
}
const char*	Bureaucrat::GradeTooHighException::what(void) const throw() {
    return ("Grade too high");
}
const char*	Bureaucrat::GradeTooLowException::what(void) const throw() {
    return ("Grade too low");
}
const std::string&	Bureaucrat::getName(void)const
{
	return (this->name_);
}
int	Bureaucrat::getGrade(void)const
{
	return (this->grade_);
}
void	Bureaucrat::decrementGrade(void) {
    std::cout << "<Bureaucrat> decrementGrade() called for " << this->name_ << std::endl;
	this->grade_++;
    if (this->grade_ > 150)
        throw Bureaucrat::GradeTooLowException();


}
void	Bureaucrat::incrementGrade(void) {

    std::cout << "<Bureaucrat> incrementGrade() called for " << this->name_ << std::endl;
    this->grade_--;
    if (this->grade_ < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name_(src.getName()), grade_(src.getGrade())
{
	std::cout << "Bureaucrat Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (src.grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (src.grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this != &src) {
        // constメンバでない部分だけ代入
		this->grade_ = src.grade_;
    	const_cast<std::string&>(this->name_) = src.name_;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bureaucrat) {
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (stream);
}

int	Bureaucrat::signForm(Form& form) {
	std::cout << this << "<Bureaucrat> signForm() called " \
		<< this->name_ << std::endl;
	try {
		form.beSigned(*this);
	}
	catch (std::exception & e) {
		std::cout << this->name_ << " couldn't sign " << form.getName() \
			<< " because " << e.what() << "." << std::endl;
		return (0);
	}
	std::cout << this->name_ << " signed " << form.getName() << std::endl;
	return (1);
}