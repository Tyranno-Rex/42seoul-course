#include "Bureaucrat.hpp"

void Bureaucrat::setGrade(int grade){
    if (grade > 150){
        this->_grade = -1;
        throw Bureaucrat::GradeTooLowException();
    }
    else if (grade < 1){
        this->_grade = -1;
        throw Bureaucrat::GradeTooHighException();
    }
    else
        this->_grade = grade;
}



// <bureaucrat> signed <form>
// Otherwise, it will print something like:
// <bureaucrat> couldn’t sign <form> because <reason>
void Bureaucrat::signForm(Form &form){

    if (form->_sign == true){
        std::cout << this. << " signed "<< this->getFormName() << "\n";
    }
    else{
        std::cout << agent.getName() << " couldn't signed "
        << this->getFormName() << " because this form level(" 
        << this->getSignLevel() <<  ") is higher than agent grade(" 
        << agent.getGrade() << ")\n";
    }
}
Bureaucrat::Bureaucrat(void): _name("EunSeong"), _grade(1){
    // std::cout << "Bureaucrat is Created\n";
    // std::cout << "Bureaucrat name is " << this->_name << " and Grade is " << this->_grade << "\n";
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(1){
    // std::cout << "Bureaucrat is Created\n";
    // std::cout << "Bureaucrat name is " << this->_name << " and Grade is " << this->_grade << "\n";
}

Bureaucrat::Bureaucrat(int grade): _name("EunSeong"){
    try{
        this->setGrade(grade);
    }
    catch(...)
    {
        std::cerr << "ERROR\n";
        std::cerr << this->getName() <<  "'s grade " << grade <<  " is in Wrong Range of Grade(Invalid values are stored as -1.)\n";
    }
    // std::cout << "Bureaucrat is Created\n";
    // std::cout << "Bureaucrat name is " << this->_name << " and Grade is " << this->_grade << "\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name){
    try{
        this->setGrade(grade);
    }
    catch(...)
    {
        std::cerr << "ERROR\n";
        std::cerr << this->getName() <<  "'s grade " << grade <<  " is in Wrong Range of Grade(Invalid values are stored as -1.)\n";
    }
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

void Bureaucrat::increment(void){
    this->_grade += 1;
}

void Bureaucrat::decrement(void){
    this->_grade -= 1;
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
    oper << Bur->getName() << ", bureaucrat grade " << Bur->getGrade() << "\n";
	return (oper);
}