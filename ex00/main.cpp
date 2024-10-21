#include "Bureaucrat.hpp"

bool case_regular() {
    try {
        Bureaucrat b("Alice", 50);
        return true;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return false;
    }
}

bool case_high() {
    try {
        Bureaucrat b("Bob", 0);
        return true;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return false;
    }
}

bool case_low() {
    try {
        Bureaucrat b("Charlie", 200);
        return true;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return false;
    }
}

bool case_increment() {
    try {
        Bureaucrat b("Dave", 150);  
        b.incrementGrade();
        return true;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return false;
    }
}

bool case_increment_high() {
    try {
        Bureaucrat b("Eve", 2);  
        b.incrementGrade();
        b.incrementGrade();
        return true;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return false;
    }
}

bool case_decrement() {
    try {
        Bureaucrat b("Frank", 50);  
        b.decrementGrade();
        return true;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return false;
    }
}

bool case_decrement_low() {
    try {
        Bureaucrat b("Grace", 150);  
        b.decrementGrade();
        b.decrementGrade();
        return true;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return false;
    }
}

int main() {
    Bureaucrat b("b",35);
    std::cout<<b<<std::endl;
    if (!case_regular())
        std::cout << "No exception occurred" << std::endl;
    if (!case_high())
        std::cout << "No exception occurred" << std::endl;
    if (!case_low())
        std::cout << "No exception occurred" << std::endl;
    if (!case_increment())
        std::cout << "No exception occurred" << std::endl;
    if (!case_increment_high())
        std::cout << "No exception occurred" << std::endl;
    if (!case_decrement())
        std::cout << "No exception occurred" << std::endl;
    if (!case_decrement_low())
        std::cout << "No exception occurred" << std::endl;
    return 0;
}