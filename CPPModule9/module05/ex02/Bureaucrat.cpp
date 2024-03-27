#include "Bureaucrat.hpp"

void Bureaucrat::setGrade(int grade){
    if (grade > 150){
        this->_grade = 10000;
        throw Bureaucrat::GradeTooLowException();
    }
    else if (grade < 1){
        this->_grade = 10000;
        throw Bureaucrat::GradeTooHighException();
    }
    else
        this->_grade = grade;
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
        std::cerr << this->getName() <<  "'s grade " << grade <<  " is in Wrong Range of Grade(Invalid values are stored as 10000.)\n";
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
        std::cerr << this->getName() <<  "'s grade " << grade <<  " is in Wrong Range of Grade(Invalid values are stored as 10000.)\n";
    }
    // std::cout << "Bureaucrat is Created\n";
    // std::cout << "Bureaucrat name is " << this->_name << " and Grade is " << this->_grade << "\n";
}

Bureaucrat::~Bureaucrat(void){
    // std::cout << "Bureaucrat is destoryed\n";
}


void Bureaucrat::signForm(AForm &form) const{
    if (this->getGrade() < form.getSignLevel()){
        std::cout << this->getName() << " signed "<< form.getFormName() << "\n";
        form.beSigned(*this);
    }
    else{
        std::cout << this->getName() << " couldn't signed "
        << form.getFormName() << " because this form level(" 
        << form.getSignLevel() <<  ") is higher than agent grade(" 
        << this->getGrade() << ")\n";
    }
}


void	Bureaucrat::executeForm(AForm &form) const{
    if (this->getGrade() < form.getExecLevel()){
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getFormName() << "\n";
	}
    else{
        std::cout << this->getName() << " couldn't execute "
        << form.getFormName() << " because this form level(" 
        << form.getExecLevel() <<  ") is higher than agent grade(" 
        << this->getGrade() << ")\n";
    }
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