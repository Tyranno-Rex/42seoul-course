#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(void): Form("RobotomyRequestForm", 72, 45), _name("default_name"){
    // std::cout << this->_name << "\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string name): Form("RobotomyRequestForm", 72, 45), _name(name){
    // std::cout << this->_name << "\n";
}

RobotomyRequestForm::~RobotomyRequestForm(void){
    // std::cout << this->_name << " is deleted\n";
}

void RobotomyRequestForm::execute(Bureaucrat const &executer){
    if (this->getFormSign() == false){
        std::cout << "this form isn't signed\n";
        std::cout << "go sign first\n";
        return ;
    }

    if (executer.getGrade() < 45){
        std::cout << "you can assign the this form\n";
    }
    else{
        std::cout << "you can't assign the this form\n";
        return ;
    }
    std::cout << "Beeeeeeeep!" << "\n";
    std::cout << "Beeeeeeeep!" << "\n";
    std::cout << "Beeeeeeeep!" << "\n";
    std::cout << "Beeeeeeeep!" << "\n";
    std::cout << "Beeeeeeeep!" << "\n";
    std::cout << "Beeeeeeeep!" << "\n";
    std::cout << "Beeeeeeeep!" << "\n";
}

std::string RobotomyRequestForm::getNameFile(void) const{
    return (this->_name);
}

std::ostream &operator<<(std::ostream &oper, RobotomyRequestForm *Robo){
    oper << "Form " << Robo->getNameFile() << "\nSign or Not: " << Robo->getFormSign()
    << "\nsign level: " << Robo->getFormLevel() << "\nExec level: " << Robo->getExecLevel() << "\n";
    return oper;
}