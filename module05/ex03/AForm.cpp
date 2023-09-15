#include "AForm.hpp"

AForm::AForm(void): _name("default_name"), _sign_lvl(150), _exec_lvl(150), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_sign_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

AForm::AForm(const AForm &src): _name(src.getFormName()), _sign_lvl(src.getSignLevel()), _exec_lvl(src.getExecLevel()), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_sign_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

AForm::AForm(std::string name): _name(name), _sign_lvl(150), _exec_lvl(150), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_sign_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

AForm::AForm(std::string name, int access_lvl, int exec_lvl): _name(name), _sign_lvl(access_lvl), _exec_lvl(exec_lvl), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_sign_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}


AForm::~AForm(void){
    // std::cout << "AForm is deleted\n";
}

std::string AForm::getFormName(void) const{
    return (this->_name);
}

int AForm::getSignLevel(void) const {
    return (this->_sign_lvl);
}

int AForm::getExecLevel(void) const {
    return (this->_exec_lvl);
}

bool AForm::getFormSign(void) const{
    return (this->_sign);
}

void AForm::beSigned(Bureaucrat agent){
    std::cout << "!CHECK!\n[";
    try
    {
        if (this->_sign_lvl >= agent.getGrade()){
            std::cout << "you can access this "<< this->getFormName() << " AForm]\n";
            this->_sign = true;
        }
        else{
            std::cout << "you can't access this "<< this->getFormName() << " AForm]\n";
            throw AForm::GradeTooLowException();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

// <bureaucrat> signed <Aform>
// Otherwise, it will print something like:
// <bureaucrat> couldn’t sign <Aform> because <reason>
void AForm::signForm(Bureaucrat agent){
    if (this->_sign == true){
        std::cout << agent.getName() << " signed "<< this->getFormName() << "\n";
        if (this->getExecLevel() <  agent.getGrade()){
            std::cout << agent.getName() << " couldn't signed "
            << this->getFormName() << " because this Aform level(" 
            << this->getSignLevel() <<  ") is higher than agent grade(" 
            << agent.getGrade() << ")\n";
        }
    }
    else{
        std::cout << agent.getName() << " isn't signed "<< this->getFormName() << "\n";
    }
}

std::ostream &operator<<(std::ostream &oper, AForm *Aform)
{
    oper 
    << "AForm Name:          " << Aform->getFormName() << "\n"
    << "AForm Sign Level:    " << Aform->getSignLevel() << "\n"
    << "AForm Exec Level:    " << Aform->getExecLevel() << "\n";
	return (oper);
}

const char* AForm::GradeTooHighException::what() const throw(){
    return "Grade is too High";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "Grade is too Low";
}