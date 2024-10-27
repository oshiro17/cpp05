#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) \
: name_(name), grade_(grade) {
	if (this->grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
}
Bureaucrat::~Bureaucrat(){}

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
	this->grade_++;
    if (this->grade_ > 150)
        throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::incrementGrade(void) {
    this->grade_--;
    if (this->grade_ < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name_(src.getName()), grade_(src.getGrade()){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (src.grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (src.grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this != &src) {
		this->grade_ = src.grade_;
    	const_cast<std::string&>(this->name_) = src.name_;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bureaucrat) {
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (stream);
}

void	Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
	}
	catch (std::exception & e) {
		std::cout << this->name_ << " couldn't sign " << form.getName() \
			<< " because " << e.what() << "." << std::endl;
		return;
	}
	std::cout << this->name_ << " signed " << form.getName() << std::endl;
	return ;
}

void Bureaucrat::executeForm(AForm const & form)
{
	try{
		form.execute(*this);
	}
	catch(std::exception &e){
		std::cout << this->name_ << " couldn't execute " << form.getName() 
		<< " because " << e.what() << std::endl;
	}
}
