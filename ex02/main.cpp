#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form form("form",75,150);

    std::cout<<form<<std::endl;
  try {
        Bureaucrat dave("Dave", 30);
        Form taxForm("Tax Form", 25, 50);
        std::cout << taxForm << std::endl;

        dave.signForm(taxForm); 
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat eve("Eve", 10);
        Form contract("Contract", 20, 10);
        std::cout << contract << std::endl;

        eve.signForm(contract);  
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

}