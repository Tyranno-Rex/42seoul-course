#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("EunSeong"), _grade(1){
    // std::cout << "Bureaucrat is Created\n";
    // std::cout << "Bureaucrat name is " << this->_name << " and Grade is " << this->_grade << "\n";
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(1){
    // std::cout << "Bureaucrat is Created\n";
    // std::cout << "Bureaucrat name is " << this->_name << " and Grade is " << this->_grade << "\n";
}

Bureaucrat::Bureaucrat(int grade): _name("EunSeong"), _grade(grade){
    // std::cout << "Bureaucrat is Created\n";
    // std::cout << "Bureaucrat name is " << this->_name << " and Grade is " << this->_grade << "\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade){
    // std::cout << "Bureaucrat is Created\n";
    // std::cout << "Bureaucrat name is " << this->_name << " and Grade is " << this->_grade << "\n";
}

Bureaucrat::~Bureaucrat(void){
    // std::cout << "Bureaucrat is destoryed\n";
}

std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref){
    std::cout << "<< overloading is processed" << "\n";
    this->_grade = ref.getGrade();
    return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too High";
}
const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too Low";
}

std::ostream &operator<<(std::ostream &oper, Bureaucrat *Bur)
{
    oper << "Bureaucrat " << Bur->getName() << " grade: " << Bur->getGrade() << "\n";
	return (oper);
}